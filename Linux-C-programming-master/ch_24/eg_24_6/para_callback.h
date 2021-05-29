#ifndef PARA_CALLBACK_H
#define PARA_CALLBACK

typedef void (*callback_t) (void*);
extern void repeat_three_times(callback_t, void *);

#endif // !PARA_CALLBACK_H