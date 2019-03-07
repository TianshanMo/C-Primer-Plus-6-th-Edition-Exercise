/* Programming Exercise 13-10 */
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
char * s_gets(char *st, int n);

int main(void)
{
	FILE *fp;
	char name[MAX];
	long position, set;
	int ch;
	printf("Enter a file name:\n");
	s_gets(name, MAX);
	if ((fp = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n",
			name);
		exit(EXIT_FAILURE);
	}
	printf("Zero is the first position\n");
	printf("Enter a position, q to quit:\n");
	while (scanf("%ld", &position) == 1)
	{
		if (position < 0)
			break;
		fseek(fp, position, SEEK_SET);
		while ((ch = getc(fp)) != EOF && (ch != '\n'))
			putchar(ch);
		printf("\nEnter a position, q to quit:\n");
	}
	printf("\nDone.\n");

	return 0;
}

char * s_gets(char *st, int n)
{
	char * ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}