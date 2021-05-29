#ifndef POPULATION_H
#define POPULATION_H

typedef struct {
    int number;
    char msg[20];
} unit_t;

extern void set_unit(unit_t *);

#endif // !POPULATION_H