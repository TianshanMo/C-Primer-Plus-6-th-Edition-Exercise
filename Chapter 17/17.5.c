/* Programming Exercise 17-5 */
#include <stdio.h>
#include <string.h>
#include "17.5 stack.h"
#define SLEN 50
char * s_gets(char * st, int n);

int main(void)
{
	Stack st;
	char temp[SLEN];
	char ch;
	InitializeStack(&st);

	printf("Enter a string, empty to quit:\n");
	while (s_gets(temp, SLEN) && temp[0] != '\0')
	{
		int i = 0;
		while (temp[i] != '\0' && !FullStack(&st))
		{
			Push(temp[i], &st);
			i++;
		}
		while (!EmptyStack(&st))
		{
			if (Pop(&ch, &st))
				printf("%c", ch);
		}
		printf("\nEnter a string, empty to quit:\n");
	}
	putchar('\n');

	return 0;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');   // look for newline
		if (find)                  // if the address is not NULL,
			*find = '\0';          // place a null character there
		else
			while (getchar() != '\n')
				continue;          // dispose of rest of line
	}

	return ret_val;
}