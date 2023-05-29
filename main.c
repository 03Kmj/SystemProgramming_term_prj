#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <gtk/gtk.h>
#include <gio/gio.h>

#define MAX_FILENAMES 100

char *filenames[MAX_FILENAMES];
int num_files = 0;
int file_cnt = 0;
int main_check = 1;
int num_sub_files= 0;

// Drag and Drop
int drag_and_drop(int, char *[]);
void save_filenames_to_file();
void start_button_clicked(GtkWidget *, gpointer);
void drag_data_received(GtkWidget *, GdkDragContext *, int, int, GtkSelectionData *, guint, guint, gpointer);

// print progress bar
void progress_bar();

// call ls_c and check if there is enough C files
void ls_grep_c();

void intro();

// main
int main(int argc, char *argv[]) {
    char main_dir[100];
    char sub_dir[100];
    
    intro();

    printf("===Here is a list of files you can use===\n");
    ls_grep_c();

    drag_and_drop(argc, argv);

    FILE *fp = fopen("dropped_file.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file: dropped_file.txt\n");
        exit(1);
    }

    FILE *fp_result = fopen("similarity_result.txt", "w");
    if (fp_result == NULL) {
        printf("Failed to open file: similarity_result.txt\n");
        exit(1);
    }

    main_check = 1;
    for (int i = 0; i < num_files; i++) {
        char buf[100];
        fscanf(fp, "%s", buf);

        FILE *buf_fp = fopen(buf, "r");
        if (buf_fp == NULL) {
            printf("\n(%d/%d) ", file_cnt, num_sub_files);
            printf("\033[1;31mError: ");
            printf("\033[0m");
            printf("%s is not in the directory.\n", buf);
            exit(1);
        }
        fclose(buf_fp);

        char *extension = strrchr(buf, '.');
        if (strcmp(extension, ".c") != 0) {
            printf("\n(%d/%d) ", file_cnt, num_sub_files);
            printf("\033[1;31mError: ");
            printf("\033[0m");
            printf("%s is not a C file.\n", buf);
            exit(1);
        }

        if (main_check) {
            strcpy(main_dir, buf);
            main_check = 0;
        }
        else {
            strcpy(sub_dir, buf);

            char command[200];
            sprintf(command, "python3 ./similarity.py %s %s", main_dir, sub_dir);

            FILE *fp = popen(command, "r");
            if (fp == NULL) {
                printf("Error: cannot open file\n");
                return 1;
            }

            double similarity;
            fscanf(fp, "%lf", &similarity);
            pclose(fp);

            printf("\n");
            progress_bar(sub_dir);
            fprintf(fp_result, "The similarity between %s and %s is %.2lf%%\n", main_dir, sub_dir, similarity);
            sleep(1);
        }
        file_cnt++;
    }
    fclose(fp);
    fclose(fp_result);

    printf("\n\n-------------------------RESULT-------------------------\n");
    fp_result = fopen("similarity_result.txt", "r");
    if (fp_result == NULL) {
        printf("Failed to open file: similarity_result.txt\n");
        exit(1);
    }
    for (int i = 0; i < num_sub_files; i++) {
        char buf[100];
        fgets(buf, sizeof(buf), fp_result);
        printf("%s", buf);
    }

    return 0;
}

