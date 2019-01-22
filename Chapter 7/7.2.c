/* Programming Exercise 7-2 */
#include <stdio.h>
int main(void)
{
	char ch;
	int i = 0;
	printf("Enter the input:\n");
	while ((ch = getchar()) != '#')
	{
		if (ch == '\n')
			continue;
		printf("'%c':%3d ", ch, ch);
		i++;
		if (i % 8 == 0)
			printf("\n");
	}

	return 0;
}