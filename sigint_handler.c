#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// 시그널 핸들러 함수
void signal_handler(int signum) {
    // 시그널 무시
}

int main() {
    // 모든 시그널을 무시하는 핸들러 등록
    struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    for (int i = 1; i <= 31; i++) {
        sigaction(i, &sa, NULL);
    }

    // 메인 프로그램 시작
    while (1) {
        printf("working...\n");
        sleep(1);
    }

    return 0;
}
