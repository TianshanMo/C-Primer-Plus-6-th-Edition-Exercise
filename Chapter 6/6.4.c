/* Programming Exercise 6-4 */
#include <stdio.h>
int main(void)
{
	int i, j;
	char alpha = 'A';
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
			printf("%c", alpha++);
		printf("\n");
	}


	return 0;
}