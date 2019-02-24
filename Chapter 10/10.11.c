/* Programming Exercise 10-11 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void print_arr(int(*ar)[COLS], int n);
void dbl(int(*ar)[COLS], int n);

int main(void)
{
	int lattice[ROWS][COLS] = 
	{
		{ 718, 109, 775, 831, 854 },
		{ 289, 237, 649, 663, 814 },
		{ 448, 602, 439, 126, 519 }
	};
	printf("The values before the array is doubled are as follows:\n");
	print_arr(lattice, ROWS);

	dbl(lattice, ROWS);

	printf("The values after the array is doubling are as follows:\n");
	print_arr(lattice, ROWS);

	return 0;
}

void print_arr(int(*ar)[COLS], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLS; j++)
			printf("%d	", *(*(ar + i) + j));
		putchar('\n');
	}
}

void dbl(int(*ar)[COLS], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < COLS; j++)
			*(*(ar + i) + j) *= 2;
}