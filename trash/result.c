void print_similarity() {
    FILE *fp_result = fopen("similarity_result.txt", "r");
    if (fp_result == NULL) {
        printf("Failed to open file: similarity_result.txt\n");
        exit(1);
    }
    for (int i = 0; i < num_sub_files; i++) {
        char text[100];
        fgets(text, sizeof(text), fp_result);

        int len = (70 - strlen(text)) / 2;
        for (int j = 0; j < 70 -len - strlen(text) - 1; j++) {
            printf(" ");
        }
        
        const char *keyword = "is";

        char *keyword_position = strstr(text, keyword);

        size_t before_keyword = keyword_position - text;
        printf("%.*s", (int) before_keyword, text);
        printf("%s", keyword);

        char *percentage_position = strstr(keyword_position, "%");
        char *number_start = keyword_position + strlen(keyword) + 1;
        size_t number_length = percentage_position - number_start;
        char number_string[50];
        strncpy(number_string, number_start, number_length);
        number_string[number_length] = '\0';
        double number = atof(number_string);

        const char *color_code;
        if (number > 90) {
            color_code = "\033[31m";
        }
        else if (number > 70) {
            color_code = "\033[35m";
        }
        else if (number > 50) {
            color_code = "\033[34m";
        }
        else if (number > 30) {
            color_code = "\033[33m";
        }
        else {
            color_code = "\033[32m";
        }

        int offset = (int) (percentage_position - keyword_position - strlen(keyword));

        printf("%s", color_code);
        printf("%.*s", offset, keyword_position + strlen(keyword));
        printf("%%");
        printf("\033[0m\n");
    }
}
