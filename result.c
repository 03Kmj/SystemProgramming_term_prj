    printf("\n\n -----------------------------------RESULT----------------------------------\n");
    fp_result = fopen("similarity_result.txt", "r");
    if (fp_result == NULL) {
        printf("Failed to open file: similarity_result.txt\n");
        exit(1);
    }

    for (int i = 0; i < 2; i++) {
        printf("|");
        for (int j = 0; j < 76; j++) {
            printf(" ");
        }
        printf("|\n");
    }

    for (int i = 0; i < num_sub_files; i++) {
        printf("| ");
        char buf[100];
        fgets(buf, sizeof(buf), fp_result);
        int len = (76 - strlen(buf)) / 2;
        for (int j = 0; j < 76 - len - strlen(buf) - 1; j++) {
            printf(" ");
        }
        printf("%s", buf);
        for (int j = 0; j < len; j++) {
            printf(" ");
        }
        printf("|\n");
    }

    for (int i = 0; i < 2; i++) {
        printf("|");
        for (int j = 0; j < 76; j++) {
            printf(" ");
        }
        printf("|\n");
    }

    printf(" ---------------------------------------------------------------------------\n");

