#include <stdio.h>
#include "word_manage_p.h"

void dump_word(FILE *fp) {
    for (Word * pos = word_header; pos != NULL; pos = pos->next) {
        fprintf(fp, "%-20s%5d\n", 
                pos->name, pos->count); 
    }
}
