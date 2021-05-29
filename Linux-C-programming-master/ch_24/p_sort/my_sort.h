#ifndef MY_SORT_H
#define MY_SORT_H

typedef int (*cmp_t)(void *, void *);

extern void my_insertion_sort(void * const data, int num, cmp_t cmp, size_t size);
extern int my_binary_search (void *const data, void * targ, int num, cmp_t cmp, size_t size);

#endif // !MY_SORT_H