/* Programming Exercise 13-1 */
/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h>	// exit() prototype
#define MAX 256

int main(void)
{
	int ch;			// place to store each character as read
	FILE *fp;		// "file pointer"
	unsigned long count = 0;
	char name[MAX];
	int i = 0;
	printf("Enter a file name:\n");
	fgets(name, MAX, stdin);
	while (name[i] != '\n')
		i++;
	name[i] = '\0';

	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("Can't open %s\n", name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);	// same as putchar(ch);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", name, count);

	return 0;
}