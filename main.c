#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./main [main_dir] [dir_1] [dir_2] ... \n");
    }
    char *main_dir = argv[1];
    printf("main_dir: %s\n", main_dir);
    sleep(1);

    for (int i = 2; i < argc; i++) {
        char *dir = argv[i];
        char command[100];
        sprintf(command, "python3 ./similarity.py %s %s", main_dir, dir);
        system(command);

        FILE *fp = fopen("similarity.txt", "r");
        if (fp == NULL) {
            printf("Error: cannot open file\n");
            return 1;
        }
        double similarity;
        fscanf(fp, "%lf", &similarity);
        printf("The similarity between %s and %s is %lf\n", main_dir, dir, similarity);
        sleep(1);
    }

    return 0;
}
