#include <math.h>
#include <stdio.h>

struct complex_struct {
    double x, y;
};

double real_part(struct complex_struct z) {
    return z.x;
}

double img_part(struct complex_struct z) {
    return z.y;
}

double magnitude(struct complex_struct z) {
    return sqrt(z.x * z.x + z.y * z.y);
}

double angle(struct complex_struct z) {
    return atan2(z.y, z.x);
}

struct complex_struct make_from_real_img(double x, double y) {
    struct complex_struct z = {x, y};
    return z;
}

struct complex_struct make_from_mag_ang(double r, double A) {
    struct complex_struct z = {
        r * cos(A),
        r * sin(A)
    };
    return z;
}

struct complex_struct add_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_real_img(real_part(z1) + real_part(z2),
				  img_part(z1) + img_part(z2));
}

struct complex_struct sub_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_real_img(real_part(z1) - real_part(z2),
				  img_part(z1) - img_part(z2));
}

struct complex_struct mul_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_mag_ang(magnitude(z1) * magnitude(z2),
				 angle(z1) + angle(z2));
}

struct complex_struct div_complex(struct complex_struct z1, struct complex_struct z2) {
	return make_from_mag_ang(magnitude(z1) / magnitude(z2),
				 angle(z1) - angle(z2));
}

void print_rational(struct complex_struct z) {
    if (z.x > 0 || z.x < 0) printf("%.1f", z.x);
    if (z.y > 0) printf("+%.1fi", z.y);
    else {
        if (z.y < 0) printf("%.1fi", z.y);
    }
    printf("\n");
}

int main(void)
{
	struct complex_struct a = make_from_real_img(1, 8); /* a=1/8 */
	struct complex_struct b = make_from_real_img(-1, 8); /* b=-1/8 */
	print_rational(add_complex(a, b));
	print_rational(sub_complex(a, b));
	print_rational(mul_complex(a, b));
	print_rational(div_complex(a, b));

	return 0;
}