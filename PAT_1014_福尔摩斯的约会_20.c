#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int* arr, int L, int R) {
	if (L != R) {
		int p = arr[L];
		arr[L] = arr[R];
		arr[R] = p;
	}
}
void bigsort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			int tmp = arr[i] > arr[j] ? i : j;
			swap(arr, tmp, i);
		}
	}
}
void smallsort(int* arr, int len) {
	int L = 0, R = len - 1;
	while (L < R) {
		swap(arr, L, R);
		L++;
		R-- ;
	}
}
int makenum(int* arr) {
	return (1000 * arr[0] + 100 * arr[1] + 10 * arr[2] + arr[3]);
}
int main() {
	int in = 0;
	scanf("%d", &in);
	int newd = 0;
	int flag = 0;
	while (newd != in) {
		int arr[4];
		int tmp = in;
		for (int k = 0; k < 4; k++) {
			arr[k] = tmp % 10;
			tmp = tmp / 10;
		}
		bigsort(arr, 4);
		int big = makenum(arr);
		smallsort(arr, 4);
		int small = makenum(arr);
		newd = big - small;
		if (newd == in)
			break;
		else {
			if (flag == 1)
				printf("\n");
			printf("%d - %d = %d", big, small, newd);
			in = newd;
			flag = 1;
		}
	}
return 0;
}