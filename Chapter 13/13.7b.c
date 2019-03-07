/* Programming Exercise 13-7a */
#include <stdio.h>
#include <stdlib.h>
#define MAX 256
char * s_gets(char *st, int n);

int main(void)
{
	FILE *fp1, *fp2;
	char file1[MAX];
	char file2[MAX];
	int ch1, ch2;
	printf("Enter name of file1:\n");
	s_gets(file1, MAX);
	if ((fp1 = fopen(file1, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n",
			file1);
		exit(EXIT_FAILURE);
	}
	printf("Enter name of file1:\n");
	s_gets(file2, MAX);
	if ((fp2 = fopen(file2, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n",
			file2);
		exit(EXIT_FAILURE);
	}
	ch1 = getc(fp1);
	ungetc(ch1, fp1);
	ch2 = getc(fp2);
	ungetc(ch2, fp2);

	while (ch1 != EOF || ch2 != EOF)
	{
		while ((ch1 = getc(fp1)) != '\n' && (ch1 != EOF))
			putchar(ch1);
		if (ch1 != EOF)
			putchar('\n');
		while ((ch2 = getc(fp2)) != '\n' && (ch2 != EOF))
			putchar(ch2);
		if (ch2 != EOF)
			putchar('\n');
	}
	if (fclose(fp1) != 0 || fclose(fp2) != 0)
		fprintf(stderr, "Error in closing files\n");

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