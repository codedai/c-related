#include <stdio.h>

int main(void)
{
	int count[4] = { 3, 2, }, i;

	for (i = 0; i < 4; i++)
		printf("count[%d]=%d\n", i, count[i]);
    int a[5] = { 4, 3, 2, 1 };
    int b[5] = { 4, 3, 2, 1 };
    b = a;
    printf("%d\n", *b);
	return 0;
}