/* Programming Exercise 5-7							*/
/* this implementation assumes the character codes	*/
/* are sequential, as they are in ASCII.			*/
#include <stdio.h>
#define SIZE 26
int main(void)
{
	char alphabet[SIZE];
	int i;
	for (i = 0; i < SIZE; i++)
		alphabet[i] = 'a' + i;
	for (i = 0; i < SIZE; i++)
		printf("%c", alphabet[i]);

	return 0;
}