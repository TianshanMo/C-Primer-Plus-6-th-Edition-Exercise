/* Programming Exercise 11-5 */
#include <stdio.h>
#include <string.h>
#define SIZE 20
char * findchar(char * st, char ch);
char * s_gets(char * st, int n);

int main(void)
{
	char input[SIZE];
	char ch;
	char  * position;
	puts("Enter a string(empty to quit):");
	while (s_gets(input, SIZE) && input[0] != '\0')
	{
		puts("Enter a character:");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		position = findchar(input, ch);
		if (position != NULL)
			printf("The position of the character '%c' in the \"%s\" is %d.\n",
				ch, input, position - input + 1);
		else
			printf("404 not found.\n");
		puts("Enter next string(empty to quit):");
	}
	puts("Done.\n");

	return 0;
}

char * findchar(char * st, char ch)
{
	while (*st != ch)
	{
		if (*st == '\0')
			return NULL;
		st++;
	}
	return st;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}