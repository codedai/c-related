#include <stdio.h>

char * strcpy(char * dest, const char * src) {
    int i;
    for (i=0; src[i] != '\0'; i++) dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}

char *my_strcpy(char *dest, const char*src){
    char *temp = dest;
    while((*dest++ = *src++) != '\0');
    return temp;
}

char * shrink_space(char * dest, const char * src, size_t n) {
    size_t i = 0, j = 0;
    while (i < n-1 && src[i] != '\0') {
        
        if (src[i] != ' ' && src[i] != '\n' && src[i] != '\t' && src[i] != '\r') {
            // printf("%c\n", src[i]);
            dest[j] = src[i];
            i++;
            j++;
            if (src[i] == ' ' || src[i] == '\n' || src[i] == '\t' || src[i] == '\r') {
                dest[j] = ' ';
                i++;
                j++;
            }
        } else 
            i++;
    }
    if (i <= n) {
        if (src[i] != ' ' || src[i] != '\n' || src[i] != '\t' || src[i] != '\r') {
            dest[j] = src[i];
        }
    }
    return dest;
}

char * improved_shrink_space(char * dest, const char * src, size_t n) {
    size_t i = 0, j = 0;
    char * temp = dest;

    for (i = 0; i < n-1 && *src != '\0'; i++) {
        if (*src != ' ' && *src != '\n' && *src != '\t' && *src != '\r') {
            *dest++ = *src++;
            if (*src == ' ' || *src == '\n' || *src == '\t' || *src == '\r') {
                *dest = ' ';
                dest++;
                src++;
            }
        } else src++;
    }
    if (i <= n) {
        if (*src != ' ' || *src != '\n' || *src != '\t' || *src != '\r') {
            *dest = *src;
        }
    }
    return temp;
}

int main (void) {
    char a[512];
    a[511] = '\0';
    char *b = "This Content hoho       is ok\
        ok?\
        \
        file system\
        uttered words   ok ok      ?\
        end.";
    printf("%s\n", my_strcpy(a, b));
    printf("%s\n", improved_shrink_space(a, b, 1000));
    return 0;
}