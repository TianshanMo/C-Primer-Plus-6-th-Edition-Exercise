/* Programming Exercise 6-7 */
#include <stdio.h>
#include <string.h>
#define SIZE 20
int main(void)
{
	char letter[SIZE];
	int count;
	printf("Enter a word: ");
	scanf("%s", letter);
	for (count = strlen(letter) - 1; count >= 0; count--)
		printf("%c", letter[count]);
	printf("\n");

	return 0;
}