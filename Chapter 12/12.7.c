/* Programming Exercise 12-7 */
/* manydice.c -- multiple dice rolls                      */
/* compile with diceroll.c                                */
#include <stdio.h>
#include <stdlib.h>             /* for library srand()    */
#include <time.h>               /* for time()             */

int rollem(int sides);

int main(void)
{
	int dice, roll = 0;
	int sides;
	int sets;
	int total = 0;

	srand((unsigned int)time(0)); /* randomize seed      */
	printf("Enter the number of sets; enter q to stop: ");
	while (scanf("%d", &sets) == 1 && sets > 0)
	{
		printf("How many sides and how many dices? ");
		if ((scanf("%d %d", &sides, &dice)) != 2)
		{
			while (getchar() != '\n')
				continue;
			printf("Invalid input. Enter the number of sets; enter q to stop: ");
			continue;
		}
		printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
		for (int i = 0; i < sets; i++)	// number of times the dice are rolled
		{
			if (i % 15 == 0 && i != 0)
				printf("\n");
			for (int dice_num = 0; dice_num < dice; dice_num++)	// number of dices
				total += rollem(sides);
			printf("%d ", total);
			total = 0;
		}
		printf("\nEnter the number of sets; enter q to stop: ");
	}
	printf("GOOD FORTUNE TO YOU!\n");

	return 0;
}

/* roll dice simulator */
int rollem(int sides)
{
	int roll;
	roll = rand() % sides + 1;

	return roll;
}
