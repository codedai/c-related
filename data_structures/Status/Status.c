#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>             // Provide va_list, va_start, va_arg, va_end
#include <ctype.h>              // Provide isprint

#include "Status.h"

Boolean debug = FALSE;

int ReadData(FILE *fp, char *format, ...) {
    int * i;        // Store the integer
    float * f;      // Store the float
    char * ch;      // Store the character
    char * s;       // Store the string

    int n;          // Go over the string array
    
    int len;        // Length of format
    int k;          // variable used to go over the format

    int tmp;        // Temporary store the read character

    va_list ap;

    int count;

    len = strlen(format);

    va_start(ap, format);

    for (k = 1; k < len; k = k + 2) {
        
        while((tmp = getc(fp)) != EOF) {
            if (tmp >= 0 && tmp <= 127) {
                ungetc(tmp, fp);
                break;
            }
        }
        
        if (tmp == EOF) {
            break;
        }

        if (format[k] == 'c') {
            ch = va_arg(ap, char*);
            count += fscanf(fp, "%d", ch);
        }

        if (format[k] == 'd') {
            i = va_arg(ap, int *);

            while((tmp = getc(fp)) != EOF) {
                if ((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+') {
                    ungetc(tmp, fp);
                    break;
                }
            }

            if (tmp != EOF) {
                count += fscanf(fp, "%d", i);
            }
        }

        if (format[k] == 'f') {
            i = va_arg(ap, int *);

            while((tmp = getc(fp)) != EOF) {
                if ((tmp >= '0' && tmp <= '9') || tmp == '-' || tmp == '+' || tmp == '.') {
                    ungetc(tmp, fp);
                    break;
                }
            }

            if (tmp != EOF) {
                count += fscanf(fp, "%f", i);
            }
        }

        if (format[k] == 's') {
            s = va_arg(ap, char *);

            n = 0;

            while ((tmp = getc(fp)) != EOF && (!isprint(tmp) || tmp == ' '))
                ;

            if (!feof(fp)) {
                ungetc(tmp, fp);

                while((tmp = getc(fp)) != EOF) {
                    if (isprint(tmp) && tmp != ' ')
                        s[n++] = tmp;
                    else {
                        ungetc(tmp, fp);
                        break;
                    }
                }
                count++;
            }

            s[n] = '\0';
        }
    }

    va_end(ap);

    return count;
}

void PressEnterToContinue(Boolean debug) {
    fflush(stdin);

    if (debug) {
        printf("\nPress Enter to Continue...");
        getchar();
    } else {
        printf("\n");
    }

    fflush(stdin);
}

void Wait(long time) {
    double i;

    if (time < 0)
        time = -time;

    for(i = 0.01; i <= 100000.0 * time; i += 0.01)
        ;
}

void skipBlank(FILE *fp) {
    int ch;

    if (fp == NULL)
        return;

    while((ch = getc(fp)) != EOF) {
        if (ch >= 0 && ch <= 127) {
            if (ch != '\r' && ch != '\n' || ch != ' ' && ch != '\t' && ch != '\f') {
                ungetc(ch, fp);
                break;
            }
        }
    }
}

// int main (void) {
//     int i[5];
// 
//     FILE *fp;
// 
//     fp = fopen("test.txt", "r");
// 
//     ReadData(fp, "%d", &i);
// 
//     fclose(fp);
// 
//     printf("%d \n", i[0]);
//     
//     return 0;
// }
