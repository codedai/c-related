#include <stdio.h>
#include <math.h>

struct rational {
    int num, dnum;
};

int cal_gcd(int a, int b) {
    if (a < b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    int t = 1;
    while (t != 0) {
        t = a % b;
        a = b;
        b = t;
    }
    return a;

}

struct rational make_rational(int num, int dnum) {
    struct rational a = {num, dnum};
    return a;
}

struct rational add_rational(struct rational a, struct rational b) {
    int n, d, gcd;
    n = a.num * b.dnum + b.num * a.dnum;
    d = a.dnum * b.dnum;

    struct rational ans = {n, d};
    return ans;
}

struct rational sub_rational(struct rational a, struct rational b) {
    int n, d, gcd;
    n = a.num * b.dnum - b.num * a.dnum;
    d = a.dnum * b.dnum;


    struct rational ans = {n, d};
    return ans;
}

struct rational mul_rational(struct rational a, struct rational b) {
    int n, d, gcd;
    n = a.num * b.num;
    d = a.dnum * b.dnum;

    struct rational ans = {n, d};
    return ans;   
}
struct rational div_rational(struct rational a, struct rational b) {
    int n, d, gcd;
    n = a.num * b.dnum;
    d = a.dnum * b.num;

    struct rational ans = {n, d};
    return ans;  
}

void print_rational(struct rational a) {
    if (a.num == 0) printf("0\n");
    else if (a.num == a.dnum ) printf("1");
    else if ( a.num == -1*a.dnum) printf("1");
    else {
        int gcd = cal_gcd(a.num, a.dnum);
        printf("%d/%d\n", a.num / gcd, a.dnum / gcd);
    }
    
}

int main(void)
{
	struct rational a = make_rational(1, 8); /* a=1/8 */
	struct rational b = make_rational(-1, 8); /* b=-1/8 */
	print_rational(add_rational(a, b));
	print_rational(sub_rational(a, b));
	print_rational(mul_rational(a, b));
	print_rational(div_rational(a, b));

	return 0;
}