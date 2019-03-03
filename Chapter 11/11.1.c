/* Programming Exercise 11-1 */
#include <stdio.h>
#define TEST 20
char * getnchar(char * st, int n);
int main(void)
{
	char input[TEST];
	puts("Enter a string");
	getnchar(input, TEST - 1);
	puts(input);

	return 0;
}

char * getnchar(char * st, int n)
{
	int i;
	int ch;
	for (i = 0; i < n; i++)
	{
		if ((ch = getchar()) == EOF)
			break;
		else
			st[i] = ch;
	}

	st[i] = '\0';

	return st;
}