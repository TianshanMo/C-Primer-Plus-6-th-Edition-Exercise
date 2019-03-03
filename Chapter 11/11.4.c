/* Programming Exercise 11-3 */
#include <stdio.h>
#include <ctype.h>
#define SIZE 20
char * getword(char * st, int n);

int main(void)
{
	char word[SIZE];
	puts("Enter a string:");
	getword(word, SIZE / 2);
	puts(word);

	return 0;
}

char * getword(char * st, int n)
{
	int i = 0;
	int ch;
	while ((ch = getchar()) != EOF && isspace(ch))
		continue;
	st[i] = ch;
	i++;
	while ((ch = getchar()) != EOF && !isspace(ch) && i < n)
	{
		st[i] = ch;
		i++;
	}
	st[i] = '\0';
	while ((ch = getchar()) != '\n')
		continue;
	return st;
}