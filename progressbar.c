#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char bar = '=';
    const char blank = ' ';
    const int LEN = 50;
    const int MAX = 100;
    const int SPEED = 35;
    int count = 0;
    int i;
    float tick = (float) MAX / LEN;
    printf("%.2f%% 단위로 bar 1개 출력\n\n", tick);
    int barCount;
    float percent;
    
    while (count <= MAX) {
        printf("\r[");
        percent = (float) count / MAX * 100;
        barCount = (int) (percent / tick);
        for (i = 0; i < LEN; i++) {
            if (i < barCount)
                printf("%c", bar);
            else
                printf("%c", blank);
        }
        printf("] %.2f%%", percent);
        fflush(stdout); // 출력 버퍼 비우기
        count++;
        usleep(SPEED * 1000);
    }
    printf("\ndone!\n\n");
    system("pause");
    return 0;
}
