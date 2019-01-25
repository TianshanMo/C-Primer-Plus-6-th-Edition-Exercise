/* Programming Exercise 8-6 */
#include <stdio.h>
char get_first(void);
int main(void)
{
	int ch;

	printf("returns the first non-whitespace character encountered.\n");
	printf("Please enter a string:\n");
	ch = get_first();
	printf("The result is %c\n", ch);

	return 0;
}

char get_first(void)
{
	int ch;

	ch = getchar();
	while (ch == ' ')
	{
		ch = getchar();
		continue;
	}
	while (getchar() != EOF)
		continue;

	return ch;
}