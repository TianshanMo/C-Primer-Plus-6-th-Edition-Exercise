/* Programming Exercise 15-4 */
#include <stdio.h>
_Bool bitval(int val, int position);

int main(void)
{
	int val, position;

	printf("Enter a value: \n");
	while (scanf("%d", &val) == 1)
	{
		printf("Enter a position: \n");
		while (scanf("%d", &position) == 1)
		{
			printf("That particular bit position is %d.\n", bitval(val, position));
			printf("Enter a position (q to quit): \n");
		}
	}
}

_Bool bitval(int val, int position)
{
	val >>= (position - 1);
	if (val & 1)
		return 1;
	else
		return 0;
}