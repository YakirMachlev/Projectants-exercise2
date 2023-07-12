#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum{FALSE, TRUE}bool;
#define INITIAL_CAPACITY 10
#define LINE_LENGTH 90

bool is_alnum(char tav)
{
    return (tav >= 'a' && tav <= 'z') || (tav >= 'A' && tav <= 'Z') || (tav >= '0' && tav <= '9');
}

void display_input(char* input)
{
    int offset;
    while (*input)
    {
        offset = 0;
        while (offset++ < LINE_LENGTH && *input != '\n')
            printf("%c", *(input++));

        printf("\n");
        input += *input == '\n';
    }
    printf("\n");
}

char* insert_chars(int* count, int* countAlNum)
{
    int capacity;
    char* input;
    char* temp;
    char tav;
    bool valid;

    capacity = INITIAL_CAPACITY;
    *countAlNum = 0;
    *count = 0;
    input = (char*)malloc(capacity * sizeof(char));
    valid = 1;

    while ((tav = getchar()) != EOF && valid)
    {
        input[(*count)++] = tav;
        *countAlNum += is_alnum(tav);

        if (*count >= capacity)
        {
            capacity *= 2;
            temp = (char*)realloc(input, capacity * sizeof(char));
            if (temp)
                input = temp;
            else
            {
                printf("Reallocation failed\n");
                valid = 0;
            }
        }
    }

    return input;
}

void handle_input()
{
    int countAlNum;
    int count;
    char* input;

    if (isatty(0))
        printf("Enter a text:\n");
    input = insert_chars(&count, &countAlNum);

    printf("\nReceived input:\n");
    display_input(input);

    printf("The total amount of characters is: %d\n", count);
    printf("The amount of alpha-numeric characters is: %d\n", countAlNum);

    free(input);
}

int main()
{
    handle_input();

    return 0;
}