#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define ALLOC_SIZE (256)

static char *st_line_buffer = NULL;

static int st_current_buffer_size = 0;

static int st_current_used_size = 0;

static void add_character(int ch) {
    assert(st_current_buffer_size >= st_current_used_size);

    if (st_current_buffer_size == st_current_used_size) {
        st_line_buffer = realloc(st_line_buffer, 
                sizeof(char) * (st_current_buffer_size + ALLOC_SIZE));
        st_current_buffer_size += ALLOC_SIZE;
    }

    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
}

char * read_line(FILE * fp) {
    int ch;
    char *ret;

    st_current_used_size = 0;
    while((ch=getc(fp)) != EOF) {
        if (ch == '\n') {
            add_character(ch);
            break;
        }
        add_character(ch);
    }

    if (ch == EOF) {
        if (st_current_used_size > 0){
            add_character('\0');
        } else {
            return NULL;
        }
    }

    ret = malloc(sizeof(char)*st_current_used_size);
    strcpy(ret, st_line_buffer);

    return ret;
}

void free_buffer(void) {
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}
