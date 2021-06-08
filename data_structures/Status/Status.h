#ifndef STATUS_H
#define STATUS_H

#include <stdio.h>

/* status code */
#define TRUE     1
#define FALSE    0
#define OK       1
#define ERROR   -1

// Already have this statue code in the system, use ifndef to avoid conflict
#ifndef OVERFLOW
#define OVERFLOW    -2  // stack overflow
#endif

#ifndef NULL
#define ((void *)0)
#endif

/* status code type */
typedef int Status;

/* Bool type */
typedef int Boolean;

/* Global variable */
extern Boolean debug;


/* 
 * Read characters from a file
 */

int ReadData(FILE *fp, char * format, ...);

void PressEnterToContinue(Boolean debug);

void Wait(long time);

void skipBlank(FILE * fp);

#endif 
