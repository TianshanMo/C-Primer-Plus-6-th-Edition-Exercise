/* Programming Exercise 11-10 */
#include <stdio.h>
#include <string.h>
#define SIZE 30
void * DeleteSpace(char * st);
char * s_gets(char * st, int n);

int main(void)
{
	char str[SIZE];

	puts("Enter a string(empty to quit):");
	while (s_gets(str, SIZE) && str[0] != '\0')
	{
		puts("The string after deleting spaces:");
		DeleteSpace(str);
		puts(str);

		puts("Enter a string(empty to quit):");
	}
	puts("Done.\n");

	return 0;
}

void * DeleteSpace(char * st) 
{
	int i, j;
	for (i = 0; st[i] != '\0'; i++)
	{
		if (st[i] == ' ')
		{
			for (j = i; st[j] != '\0'; j++)
				st[j] = st[j + 1];
			i--; 
		}
	}
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