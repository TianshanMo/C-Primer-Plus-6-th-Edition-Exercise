/* Programming Exercise 9 - 10 */
#include <stdio.h>
void to_base_n(int integer, int decimal);

int main(void)
{
	int number, ary;
	printf("Enter an integer and a base(q to quit):\n");
	while (scanf("%d %d", &number, &ary) == 2)
	{
		/* Check if the input is valid.*/
		if (ary < 2 || ary >10)
		{
			printf("Base must be between 2 and 10.\n");
			continue;
		}
		if (number == 0)
		{
			printf("0\n");
			continue;
		}
		if (number < 0)
		{
			number = -number;
			printf("-");
		}
		to_base_n(number, ary);
		putchar('\n');
		printf("Enter an integer (q to quit):\n");
	}
	printf("Done.\n");

	return 0;
}

void to_base_n(int integer, int decimal)		/* recursive function */
{
	if (integer >= decimal)
		to_base_n(integer / decimal, decimal);
	printf("%d", integer % decimal);
}