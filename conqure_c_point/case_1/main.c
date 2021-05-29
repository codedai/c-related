#include <stdio.h>
#include <stdlib.h>

#include "get_word.h"
#include "word_manage.h"

#define WORD_LEN_MAX (1024)

int main(int argc, char **argv) {
    char buf[WORD_LEN_MAX];
    FILE *fp;

    if (argc==1) fp = stdin;
    else {
        fp = fopen(argv[1], "r");
        if (fp == NULL) {
            fprintf(stderr, "%s: %s cannot open.\n",
                    argv[0], argv[1]);
            exit(1);
        }
    }

    /*initialize the word management part*/
    word_initialize();

    /* add words while reading the file*/
    while(get_word(buf, WORD_LEN_MAX, fp) != EOF) {
        add_word(buf);
    }

    /* output part */
    dump_word(stdout);

    /* end word management part */
    word_finalize();

    return 0;
}
