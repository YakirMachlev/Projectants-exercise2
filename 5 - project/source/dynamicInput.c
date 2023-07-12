#include "dynamicInput.h"

void display_buffer(char *buffer)
{
    while (*buffer)
        printf("%c", *(buffer++));
    printf("\n");
}

char *insert_to_buffer(char *buffer, int *length)
{
    int capacity;
    char tav;
    bool flag;
    char *tempBuffer;

    capacity = BUFFER_INITIAL_CAPACITY;
    *length = 0;
    flag = TRUE;

    while ((tav = getchar()) != '\n' && tav != EOF && flag)
    {
        buffer[(*length)++] = tav;
        if (*length >= capacity)
        {
            capacity += BUFFER_INITIAL_CAPACITY / 2;
            tempBuffer = (char *)realloc(buffer, capacity * sizeof(char));
            if (tempBuffer)
                buffer = tempBuffer;
            else
            {
                printf("Line too long. Reallocation failed\n");
                flag = FALSE;
            }
        }
    }
    buffer[*length] = '\0';

    return buffer;
}