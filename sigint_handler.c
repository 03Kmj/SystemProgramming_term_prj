#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
// SIGINT 핸들러 함수
void sigint_handler(int signum) {
    char choice;
    printf("프로그램을 종료하시겠습니까? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        exit(0);
    }
}

int main() {
    // SIGINT 핸들러 등록
    signal(SIGINT, sigint_handler);

    // 메인 프로그램 시작
    while (1) {
       printf("working...\n");
       sleep(1);
    }
    return 0;
}
