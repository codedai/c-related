#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_manage_p.h"

static char * my_strdup(char * src);

void add_word(char * word);

static char * my_strdup(char * src) {
    char * dest;
    dest = malloc(sizeof(char) * (strlen(src) + 1));
    strcpy(dest, src);
    return dest;
}

void add_word(char * word) {
    // int i;
    int result;
    Word *s_p;
    Word *prev;

    prev = NULL;
    for (s_p = word_header; s_p != NULL; s_p = s_p->next) {
        result = strcmp(s_p->name, word);
        if (result >= 0)
            break;
        prev = s_p;
    }
    
    if (s_p != NULL && result == 0){
        s_p->count++;
    } else {
        Word * new_word = malloc(sizeof(Word));
        new_word->name = my_strdup(word);
        new_word->count = 1;
        new_word->next = s_p;
        if (prev==NULL){
            word_header = new_word;
        } else
            prev->next = new_word;
    }
}








