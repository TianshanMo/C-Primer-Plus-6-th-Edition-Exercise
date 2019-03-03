/* Programming Exercise 11-6 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 20
bool is_within(char ch, char * st);
char * s_gets(char * st, int n);

int main(void)
{
	char input[SIZE];
	char ch;
	bool position;
	puts("Enter a string(empty to quit):");
	while (s_gets(input, SIZE) && input[0] != '\0')
	{
		puts("Enter a character:");
		ch = getchar();
		while (getchar() != '\n')
			continue;
		position = is_within(ch, input);
		if (position == 1)
			printf("'%c' found in string \"%s\"\n", ch, input);
		else
			printf("404 not found.\n");
		puts("Enter next string(empty to quit):");
	}
	puts("Done.\n");

	return 0;
}

bool is_within(char ch, char * st)
{
	while (*st++ != '\0')
	{
		if (*st == ch)
			return 1;
	}
	return 0;
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