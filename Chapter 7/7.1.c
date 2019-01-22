/* Programming Exercise 7-1 */
#include <stdio.h>
int main(void)
{
	char ch;
	int spaces = 0;
	int lines = 0;
	int others = 0;
	printf("Enter input (# to stop):\n");
	while (!((ch = getchar()) == '#'))
	{
		if (ch == ' ')
			spaces++;
		else if (ch == '\n')
			lines++;
		else
			others++;
	}
	printf("You have entered %d spaces, %d lines, %d others.\n", spaces, lines, others);

	return 0;
}