#include <stdio.h>
#include <math.h>

#define LEN 8
int a[LEN] = {1, 2, 2, 2, 5, 6, 8, 9};

double power(double x, int y);

int binarysearch(int number) {
    int mid, s = 0, e = LEN - 1;
    while (s <= e) {
        mid = (e + s) / 2;
        if (a[mid] == number) {
            return  mid;
        } else if (a[mid] > number) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return -1;
}

int binarysearch_v2(int number) {
    int mid, s = 0, e = LEN - 1;
    while (s < e) {
        mid = (e + s) / 2;
        if (a[mid] == number) {
            e = mid;
        } else if (a[mid] > number) {
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    if (a[s] == number) {
        return s;
    }
    return -1;
}

double mysqrt(double y) {
    double x, s = 0, e = y;
    x = y / 2;
    while (fabs(x * x - y) > 0.000001) {
        if ((x * x - y) > 0) {
            e = x;
        } else {
            s = x;
        }
        x = (e+s) / 2;

    }
    return x;
}

double mypow(double x, int n) {
    if (n < 0) return 1 / power(x, -n);
    else return power(x, n);
}

double power(double x, int n) {
    if (n == 0) return 1;
    double half = power(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return x * half * half;
}

int main(void)
{
	printf("%d\n", binarysearch_v2(2));
    printf("%.6f\n", mysqrt(2));
    printf("%.6f\n", mypow(10, 3));
	return 0;
}