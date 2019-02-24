/* Programming Exercise 10-9 */
#include <stdio.h>
#define ROWS 3
#define COLS 5
void copy_vla(int n, int m, double target[n][m], double source[n][m]);
void print_vla(int n, int m, double target[n][m]);

int main(void)
{
	int r, c;
	double source[ROWS][COLS] =
	{
		{ 66.6, 94.5, 34.8, 73.4, 39.7 },
		{ 36.4, 80.2, 64.7, 64.2, 62.9 },
		{ 98.1, 48.6, 46.6, 57.6, 32.4 }
	};
	double target[ROWS][COLS];

	printf("Source array:\n");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf("%.1f ", source[r][c]);
		putchar('\n');
	}

	copy_vla(ROWS, COLS, target, source);

	printf("Copying...\n");
	printf("Target array:\n");
	print_vla(ROWS, COLS, target);

	return 0;
}

void copy_vla(int n, int m, double target[n][m], double source[n][m])
{
	int r, c;
	for (r = 0; r < n; r++)
		for (c = 0; c < m; c++)
			target[r][c] = source[r][c];
}

void print_vla(int n, int m, double target[n][m])
{
	int r, c;
	for (r = 0; r < n; r++)
	{
		for (c = 0; c < m; c++)
			printf("%.1f ", target[r][c]);
		putchar('\n');
	}

}