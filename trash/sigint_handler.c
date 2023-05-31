#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

// 시그널 핸들러 함수
void signal_handler(int signum) {
    // 시그널 무시
}

int main() {
    // 모든 시그널을 무시하는 핸들러 등록
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    // 필요한 다른 시그널들도 추가로 등록 가능

    // 메인 프로그램 시작
    while (1) {
        printf("working...\n");
        sleep(1);
    }

    return 0;
}
