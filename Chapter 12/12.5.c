/* Programming Exercise 12-5 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
void decending_sort(int * ar);

int main(void)
{
	int i;
	int random[SIZE];
	printf("%d random numbers not exceeding 10 are as follows:\n", SIZE);
	srand((unsigned int)time(0));	// randomize seed
	for (i = 0; i < SIZE; i++)
	{
		if ((i % 10 == 0) && (i != 0))
			printf("\n");
		random[i] = rand() % 10 + 1;
		printf("%-2d ", random[i]);
	}

	decending_sort(random);

	printf("\nAfter descending sorting:\n");
	for (i = 0; i < SIZE; i++)
	{
		if ((i % 10 == 0) && (i != 0))
			printf("\n");
		printf("%-2d ", random[i]);
	}
	printf("\nDone.\n");

	return 0;
}

void decending_sort(int * ar)
{
	int temp;
	int i, j;
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			if (ar[i] < ar[j])
			{
				temp = ar[i];
				ar[i] = ar[j];
				ar[j] = temp;
			}
		}
	}

}