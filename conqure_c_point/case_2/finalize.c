#include <stdlib.h>
#include "word_manage_p.h"

void word_finalize(void) {
    for (Word * pos = word_header; pos != NULL; pos = pos->next)
    free(pos->name);

    word_header = NULL;
}
