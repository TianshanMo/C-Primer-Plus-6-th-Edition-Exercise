/* Programming Exercise 11-16 */
#include <stdio.h>
#include <ctype.h>
void PrintOriginal(void);
void MapUppercase(void);
void MapLowercase(void);

int main(int argc, char *argv[])
{
	if (argc != 2 || (argv[1][0] != '-') || (argv[1][2] != '\0'))
		printf("Usage: %s [ -p | -u | -l ]", argv[0]);
	else
		switch (argv[1][1])
		{
		case 'p':PrintOriginal();
			break;
		case 'u':MapUppercase();
			break;
		case 'l':MapLowercase();
			break;
		default:printf("Usage: %s [ -p | -u | -l ]", argv[0]);
			break;
		}

	return 0;
}

void PrintOriginal(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
		putchar(ch);
}
void MapUppercase(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
		putchar(toupper(ch));
}
void MapLowercase(void)
{
	char ch;
	while ((ch = getchar()) != EOF)
		putchar(tolower(ch));
}