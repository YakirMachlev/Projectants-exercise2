#ifndef MATRIX
	#define MATRIX
	#include <stdio.h>

	typedef char string[100];
	#define WIDTH 5
	#define HEIGHT 5
	#define AMOUNT (WIDTH * HEIGHT)
	typedef enum{FALSE, TRUE}bool;

	#define MAT_COLUMN(x, y) ((x) - (y)) % WIDTH
	#define MAT_ROW(x, y) ((x) - (y)) / WIDTH

	void print_matrix(int*, int*);
	int main_diagonal_sum(int*, int*);
	int secondary_diagonal_sum(int*, int*);
	int mat_row_sum(int*, int*);
	int mat_column_sum(int*, int*);
	bool insert_numbers_to_matrix(int*, int*);
#endif