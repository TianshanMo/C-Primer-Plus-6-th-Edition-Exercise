/* Programming Exercise 11-3 */
#include <stdio.h>
#include <ctype.h>
#define SIZE 20
char * getword(char * st);

int main(void)
{
	char word[SIZE];
	puts("Enter a string:");
	getword(word);
	puts(word);

	return 0;
}

char * getword(char * st)
{
	int ch;
	while ((ch = getchar()) != EOF && isspace(ch))
		continue;
	*st++ = ch;
	while ((ch = getchar()) != EOF && !isspace(ch))
		*st++ = ch;
	*st = '\0';
	while ((ch = getchar()) != '\n')
		continue;
	return st;
}