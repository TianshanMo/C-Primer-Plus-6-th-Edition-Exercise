/* Programming Exercise 9-2 */
#include <stdio.h>
#include <stdlib.h>
void chline(char ch, int i, int j);

int main(void)
{
	char ch;
	int i, j;
	printf("Prints the requested character in columns i through j.\n");
	printf("Enter a character and two integers, separated by spaces:\n");
	while ((ch = getchar()) != '\n')
	{
		if (scanf("%d %d", &i, &j) != 2)
			break;
		chline(ch, i, j);
		while (getchar() != '\n')
			continue;
		printf("Enter another character and two integers;\n");
		printf("Enter a newline to quit.\n");
	}
	
	return 0;
}

void chline(char ch, int i, int j)
{
	int row, col;
	for (row = 1; row <= i; row++)
	{
		for (col = 1; col <= j; col++)
			putchar(ch);
		putchar('\n');
	}
}