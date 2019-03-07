/* Programming Exercise 13-6 */
// reducto.c -- reduces your files by two-thirds!
#include <stdio.h>
#include <stdlib.h>		// for exit()
#include <string.h>
#define LEN 40
char * s_gets(char *st, int n);

int main(void)
{
	FILE *in, *out;		// declare two file pointers
	int ch;
	char name[LEN];		// storage for input filename
	char oname[LEN];	// storage for output filename
	int count = 0;

	printf("Enter source file name:\n");
	s_gets(name, LEN);

	// set up intput
	if ((in = fopen(name, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n",
			name);
		exit(EXIT_FAILURE);
	}
	// set up output
	strcpy(oname, name);	// copy filename
	strcat(oname, ".red");				// append.red
	if ((out = fopen(oname, "w")) == NULL)
	{						// open file for writing
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	// copy data
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out);	// print every 3rd char
	// clean up
	if (fclose(in) != 0 || fclose(out) != 0)
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