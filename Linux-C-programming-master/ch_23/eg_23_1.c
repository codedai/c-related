#include <stdio.h>

int * swap (int *px, int *py) {
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
    return px;
}

void increment(int *x)
{
	*x = *x + 1;
}


int main(void) {
    int i = 10, j = 20;
    int *p = swap(&i, &j);
    printf("%d, %d, %d\n", i, j, *p);
    increment(&i); /* i now becomes 2 */
	increment(&j); /* j now becomes 3 */
    printf("%d, %d, %d\n", i, j, *p);

    const char *pc = "abcd";

    char str_1[5] = {'a', 'b', 'c', '\0'};
    char *str_2 = "abc"; // char const * str_2
    char * as[5] = {"anc", "adc", "aaa", "bbb", "ccc"};
    char **pstr_2 = &str_2;

    char const * ch_c_s_p = str_1;
    char * const ch_s_c_p = str_1;
    const char * const c_ch_s_p = str_1;

    char ** s_s_p = pstr_2;
    char const ** ch_c_s_s_p = &ch_c_s_p;
    char * const * ch_s_c_s_p = as;
    char ** const ch_s_s_c_p = as;


    // const int * cisp =

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    int (*pa_1)[10] = &a;
    // int *pa_2[10] = &a;

    char ta[4][3][2] = {{{'a', 'b'}, {'c', 'd'}, {'e', 'f'}},
		   {{'g', 'h'}, {'i', 'j'}, {'k', 'l'}},
		   {{'m', 'n'}, {'o', 'p'}, {'q', 'r'}},
		   {{'s', 't'}, {'u', 'v'}, {'w', 'x'}}};
    char (*pa)[2] = &ta[1][0];
    char (*ppa)[3][2] = &ta[1];

    printf("%c, %c\n", *(*(pa+1)+1), *(*(*(ppa+1) + 2) + 1) );
    printf("%p, %p\n", pa, ppa);

    return 0;
}