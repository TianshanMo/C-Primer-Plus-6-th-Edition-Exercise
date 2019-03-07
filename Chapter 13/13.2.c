/* Programming Exercise 13-2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *source;
	FILE *target;
	int ch;
	if (argc != 3)
	{
		printf("Usage: %s [sourcefile] [targetfile].\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if (strcmp(argv[1], argv[2]) == 0)
	{
		printf("source file and target file cannot have the same name.");
		exit(EXIT_FAILURE);
	}
	if ((source = fopen(argv[1], "rb")) == NULL)
	{
		printf("Can't open the source file.\n");
		exit(EXIT_FAILURE);
	}
	if ((target = fopen(argv[2], "wb")) == NULL)
	{
		printf("Can't open the target file.\n");
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(source)) != EOF)
		putc(ch, target);
	if (fclose(source) != 0 || fclose(target) != 0)
		fprintf(stderr, "Error in closing files.\n");

	printf("The file is copied.\n");
	
	return 0;
}