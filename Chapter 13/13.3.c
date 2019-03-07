/* Programming Exercise 13-3 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 256

char * s_gets(char *st, int n);

int main(void)
{
	FILE *source;
	FILE *target;
	char sname[MAX];
	char tname[MAX];
	int ch;
	printf("Enter source file name:\n");
	s_gets(sname, MAX);

	if ((source = fopen(sname, "r")) == NULL)
	{
		printf("Can't open the source file.\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter target the file name:\n");
	s_gets(tname, MAX);
	if ((target = fopen(tname, "w")) == NULL)
	{
		printf("Can't open target file.\n");
		exit(EXIT_FAILURE);
	}

	if (strcmp(sname, tname) == 0)
	{
		printf("source file and target file cannot have the same name.");
		exit(EXIT_FAILURE);
	}

	while ((ch = getc(source)) != EOF)
	{
		if (islower(ch))
			ch = toupper(ch);
		putc(ch, target);
	}

	if (fclose(source) != 0 || fclose(target) != 0)
		fprintf(stderr, "Error in closing files.\n");
	printf("The file is copied.\n");

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