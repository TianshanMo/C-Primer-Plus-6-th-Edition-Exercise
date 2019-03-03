/* Programming Exercise 11-9 */
#include <stdio.h>
#include <string.h>
#define SIZE 30
void * StringReverse(char * st);
char * s_gets(char * st, int n);

int main(void)
{
	char str[SIZE];

	puts("Enter a string(empty to quit):");
	while (s_gets(str, SIZE) && str[0] != '\0')
	{
		StringReverse(str);
		puts("The reversed string:");
		puts(str);
		
		puts("Enter a string(empty to quit):");
	}
	puts("Done.\n");

	return 0;
}

void * StringReverse(char * st)
{
	int i;
	int n = strlen(st);
	char temp;
	for (i = 0; i < n / 2; i++)
	{
		temp = st[i];
		st[i] = st[n - i - 1];
		st[n - i - 1] = temp;
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