/* Programming Exercise 7-4 */
#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int count = 0;
	printf("Enter input (# to exit):\n");
	while ((ch = getchar()) != STOP)
	{
		if (ch == '.')
		{
			printf("!");
			count++;
		}
		else if (ch == '!')
		{
			printf("!!");
			count++;
		}
		else
			putchar(ch);
	}
	printf("A total of %d %s were made.\n",
		count, count == 1 ? "replacement" : "replacements");

	return 0;
}