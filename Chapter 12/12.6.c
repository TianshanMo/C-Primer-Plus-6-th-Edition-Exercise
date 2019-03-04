/* Programming Exercise 12-6 */
#include <stdio.h>
#include <stdlib.h>
#define SIZE 100
#define COUNT 10

void statics(int * ar);

int main(void)
{
	int random[SIZE];
	for (int count = 0; count < COUNT; count++)
	{
		srand(count);
		for (int i = 0; i < SIZE; i++)
			random[i] = rand() % 10 + 1;
		statics(random);
	}

	return 0;
}

void statics(int * ar)
{
	static int group = 1;
	int num;
	int num_count = 0;
	printf("Group : %d\n", group);
	printf("Number: ");
	for (num = 1; num < COUNT + 1; num++)
		printf("%-3d ", num);
	printf("\n");
	printf("Counts: ");
	for (num = 1; num < COUNT + 1; num++)
	{
		for (int i = 0; i < SIZE; i++)
		{
			if (num == ar[i])
			num_count++;
		}
		printf("%-3d ", num_count);
		num_count = 0;
	}

	group++;
	puts("\n-----------------------------------------------------");
}