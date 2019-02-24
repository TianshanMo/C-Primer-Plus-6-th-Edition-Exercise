/* Programming Exercise 10-14 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void input(int rows, int cols, double lattice[rows][cols]);
void print(int rows, int cols, double lattice[rows][cols]);
double average_row(int cols, double ar[cols]);
double average_all(int rows, int cols, double ar[rows][cols]);
double max_all(int rows, int cols, double ar[rows][cols]);


int main(void)
{
	double lattice[ROWS][COLS];

	input(ROWS, COLS, lattice);
	print(ROWS, COLS, lattice);

	return 0;
}

void input(int rows, int cols, double lattice[rows][cols])
{
	for (int r = 0; r < rows; r++)
	{
		printf("%d/3. Enter five numbers:", r + 1);
		for (int c = 0; c < cols; c++)
			scanf("%lf", &lattice[r][c]);
	}
}

void print(int rows, int cols, double lattice[rows][cols])
{
	printf("\nThe average of each set of five values:\n");
	for (int i = 0; i < rows; i++)
		printf("Average of row %d is %.2lf\n", i + 1, average_row(cols, lattice[i]));

	printf("\nThe average of all the value is %.2lf\n", average_all(rows, cols, lattice));

	printf("\nThe largest value of the 15 values is %.2lf\n", max_all(rows, cols, lattice));
}

double average_row(int cols, double ar[cols])
{
	double average, total = 0;
	for (int c = 0; c < cols; c++)
		total += ar[c];
	average = total / cols;

	return average;
}

double average_all(int rows, int cols, double ar[rows][cols])
{
	double average, total = 0;
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
			total += ar[r][c];
	average = total / (rows * cols);

	return average;
}

double max_all(int rows, int cols, double ar[rows][cols])
{
	double max = ar[0][0];
	for (int r = 0; r < rows; r++)
		for (int c = 0; c < cols; c++)
		{
			if (max < ar[r][c])
				max = ar[r][c];
		}

	return max;
}