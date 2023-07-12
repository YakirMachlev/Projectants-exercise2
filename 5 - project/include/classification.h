#ifndef CLASSIFICTION
#define CLASSIFICTION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "set.h"

#ifndef BOOL
#define BOOL
typedef enum{FALSE, TRUE}bool;
#endif

void run_command(char *command, char **parameters, int size, set *setsVec[]);
#endif