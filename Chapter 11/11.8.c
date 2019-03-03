/* Programming Exercise 11-8 */
#include <stdio.h>
#include <string.h>
#define SIZE 30
char * string_in(char * st1, char * st2);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[SIZE];
	char str2[SIZE];
	char * find;

	printf("Enter a string(empty to quit):\n");
	while (s_gets(str1, SIZE) && str1[0] != '\0')
	{
		printf("Enter a string to look for:\n");
		s_gets(str2, SIZE);

		find = string_in(str1, str2);
		if (find)
			printf("The position of the string \"%s\" in the string \"%s\" is: %d\n",
				str2, str1, find - str1);
		else
			printf("404 not found\n");

		printf("Enter a string(empty to quit):\n");
	}
	puts("Done.\n");

	return 0;
}

char * string_in(char * st1, char * st2)
{
	int i, j = 0;
	for (i = 0; *(st1 + i) != '\0'; i++)
	{
		while (*(st1 + i) == *(st2 + j))
		{
			j++;
			if (*(st2 + j) == '\0')
				return st1 + i;
		}
	}

	return NULL;
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