#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_slogan(FILE *fp, char **slogan){
    char buf[1024];
    int i;

    for (i=0; i<7; i++) {
        fgets(buf, 1024, fp);
        buf[strlen(buf)-1] = '\0';

        slogan[i] = malloc((strlen(buf)+1) * sizeof(char));

        if (slogan[i] != NULL) strcpy(slogan[i], buf);

    }
}

int main (void) {
    char *slogan[7];
    int i;

    read_slogan(stdin, slogan);

    for (i=0; i<7; i++) printf("%s\n", slogan[i]);

    return 0;
}
