#define MAX(a, b) (a > b ? a : b)
#define STR(s) #s
#define CONCAT(a, b) a##b
#define HASH_HASH # ## #
#define showlist(...) printf(#__VA_ARGS__)
#define report(test, ...) ((test)? printf(#test):\
                            printf(__VA_ARGS__))

k = MAX(i&0x0f, j&0x0f);
STR(hello world);
fputs(STR(strncmp("ab\"c\0d", "abc", '\4') == 0) STR(: @\n), s);
CONCAT(con, cat);
showlist(The first, second, and third items.)
report(x>y, "x is %d but y is %d", x, y);


