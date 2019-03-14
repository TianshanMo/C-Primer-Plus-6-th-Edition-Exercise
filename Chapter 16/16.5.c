/* Programming Exercise 16-5 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5
void select(int ar[], int n, int picks);

int main(void)
{
	int vals[SIZE];
	int picks;
	srand((unsigned int)time(0));
	for (int i = 0; i < SIZE; i++)
	{
		vals[i] = rand();
		printf("%d ", vals[i]);
	}

	printf("Enter number of picks: ");
	while (scanf("%d", &picks) == 1)
	{
		select(vals, SIZE, picks);
		printf("\nEnter number of picks(q to quit): ");
	}
	
	return 0;
}

void select(int ar[], int n, int picks)
{
	int index, temp;
	if (picks > n)
	{
		printf("The number of picks should no more than %d", n);
		return;
	}
	for (int i = 0; i < picks; i++)
	{
		index = rand() % n;
		printf("%d ", ar[index]);

		temp = ar[index];
		ar[index] = ar[n - 1];
		ar[n - 1] = temp;
		n--;
	}
}