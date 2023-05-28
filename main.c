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

// Drag and Drop
int drag_and_drop(int, char *[]);
void save_filenames_to_file();
void start_button_clicked(GtkWidget *, gpointer);
void drag_data_received(GtkWidget *, GdkDragContext *, int, int, GtkSelectionData *, guint, guint, gpointer);

// main
int main(int argc, char *argv[]) {
    char main_dir[100];
    char sub_dir[100];
    int main_check = 1;

    system("./ls_c");
    sleep(1);

    drag_and_drop(argc, argv);

    FILE *fp = fopen("dropped_file.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file for reading.\n");
        exit(1);
    }

    for (int i = 0; i < num_files; i++) {
        char buf[100];
        fscanf(fp, "%s", buf);
        if (buf == NULL) {
            break;
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

            printf("The similarity between %s and %s is %lf\n", main_dir, sub_dir, similarity);
            sleep(1);
        }
    }

    fclose(fp);

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

    gtk_drag_dest_set(window, GTK_DEST_DEFAULT_ALL, targets, G_N_ELEMENTS(targets), GDK_ACTION_COPY);
    g_signal_connect(window, "drag-data-received", G_CALLBACK(drag_data_received), NULL);

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

            g_print("Dropped file: %s\n", filename);
            num_files++;
        }
        g_strfreev(uris);
    }
    gtk_drag_finish(context, TRUE, FALSE, time);
}
