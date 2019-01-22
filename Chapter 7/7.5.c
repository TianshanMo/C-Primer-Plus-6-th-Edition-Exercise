/* Programming Exercise 7-5 */
#include <stdio.h>
#define STOP '#'
int main(void)
{
	char ch;
	int count = 0;
	printf("Enter input (# to exit):\n");
	while ((ch = getchar()) != STOP)
	{
		switch (ch)
		{
			case '.' :
				printf("!"), count++;
				break;
			case '!' :
				printf("!!"), count++;
				break;
			default:
				putchar(ch);
				break;
		}
	}
	printf("A total of %d %s were made.\n",
		count, count == 1 ? "replacement" : "replacements");

	return 0;
}