#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Print_Factorial(const int N);
int main()
{
    int N;
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial(const int N) {
    int a[3001] = { 0 };
    a[3000] = 1;
    int i = 0;
    int tmp = 0;
    int count = 1;
    if (N < 0 || N>1000) {
        printf("Invalid input");
        return;
    }
    if (N < 2) {
        printf("%d! = %d", N,a[3000]);
        return;
    }
    for (int k = 2; k <= N; k++) {
        int proceed = 0;
        int p = 0;
        for (p = 0; p < count; p++) {
            tmp = a[3000 - p] * k + proceed;
            if (tmp > 9) {
                proceed = tmp / 10;
                a[3000 - p] = tmp % 10;
            }
            else {
                proceed = 0;
                a[3000 - p] = tmp % 10;
            }
        }
        tmp = tmp / 10;
        while (tmp) {
            a[3000 - count] = tmp % 10;
            count++;
            tmp = tmp / 10;
        }
    }
    printf("%d! = ", N);
    for (i = 0; i < count; i++) {
        printf("%d", a[3001 - count + i]);
    }
}