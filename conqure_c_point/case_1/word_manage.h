#ifndef WORD_MANAGE_H
#define WORD_MANAGE_H

#include <stdio.h>

void word_initialize(void);
void add_word(char *word);
void dump_word(FILE *fp);
void word_finalize(void);

#endif
