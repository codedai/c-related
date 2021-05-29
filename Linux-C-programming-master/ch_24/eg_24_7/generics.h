#ifndef GENERICS_H
#define DENERICS_H

typedef int (*cmp_t) (void *, void *);
extern void * max (void *data[], int num, cmp_t cmp);

#endif // !GENERICS_H