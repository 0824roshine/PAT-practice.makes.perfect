#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
    char num = '0';
    char arr[5] = { '0' };
    int past = 0,i=0;
    for (i = 0; i < 5; i++) {
        scanf("%c", &num);
        if (num == ' ') {
            arr[i] = '\0';
            scanf("%d", &past);
            break;
        }
        else {
            arr[i] = num;
        }
    }
    int hour = 0, min = 0;

    if (i==3) {
        min = (arr[1] - '0') * 10 + (arr[2] - '0');
        hour = arr[0] == '0' ? 24 : arr[0] - '0';
    }
    else if (i==4) {
        min = (arr[2] - '0') * 10 + (arr[3] - '0');
        hour = (arr[0] - '0') * 10 + (arr[1] - '0');
    }
    int now = hour * 60 + min;
    now = now + past;
    while (now < 0) {
        now += 60 * 24;
    }
    hour = (now / 60) % 24;
    min = now % 60;
    if (min <10)
        printf("%d%d%d", hour,0, min);
    else
        printf("%d%d", hour,min);
    return 0;
}