#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double f(double x, double* arr) {
    double res = 0;
    for (int i = 0; i < 4; i++) {
        res = res * x + arr[i];
    }
    return res;
}
double search(float left, float right, float* arr) {
    while ((right - left) > 0.001) {
        double L = f(left, arr);
        double M = f((left + right) / 2, arr);
        double R = f(right, arr);
        if (L == 0)
            return left;
        if (R == 0)
            return right;
        if (M == 0)
            break;
        if (L * M < 0)
            right = (right + left) / 2;
        else if (R * M < 0)
            left = (right + left) / 2;
    }
    return (right + left) / 2;
}
int main() {
    int i;
    double arr[4];
    for (i = 0; i < 4; i++) {
        scanf("%lf", &arr[i]);
    }
    double left, right;
    scanf("%lf%lf", &left, &right);
    printf("%.2lf", search(left, right, arr));
}