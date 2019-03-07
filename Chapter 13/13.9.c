/* Programming Exercise 13-9 */
/* addaword.c -- uses fprintf(), fscanf(), and rewind() */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main(void)
{
	FILE *fp;
	char words[MAX];
	int count = 1;

	if ((fp = fopen("wordy", "a+")) == NULL)
	{
		fprintf(stdout, "Can't open \"wordy\" file.\n");
		exit(EXIT_FAILURE);
	}

	rewind(fp);
	while (fgets(words, MAX, fp) != NULL)
		count++;	// number of rows;
	rewind(fp);

	puts("Enter words to add to the file; press the #");
	puts("key at the beginning of a line to terminate.");
	while ((fscanf(stdin, "%40s", words) == 1) && (words[0] != '#'))
	{
		fprintf(fp, "%d.%s\n", count, words);
		count++;
	}

	puts("File contents:");
	rewind(fp);				/* go back to beginning of file */
	while (fscanf(fp, "%s", words) == 1)
		puts(words);
	puts("Done!");
	if (fclose(fp) != 0)
		fprintf(stderr, "Error closing file\n");

	return 0;
}