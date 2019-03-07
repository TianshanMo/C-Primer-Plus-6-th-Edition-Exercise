/* Programming Exercise 13-4 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	int ch;
	FILE * fp;
	if (argc == 1)
	{
		printf("Usage: %s filename.\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	for (int i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open \"%s\" file.\n", argv[0]);
			continue;
		}
		while ((ch = getc(fp)) != EOF)
			putchar(ch);
		if (fclose(fp) != 0)
		{
			fprintf(stderr, "Can't close \"%s\" file.\n", argv[0]);
			continue;
		}
	}
	
	return 0;
}