#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include "matrix.h"

#define N WIDTH

bool magic_square_validity(int* startPtr, int* endPtr)
{
    int vec[AMOUNT] = {0};
    int* currentPtr;
    bool magic;

    currentPtr = startPtr;
    magic = 1;
    while (currentPtr <= endPtr && magic)
    {
        magic &= *currentPtr >= 1 && *currentPtr <= AMOUNT;
        magic &= !vec[*currentPtr % AMOUNT];
        vec[*(currentPtr++) % AMOUNT]++;
    }

    return magic;
}

bool is_magic_square(int* startPtr, int* endPtr)
{
    int offset;
    int mSum;
    int sSum;
    bool magic;

    mSum = main_diagonal_sum(startPtr, endPtr);
    sSum = secondary_diagonal_sum(startPtr, endPtr);
    magic = mSum == sSum;
    for (offset = 0; offset < N && magic; offset++)
    {
        magic &= mSum == mat_row_sum(startPtr + offset * N, startPtr + offset * N + N - 1);
        magic &= mSum == mat_column_sum(startPtr + offset, startPtr + offset + N * (N - 1));
    }
    return magic;
}

void handle_input(int mat[][N])
{
    int* startPtr;
    int* endPtr;
    bool valid;
    
    startPtr = *mat;
    endPtr = startPtr + AMOUNT - 1;
    valid = 0;
    if (isatty(0))
        printf("Enter the matrix values for a matrix with %d values:\n", AMOUNT);
    if (insert_numbers_to_matrix(startPtr, endPtr))
    {
        printf("\n");
        print_matrix(startPtr, endPtr);

        if (magic_square_validity(startPtr, endPtr))
        {
            if (is_magic_square(startPtr, endPtr))
                valid = 1;
        }
        valid ? printf("The matrix is a magic square\n") : printf("The matrix isn't a magic square\n");
    }
}

int main()
{
    int mat[N][N];
    handle_input(mat);

    return 0;
}