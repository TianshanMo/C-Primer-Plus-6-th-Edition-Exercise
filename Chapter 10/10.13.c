/* Programming Exercise 10-13 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void input(double(*lattice)[COLS], int rows);				// void input(double lattice[][COLS], int rows);
double average_row(double *ar, int cols);					// double average_row(double ar[], int cols);
double average_all(double(*ar)[COLS], int rows, int cols);	// double average_all(double ar[][COLS], int rows, int cols)
double max_all(double(*ar)[COLS], int rows, int cols);		// double max_all(double ar[][COLS], int rows, int cols)
void print(double(*lattice)[COLS], int rows);				// void print(double lattice[][COLS], int rows);

int main(void)
{
	double lattice[ROWS][COLS];

	input(lattice, ROWS);
	print(lattice, ROWS);

	return 0;
}

void input(double(*lattice)[COLS], int rows)
{
	for (int r = 0; r < rows; r++)
	{
		printf("%d/3. Enter five numbers:", r + 1);
		for (int c = 0; c < COLS; c++)
			scanf("%lf", *(lattice + r) + c);	// scanf("%lf", &lattice[r][c]);
	}
}

void print(double(*lattice)[COLS], int rows)
{
	printf("\nThe average of each set of five values:\n");
	for (int i = 0; i < rows; i++)
		printf("Average of row %d is %.2lf\n", i + 1, average_row(lattice + i, COLS));	// average_row(lattice[i], COLS));

	printf("\nThe average of all the value is %.2lf\n", average_all(lattice, rows, COLS));

	printf("\nThe largest value of the 15 values is %.2lf\n", max_all(lattice, rows, COLS));	
}

double average_row(double *ar, int cols)
{
	double average, total = 0;
	for (int c = 0; c < cols; c++)
		total += *(ar + c);		// total += ar[c];
	average = total / cols;
	
	return average;
}

double average_all(double(*ar)[COLS], int rows, int cols)
{
	double average, total = 0;
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			total += *(*(ar + r) + c);	// total += ar[r][c];
	average = total / (rows * cols);

	return average;
}

double max_all(double(*ar)[COLS], int rows, int cols)
{
	double max = ar[0][0];
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
		{
			if (max < *(*(ar + r) + c))		// max < ar[r][c]
				max = *(*(ar + r) + c);		// max = ar[r][c];
		}

	return max;
}