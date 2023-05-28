#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./main [main_dir] [dir_1] [dir_2] ... \n");
        return 0;
    }
    char *main_dir = argv[1];
    printf("main_dir: %s\n", main_dir);
    sleep(1);

    // .c파일이 있는지 확인 필요
    // 없으면 프로그램 종료
    system("./ls_c");
    sleep(1);

    //using popen()
    for (int i = 2; i < argc; i++) {
        char *dir = argv[i];
        char command[100];
        sprintf(command, "python3 ./similarity.py %s %s", main_dir, dir);
        FILE *fp = popen(command, "r");
        if (fp == NULL) {
            printf("Error: cannot open file\n");
            return 1;
        }

        double similarity;
        fscanf(fp, "%lf", &similarity);
        pclose(fp);
        printf("The similarity between %s and %s is %lf\n", main_dir, dir, similarity);
        sleep(1);
    }

    return 0;
}
