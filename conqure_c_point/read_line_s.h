#ifndef READ_LINE_S_H
#define READ_LINE_S_H

#include <stdio.h>

typedef enum {
    READ_LINE_SUCCESS,
    READ_LINE_EOF,
    READ_LINE_OUT_OF_MEMORY
} ReadLineStatus;

ReadLineStatus read_line(FILE *fp, char ** line);
void free_buffer(void);

#endif
