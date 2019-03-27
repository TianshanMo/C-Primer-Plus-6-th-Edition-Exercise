/* Programming Exercise 17-6 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

bool BinSearch(int * ar, int n, int find);

int main(void)
{
	int num[SIZE] = { 2,3,5,7,11,13,17,19,23,29 };
	int BeFind;
	for (int i = 0; i < SIZE; i++)
		printf("%-2d ", num[i]);

	printf("\nEnter an integer to find it:\n");
	while (scanf("%d", &BeFind) == 1)
	{
		if (BinSearch(num, SIZE, BeFind))
			printf("%d is in this array.\n", BeFind);
		else
			printf("%d is not in this array.\n", BeFind);
		printf("Enter an integer to find it(q to quit):\n");
	}
	printf("Done.\n");

	return 0;
}

bool BinSearch(int * ar, int n, int find)
{
	int low = 0, high = n;
	int half = n / 2;

	while (ar[half] != find)
	{
		if (find > ar[half])
			low = half;
		else if (find < ar[half])
			high = half;
		if (half == (low + high) / 2)
			return false;
		half = (low + high) / 2;
	}

	return true;
}