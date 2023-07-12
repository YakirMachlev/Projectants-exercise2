#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "linearLinkedList.h"

#define LINE_LENGTH 60
#define BUFFER_INITIAL_CAPACITY 80
#define LIST_INITIAL_CAPACITY 130

void display_linked_list(LinearLinkedListNode* manager)
{
    LinearLinkedListNode* currentNode;
    int offset;
    char* buffer;
    int interval;
    int charsLeft;
    int length;

    currentNode = manager;
    interval = LIST_INITIAL_CAPACITY % LINE_LENGTH;
    charsLeft = 0;

    while (currentNode)
    {
        buffer = currentNode->info;
        offset = 0;

        length = LINE_LENGTH - charsLeft;
        for (offset = 0; offset < length && buffer[offset]; offset++)
            printf("%c", buffer[offset]);
        printf("\n");

        while (buffer[offset])
        {
            printf("%c", buffer[offset++]);
            !((offset + charsLeft) % LINE_LENGTH) ? printf("\n") : 0;
        }
        
        currentNode = currentNode->nextAddress;
        
        charsLeft += interval;
        charsLeft %= LINE_LENGTH;
    }
    printf("\n");
}

void display_buffer(char* buffer)
{
    int offset;

    while (*buffer)
    {
        for (offset = 0; offset < LINE_LENGTH && *buffer; offset++)
            printf("%c", *(buffer++));
        printf("\n");
    }
}

void insert_to_linked_list(LinearLinkedListNode* manager)
{
    char tav;
    LinearLinkedListNode* current;
    char* buffer;
    int count;

    count = 0;
    current = manager;
    while ((tav = getchar()) != EOF)
    {
        if (tav != '\n')
        {
            if (count == LIST_INITIAL_CAPACITY)
            {
                count = 0;
                buffer = (char*)calloc(LIST_INITIAL_CAPACITY, sizeof(char));
                insert_after_node_linear_linked_list(current);
                current = current->nextAddress;
                current->info = buffer;
            }
            current->info[count++] = tav;
        }
    }
}

void insert_to_buffer(char* buffer)
{
    int capacity;
    char tav;
    int count;

    capacity = BUFFER_INITIAL_CAPACITY;
    count = 0;

    while ((tav = getchar()) != EOF)
    {
        if (tav != '\n')
        {
            buffer[count++] = tav;
            if (count >= capacity)
            {
                capacity += BUFFER_INITIAL_CAPACITY;
                buffer = (char*)realloc(buffer, capacity * sizeof(char));
            }            
        }
    }
}

void printText(void* dataStruct, char option)
{
    printf("\nThe given text is:\n");
    switch (option)
    {
    case '1':
        display_buffer(dataStruct);
        break;
    case '2':
        display_linked_list(dataStruct);
        break;
    }
}

bool readText(void* dataStruct , char option)
{
    bool valid;
    valid = 1;

    switch (option)
    {
    case '1':
        insert_to_buffer(dataStruct);
        break;
    case '2':
        insert_to_linked_list(dataStruct);
        break;
    default:
        valid = 0;;
        break;
    }

    return valid;
}

int main()
{
    LinearLinkedListNode* manager;
    char* buffer;
    char option;
    bool isTerminal;
    void* dataStruct;
    bool valid;

    manager = NULL;
    isTerminal = 0;

    if (isatty(0))
    {   
        isTerminal = 1;
        printf("Choose an option for your input:\n");
        printf("1 - using a single buffer\n2 - using a linked list\n");
    }

    option = getchar();
    switch (option)
    {
    case '1':
        buffer = (char*)calloc(BUFFER_INITIAL_CAPACITY, sizeof(char));
        dataStruct = buffer;
        break;
    case '2':
        buffer = (char*)calloc(LIST_INITIAL_CAPACITY, sizeof(char));
        dataStruct = manager;
        push_linear_linked_list(&dataStruct);
        ((LinearLinkedListNode*)dataStruct)->info = buffer;
        break;
    }

    if (isTerminal)
        printf("Enter the text:\n");
    valid = readText(dataStruct, option);

    printText(dataStruct, option);
    if (!valid)
        printf("Error!\n");
    else
        option == '1' ? free(dataStruct) : free_linear_linked_list(&dataStruct);

    return 0;
}
