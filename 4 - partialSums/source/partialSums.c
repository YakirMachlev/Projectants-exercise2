#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef enum{FALSE, TRUE}bool;

int* partial_sums_vector(int* vec, int length)
{
    int offset;
    int* partialSumsVec;

    partialSumsVec = (int*)malloc(length * sizeof(int));
    partialSumsVec[0] = vec[0];

    for (offset = 1; offset < length; offset++)
        partialSumsVec[offset] = partialSumsVec[offset - 1] + vec[offset];

    return partialSumsVec;
}

void print_vector(int* vec, int length)
{
    int offset;

    for (offset = 0; offset < length; offset++)
        printf("%d ", vec[offset]);
    printf("\n");
}

int main()
{
    bool flag;
    int length;
    int offset;
    int* vec;
    int* partialSumsVec;

    flag = isatty(0);
    if (flag)
        printf("Enter the vector's length: ");
    scanf("%d", &length);
    if (flag)
        printf("Enter the vector's values:\n");

    vec = (int*)malloc(length * sizeof(int));
    for (offset = 0; offset < length; offset++)
        scanf("%d", &vec[offset]);

    printf("The vector's length is: %d\n", length);
    printf("The vector's values are:\n");
    print_vector(vec, length);

    partialSumsVec = partial_sums_vector(vec, length);
    printf("\nThe partial sums vector's values are:\n");
    print_vector(partialSumsVec, length);

    free(vec);
    free(partialSumsVec);

    return 0;
}