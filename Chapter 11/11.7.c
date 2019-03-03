/* Programming Exercise 11-7 */
#include <stdio.h>
#include <string.h>
#define SIZE 30
char * mystrncpy(char *, char *, int n);
char * s_gets(char * st, int n);

int main(void)
{
	char str1[SIZE];
	char str2[SIZE];
	int limit;
	char ch;
	printf("Enter a string(empty to quit):\n");
	while (s_gets(str2, SIZE) && str1[0] != '\0')
	{
		printf("Enter the number of characters to copy(no more than %d):", SIZE);
		while (scanf("%d", &limit) != 1)
			printf("Please enter an integer:");
		if (limit > SIZE)
			limit = SIZE;
		while (getchar() != '\n')
			continue;
		mystrncpy(str1, str2, limit);
		printf("The copied string is:\n%s\n", str1);
		printf("Enter a string(empty to quit):\n");
	}
	puts("Done.\n");

	return 0;
}

char * mystrncpy(char * st1, char * st2, int n)
{
	int i;
	char * start = st1;
	for (i = 0; i < n; i++)
		*(st1 + i) = *(st2 + i);
	*(st1 + i) = '\0';

	return start;
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