/* Programming Exercise 13-12 */

/* test data: 
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 2 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 5 2 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 1 9 8 5 4 5 2 0 0 0 0 0 0 0 0 0
0 0 0 0 9 0 0 0 0 0 0 0 5 8 9 9 8 5 0 4 5 2 0 0 0 0 0 0 0 0
0 0 9 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 4 5 2 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 1 8 5 0 0 0 4 5 2 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 4 5 2 0 0 0 0 0
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
9 9 9 9 0 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 9 3 9 9 9 9 9 9 9
8 8 8 8 8 8 8 8 8 8 8 8 5 8 9 9 8 5 8 8 8 8 8 8 8 8 8 8 8 8
5 5 5 5 5 5 5 5 5 5 5 5 5 8 9 9 8 5 5 5 5 5 5 5 5 5 5 5 5 5 
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 2 2 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 3 3 0 0 0 0 0 0 5 8 9 9 8 5 0 5 6 1 1 1 1 6 5 0 0 0
0 0 0 0 4 4 0 0 0 0 0 0 5 8 9 9 8 5 0 0 5 6 0 0 6 5 0 0 0 0
0 0 0 0 5 5 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 6 6 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 5 8 9 9 8 5 0 0 0 0 0 0 0 0 0 0 0 0
*/
#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS 30

char * s_gets(char *st, int n);

int main(void)
{
	FILE *fp1, *fp2;
	char sname[256];
	char tname[256];
	int image[ROWS][COLS];
	printf("Enter source file name:\n");
	s_gets(sname, 256);
	printf("Enter target file name:\n");
	s_gets(tname, 256);
	if ((fp1 = fopen(sname, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", sname);
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen(tname, "w")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", tname);
		exit(EXIT_FAILURE);
	}
	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS; col++)
			if (fscanf(fp1, "%d", &image[row][col]) != 1)
			{
				fprintf(stderr, "Data loading failed.\n");
				exit(EXIT_FAILURE);
			}
	fclose(fp1);

	for (int row = 0; row < ROWS; row++)
	{
		for (int col = 0; col < COLS; col++)
		{
			switch (image[row][col])
			{
			case 0: putchar(' ');
				fputc(' ', fp2);
				break;
			case 1: putchar('.');
				fputc('.', fp2);
				break;
			case 2: putchar('\'');
				fputc('\'', fp2);
				break;
			case 3: putchar(':');
				fputc(':', fp2);
				break;
			case 4: putchar('~');
				fputc('~', fp2);
				break;
			case 5: putchar('*');
				fputc('*', fp2);
				break;
			case 6: putchar('=');
				fputc('=', fp2);
				break;
			case 7: putchar('$');
				fputc('$', fp2);
				break;
			case 8: putchar('%');
				fputc('%', fp2);
				break;
			case 9: putchar('#');
				fputc('#', fp2);
				break;
			default:
				break;
			}
		}
		putchar('\n');
		fputc('\n', fp2);
		fputc('\0', fp2);
	}
	fclose(fp2);
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