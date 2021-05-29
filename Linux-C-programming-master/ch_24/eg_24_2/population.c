#include <string.h>
#include "population.h"

void set_unit(unit_t *p) {
    if (p == NULL) return; /* ignore NULL parameter */
    p->number = 3;
    strcpy(p->msg, "HELL NO!");
}