int drag_and_drop(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *main_box;
    GtkWidget *drop_label;
    GtkWidget *start_button;
    GtkTargetEntry targets[] = {
        { "text/uri-list", 0, 0 }
    };

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_size_request(window, 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
    gtk_container_add(GTK_CONTAINER(window), main_box);

    drop_label = gtk_label_new("Drop C File here!");
    gtk_box_pack_start(GTK_BOX(main_box), drop_label, TRUE, TRUE, 0);

    start_button = gtk_button_new_with_label("Start Similarity Check!");
    g_signal_connect(start_button, "clicked", G_CALLBACK(start_button_clicked), NULL);
    gtk_box_pack_start(GTK_BOX(main_box), start_button, TRUE, TRUE, 0);

    gtk_drag_dest_set(drop_label, GTK_DEST_DEFAULT_ALL, targets, G_N_ELEMENTS(targets), GDK_ACTION_COPY);
    g_signal_connect(drop_label, "drag-data-received", G_CALLBACK(drag_data_received), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    save_filenames_to_file();

    for (int i = 0; i < num_files; i++) {
        g_free(filenames[i]);
    }
}

void save_filenames_to_file() {
    FILE *fp = fopen("dropped_file.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file for writing.\n");
        exit(1);
    }
    for (int i = 0; i < num_files; i++) {
        fprintf(fp, "%s\n", filenames[i]);
    }
    fclose(fp);
}

void start_button_clicked(GtkWidget *widget, gpointer user_data) {
    gtk_main_quit();
}

void drag_data_received(GtkWidget *widget, GdkDragContext *context,
                        int x, int y, GtkSelectionData *data,
                        guint info, guint time, gpointer user_data)
{
    char **uris = gtk_selection_data_get_uris(data);
    if (uris) {
        char **uri;
        for (uri = uris; *uri; uri++) {
            GFile *file = g_file_new_for_uri(*uri);
            char *filename = g_file_get_basename(file);
            filenames[num_files] = g_strdup(filename);
            g_object_unref(file);

            if (main_check) {
                g_print("Main file: %s\n", filename);
                main_check = 0;
            }
            else {
                g_print("Sub file (%d): %s\n", ++num_sub_files, filename);
            }
            num_files++;
        }
        g_strfreev(uris);
    }
    gtk_drag_finish(context, TRUE, FALSE, time);
}

void progress_bar(char *filename) {
    const char bar = '=';
    const char blank = ' ';
    const int LEN = 50;
    const int MAX = 100;
    const int SPEED = 10;
    int count = 0;
    int i;
    float tick = (float) MAX / LEN;
    int barCount;
    float percent;
    
    while (count <= MAX) {
        printf("\r(%d/%d) %s [", file_cnt, num_sub_files, filename);
        percent = (float) count / MAX * 100;
        barCount = (int) (percent / tick);
        for (i = 0; i < LEN; i++) {
            if (i < barCount)
                printf("%c", bar);
            else
                printf("%c", blank);
        }
        printf("] %.2f%%", percent);
        fflush(stdout);
        count++;
        usleep(SPEED * 1000);
    }
}

void ls_grep_c() {
    FILE *pipe = popen("./ls_c", "r");
    if (pipe == NULL) {
        perror("popen");
        exit(1);
    }

    char buffer[1024];
    int c_check = 0;
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        printf("%s", buffer);
        c_check++;
    }

    pclose(pipe);

    if (c_check < 2) {
        printf("There is no enough C files.\n");
        exit(1);
    }
}

void intro() {
    printf("\n\n");
    printf("*Our Program: Similarity check\n");
    printf("*Purpose: This program checks the similarity between c codes.\n");
    printf("*Writer: mjkang, shpark, hjwi\n");
    sleep(3);
    printf("\n\n\n");

    printf("\033[1;31m     _           _ _            _ _                _               _      \n");  
    printf("\033[1;31m    (_)         (_) |          (_) |              | |             | |     \n");  
    printf("\033[1;33m ___ _ _ __ ___  _| | __ _ _ __ _| |_ _   _    ___| |__   ___  ___| | __  \n");  
    printf("\033[1;32m/ __| | '_ ` _ \\| | |/ _` | '__| | __| | | |  / __| '_ \\ / _ \\/ __| |/ /  \n");  
    printf("\033[1;36m\\__ \\ | | | | | | | | (_| | |  | | |_| |_| | | (__| | | |  __/ (__|   <   \n");  
    printf("\033[1;34m|___/_|_| |_| |_|_|_|\\__,_|_|  |_|\\__|\\__, |  \\___|_| |_|\\___|\\___|_|\\_\\  \n");  
    printf("\033[1;35m                                       __/ |                               \n");  
    printf("\033[1;35m                                      |___/                                \n");  
    printf("\033[0m"); 
    sleep(3);
    printf("\n\n\n");
}
