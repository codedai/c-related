#include "stdio.h"

struct complex_struct {
    double x, y;
} x2;

void print_struct(struct complex_struct x) {
    printf("%f, %f\n", x.x, x.y);
}

struct complex_struct add_complex(struct complex_struct x1, struct complex_struct x2) {
    x1.x = x1.x + x2.x;
    x1.y = x2.y + x1.y;
    return x1;
}

int main(void) {
    struct simple_struct
    {
        double x, y;
    } z2, z3;
    
    double m = 3.0;

    struct simple_struct z1 = {m, 4.0};
    struct complex_struct x1 = {.x=1};
    struct complex_struct x;



    print_struct(x1);
    print_struct( add_complex(x1, x1));
    print_struct(x1);
    return 0;
}