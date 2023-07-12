#include "classification.h"

bool is_number(char *str)
{
    bool flag;
    char sign;
    flag = TRUE;

    sign = *(str++);
    while (*str && flag)
    {
        if (!isdigit(*str))
            flag = FALSE;
        str++;
    }

    return flag && (sign == '-' || isdigit(sign));
}

set *match_set_by_name(char *setName, set *setsVec[])
{
    return setsVec[setName[3] - 'A'];
}

bool is_valid_set_name(char *setName)
{
    char identifier;
    bool valid_length;

    identifier = 0;
    valid_length = strlen(setName) == 4;
    if (valid_length)
        identifier = setName[3];

    return !strncmp(setName, "SET", 3) && (identifier >= 'A' && identifier <= 'F') && valid_length;
}

bool are_set_memebers_valid(set *setName, char **members, int size)
{
    bool valid;
    int currentNum;
    int offset;

    valid = TRUE;
    for (offset = 0; offset < size && valid; offset++)
    {
        if (is_number(*members))
        {
            currentNum = atoi(*members);
            if (offset == size - 1 && currentNum == -1)
                valid = TRUE;
            else if (offset == size - 1 && currentNum != -1)
            {
                valid = FALSE;
                printf("List of set members is not terminated correctly\n");
            }
            else if (currentNum > 127 || currentNum < 0)
            {
                valid = FALSE;
                printf("Invalid set member - value out of range\n");
            }
        }
        else
        {
            valid = FALSE;
            printf("Invalid set member - not an integer\n");
        }
        members++;
    }

    return valid;
}

void run_read_set(char **parameters, int size, set *setsVec[])
{
    set* s;
    int offset;
    char *readParameters;

    if (size < 2)
        printf("Missing parameter\n");
    else
    {
        if (is_valid_set_name(parameters[0]))
        {
            s = match_set_by_name(parameters[0], setsVec);
            parameters++;
            size--;
            if (are_set_memebers_valid(s, parameters, size))
            {
                readParameters = (char *)malloc(sizeof(char) * size);
                for (offset = 0; offset < size; offset++)
                    readParameters[offset] = atoi(parameters[offset]);

                read_set(s, readParameters);
                free(readParameters);
            }
        }
        else
            printf("Undefined set Name\n");
    }
}

void run_print_set(char **parameters, int size, set *setsVec[])
{
    set* s;

    if (size < 1)
        printf("Missing parameter\n");
    else if (size > 1)
        printf("Extraneous text after end of command\n");
    else
    {
        if (is_valid_set_name(parameters[0]))
        {
            s = match_set_by_name(parameters[0], setsVec);
            print_set(*s);
        }
        else
            printf("Undefined set Name\n");
    }
}

void run_sets_functions(char *command, char **parameters, int size, set *setsVec[])
{
    set *sets[3];
    int offset;
    bool valid;

    if (size < 3)
        printf("Missing parameter\n");
    else if (size > 3)
        printf("Extraneous text after end of command\n");
    else
    {
        for (offset = 0; offset < size && valid; offset++)
        {
            if (is_valid_set_name(parameters[offset]))
                sets[offset] = match_set_by_name(parameters[offset], setsVec);
            else
            {
                valid = 0;
                printf("Undefined set Name\n");
            }
        }
        if (valid)
        {
            if (!strcmp(command, "union_set"))
                union_set(*sets[0], *sets[1], sets[2]);
            else if (!strcmp(command, "intersect_set"))
                intersect_set(*sets[0], *sets[1], sets[2]);
            else if (!strcmp(command, "sub_set"))
                sub_set(*sets[0], *sets[1], sets[2]);
            else if (!strcmp(command, "symdiff_set"))
                symdiff_set(*sets[0], *sets[1], sets[2]);
            else
                printf("Undefined command name\n");
        }
    }
}

void run_command(char *command, char **parameters, int size, set *setsVec[])
{
    int offset;
    bool valid;

    valid = TRUE;
    for (offset = 0; offset < size; offset++)
    {
        if (!parameters[offset])
            valid = FALSE;
    }

    if (valid)
    {
        if (!strcmp(command, "read_set"))
            run_read_set(parameters, size, setsVec);
        else if (!strcmp(command, "print_set"))
            run_print_set(parameters, size, setsVec);
        else
            run_sets_functions(command, parameters, size, setsVec);
    }
    else
        printf("Multiple consecutive commas\n");
}