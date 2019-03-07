/* Programming Exercise 13-8 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	int ch;
	if (argc == 1 || argv[1][1] != '\0')
	{
		printf("Usage: %s [char] [filename]...\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
	{
		printf("Enter a string, EOF to quit:\n");
		int count = 0;
		while ((ch = getchar()) != EOF)
		{
			if (ch == argv[1][0])
				count++;
		}
		printf("There are a total of %d characters '%c'.\n", count, argv[1][0]);
	}
	else
	{
		ch = argv[1][0];
		char match;
		for (int i = 2; i < argc; i++)
		{
			int count = 0;
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "Can't open \"%s\" file.\n", argv[i]);
				continue;
			}
			while ((match = getc(fp)) != EOF)
				if (match == ch)
					count++;
			printf("The character '%c' appears %d times in the file %s\n",
				ch, count, argv[i]);
			fclose(fp);
		}
	}

	return 0;
}