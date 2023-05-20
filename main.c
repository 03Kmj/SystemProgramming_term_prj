#include <stdio.h>

void similar() {
    printf("similar check\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: ./main [main_dir] [dir_1] [dir_2] ... \n");
    }
    char *main_dir = argv[1];
    printf("main_dir: %s\n", main_dir);

    for (int i = 2; i < argc; i++) {
        char *dir = argv[i];
        printf("dir%d: %s\n",i - 1, dir);
        similar();
    }

    return 0;
}
