#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <CoreFoundation/CoreFoundation.h> //macOS
//windows: #include <windows.h>

int main(){
    const char bar = '=';
    const char blank = ' ';
    const int LEN = 20;
    const int MAX = 1000;
    const int SPEED = 35;
    int count = 0;
    int i;
    float tick = (float)100/LEN;
    printf("%.2f%% 마다 bar 1개 출력 \n\n", tick);
    int barCount;
    float percent;
    while(count < MAX){
        printf("\r%d%d [", count, MAX);
        percent = (float)count/MAX*100;
        barCount = (int)(percent/tick);
        for(i=0; i<LEN; i++){
            if(i<barCount) printf("%c", bar);
            else printf("%c", blank);
        }
        printf("] %.2f%%", percent);
        count++;
        usleep(SPEED * 1000);
    }
    printf("done!\n\n");
    system("pause");
    return 0;
}
