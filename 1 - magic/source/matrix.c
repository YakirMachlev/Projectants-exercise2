#include "matrix.h"

void print_matrix(int* startPtr, int* endPtr)
{
	int* current = startPtr;

	while (current <= endPtr)
	{
		printf("%3d", *current);
		((current - startPtr) % WIDTH == WIDTH - 1) ? printf("\n") : 0;
		current++;
	}
	printf("\n");
}

int main_diagonal_sum(int* startPtr, int* endPtr)
{
	int* currentPtr;
	int sum;

	sum = 0;
	currentPtr = startPtr;

	while (currentPtr <= endPtr)
	{
		sum += *currentPtr;
		currentPtr += WIDTH + 1;
	}
	return sum;
}

int secondary_diagonal_sum(int* startPtr, int* endPtr)
{
	int* currentPtr;
	int sum;

	sum = 0;
	currentPtr = startPtr + WIDTH - 1;
	endPtr = endPtr - WIDTH + 1;

	while (currentPtr <= endPtr)
	{
		sum += *currentPtr;
		currentPtr = currentPtr + WIDTH - 1;
	}
	return sum;
}

int mat_row_sum(int* startPtr, int* endPtr)
{
	int* currentPtr;
	int sum;

	sum = 0;
	currentPtr = startPtr;

	while (currentPtr <= endPtr)
		sum += *(currentPtr++);
		
	return sum;
}

int mat_column_sum(int* startPtr, int* endPtr)
{
	int* currentPtr;
	int sum;

	sum = 0;
	currentPtr = startPtr;

	while (currentPtr <= endPtr)
	{
		sum += *currentPtr;
		currentPtr += WIDTH;
	}
	return sum;
}

bool is_matrix_valid(bool flag, int count)
{
    bool valid;

    valid = 0;
    if (!flag)
        printf("An invalid value was entered\n");
    else if (count < AMOUNT)
        printf("Not enough values\n");
    else if (count > AMOUNT)
        printf("Too much values\n");
    else
        valid = 1;
    
    return valid;
}

bool insert_numbers_to_matrix(int* startPtr, int* endPtr)
{
    int num;
    int* current;
    bool flag;
    int count;
    int relativePos;
    
    current = startPtr;
    count = 0;
    while ((flag = scanf("%d",  &num)) == 1)
    {
    	relativePos = (current++ - startPtr) % AMOUNT;
        *(startPtr + relativePos) = num;
        count++;
    }

    return is_matrix_valid(flag, count);
}
