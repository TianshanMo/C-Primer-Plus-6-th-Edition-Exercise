/* Programming Exercise 13-11 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 256

int main(int argc, char *argv[])
{
	FILE *fp;
	char find[MAX];
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s [string] [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	while (fgets(find, MAX, fp) != NULL)
	{
		if (strstr(find, argv[1]) != NULL)
			fputs(find, stdout);
	}
	fclose(fp);

	return 0;
}