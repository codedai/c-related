#include <stdio.h>

enum coordinate_type { RECTANGULAR, POLAR };

struct complex_struct {
	enum coordinate_type t;
	double a, b;
};


struct complex_struct make_from_real_img(double x, double y) {
	struct complex_struct z = {RECTANGULAR, x, y};
	return z;
}

struct complex_struct make_from_mag_ang(double r, double a) {
	struct complex_struct z = {POLAR, r, a};
	return z;
}



int main(void)
{
	printf("%d %d\n", RECTANGULAR, POLAR);
	return 0;
}