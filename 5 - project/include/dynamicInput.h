#ifndef DYN_INPUT
#define DYN_INPUT
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_INITIAL_CAPACITY 80

#ifndef BOOL
#define BOOL
typedef enum{FALSE, TRUE}bool;
#endif

void display_buffer(char *buffer);
char *insert_to_buffer(char *buffer, int *length);
#endif