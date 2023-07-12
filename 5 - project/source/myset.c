#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "classification.h"
#include "dynamicInput.h"

#define IS_TERMINAL isatty(0)

set SETA = 0;
set SETB = 0;
set SETC = 0;
set SETD = 0;
set SETE = 0;
set SETF = 0;

set *setsVec[6] = {&SETA, &SETB, &SETC, &SETD, &SETE, &SETF};

char *trim_edges_white_spaces(char *buffer, int length)
{
    char *end;
    end = buffer + length - 1;

    while (isspace(*buffer))
        buffer++;

    if (!(*buffer))
        return NULL;

    while (end > buffer && isspace(*end))
        end--;
    *(end + 1) = '\0';

    return buffer;
}

char count_char_in_string(char *buffer, char tav)
{
    char count;
    count = 0;

    while (*buffer)
        count += *(buffer++) == tav;

    return count;
}

void analyze_entire_command(char *buffer, bool *stop)
{
    char *commandName;
    char *startPtr;
    char **allParameters;
    int length;
    int offset;
    int size;

    *stop = !strcmp(buffer, "stop");
    if (*stop)
        return;

    commandName = buffer;
    while (*buffer && !isspace(*(buffer++)));
    *(buffer - 1) = '\0';

    size = count_char_in_string(buffer, ',') + 1;
    allParameters = (char **)malloc(sizeof(char *) * size);
    offset = 0;

    while (*buffer)
    {
        startPtr = buffer;
        while (*buffer && *buffer != ',')
            buffer++;

        *buffer = '\0';
        length = buffer - startPtr;
        allParameters[offset++] = trim_edges_white_spaces(startPtr, length);
        buffer++;
    }

    run_command(commandName, allParameters, size, setsVec);
    free(allParameters);
}

void run_sets_calculator()
{
    char *buffer;
    bool stop;
    int length;
    
    stop = FALSE;

    while (!stop)
    {
        buffer = (char *)malloc(BUFFER_INITIAL_CAPACITY * sizeof(char));
        if (IS_TERMINAL)
            printf("Enter a command:\n");
        buffer = insert_to_buffer(buffer, &length);

        if (length)
        {
            printf("The given command is:\n");
            display_buffer(buffer);

            buffer = trim_edges_white_spaces(buffer, length);
            analyze_entire_command(buffer, &stop);
        }
        else
            free(buffer);
        printf("\n");
    }
    if (!stop)
        printf("Reached EOF\n");
}

int main()
{
    run_sets_calculator();

    return 0;
}