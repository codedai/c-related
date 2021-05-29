#ifndef WORD_MANAGE_P_H
#define WORD_MANAGE_P_H

#include "word_manage.h"

typedef struct {
    char *name;
    int count;
} Word;

#define WORD_NUM_MAX (1024)

extern Word word_array[];
extern int num_of_word;

#endif
