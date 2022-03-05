#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void putin(int num, int* arr) {
	for (int i = 0; i < 4; i++) {
		arr[i] = num % 10;
		num /= 10;
	}
}
void swap(int* arr, int L, int R) {
	if (L != R) {
		int p = arr[L];
		arr[L] = arr[R];
		arr[R] = p;
	}
}
void sort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			int tmp = arr[i] > arr[j] ? i : j;
			swap(arr, tmp, i);
		}
	}
}
int main() {
	int a[4];
	int N = 0, R = 0;
	scanf("%d", &N);
	if (N == N % 10 * 1111) {
		printf("%d - %d = 0000", N, N);
		return 0;
	}
	int flag = 0;
	while (R != 6174) {
		putin(N, a);
		sort(a, 4);
		int big = 0, small = 0;
		for (int k = 0; k < 4; k++) {
			big = big * 10 + a[k];
			small = small * 10 + a[3-k];
		}
		R = big - small;
		if (flag == 1)
			printf("\n");
		printf("%d - %04d = %04d", big, small, R);
		flag = 1;
		N = R;
	}
	return 0;
}