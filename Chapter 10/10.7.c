/* Programming Exercise 10-7 */
#include <stdio.h>
#define ROWS 3
#define COLS 7
void copy_arr(double target[][COLS], double source[][COLS], int n);

int main(void)
{
	int r, c;
	double source[ROWS][COLS] = 
	{
		{ 66.6, 94.5, 34.8, 73.4, 39.7, 56.4, 24.0 },
		{ 36.4, 80.2, 64.7, 64.2, 62.9, 53.4, 19.4 },
		{ 98.1, 48.6, 46.6, 57.6, 32.4, 95.8, 88.2 }
	};
	double target[ROWS][COLS];
	printf("Source array:\n");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf("%.1f ", source[r][c]);
		putchar('\n');
	}

	copy_arr(target, source, ROWS);

	printf("Copying...\n");
	printf("Target array:\n");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf("%.1f ", source[r][c]);
		putchar('\n');
	}

	return 0;
}

void copy_arr(double target[][COLS], double source[][COLS], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < COLS; j++)
			target[i][j] = source[i][j];
	}
}