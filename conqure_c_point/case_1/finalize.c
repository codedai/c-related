#include <stdlib.h>
#include "word_manage_p.h"

void word_finalize(void) {
    for (int i = 0; i < num_of_word; i++)
        free(word_array[i].name);

    num_of_word = 0;
}
