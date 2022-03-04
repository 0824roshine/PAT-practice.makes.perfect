#include <stdio.h>

#define MAXN 10
typedef float ElementType;
ElementType Median(ElementType A[], int N) {
    for (int gap = N / 2; gap > 0; gap = gap / 2) {
        for (int i = gap; i < N; i++) {
            for (int j = i - gap; j >= 0 && A[j] > A[j + gap]; j -= gap) {
                ElementType tmp = A[j];
                A[j] = A[j + gap];
                A[j + gap] = tmp;
            }
        }
    }
    return A[N / 2];
}
int main()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}