/* Programming Exercise 6-5 */
#include <stdio.h>
int main(void)
{
	char letter;
	char ch1, ch2;
	int i,j;

	do
	{
		printf("Enter a letter:");
		scanf("%c", &letter);
	} while (letter < 'A' || letter > 'Z');

	for (ch1 = 'A'; ch1 <= letter; ch1++)		// Processing line
	{
		for (i = 0; i < letter - ch1; i++)		// Fill in spaces
			printf(" ");
		for (ch2 = 'A'; ch2 <= ch1; ch2++)		// Ascending
			printf("%c", ch2);
		for (; ch2 - 1 > 'A'; ch2--)			// Descending
			printf("%c", ch2);
		for (i = 0; i < letter - ch1; i++)
			printf(" ");
		printf("\n");
	}

	return 0;
}