/* Programming Exercise 9 - 3 */
#include <stdio.h>
void display(char ch, int i, int j);

int main(void)
{
	char ch;
	int i, j;
	printf("Prints the requested character in columns j through i.\n");
	printf("Enter a character and two integers, separated by spaces:\n");
	while ((ch = getchar()) != '\n')
	{
		if (scanf("%d %d", &j, &i) != 2)
			break;
		display(ch, j, i);
		while (getchar() != '\n')
			continue;
		printf("Enter another character and two integers;\n");
		printf("Enter a newline to quit.\n");
	}
	
	return 0;
}

void display(char ch, int j, int i)
{
	int row, col;
	for (row = 1; row <= i; row++)
	{
		for (col = 1; col <= j; col++)
			putchar(ch);
		putchar('\n');
	}
}