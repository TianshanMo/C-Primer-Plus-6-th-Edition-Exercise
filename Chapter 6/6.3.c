/* Programming Exercise 6-3 */
#include <stdio.h>
int main(void)
{
	int i, j;
	char alpha = 'F';
	for (i = 1; i < 7; alpha = 'F', i++)
	{
		for (j = 0; j < i; j++)
			printf("%c", alpha--);
		printf("\n");
	}


	return 0;
}