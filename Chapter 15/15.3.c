/* Programming Exercise 15-3 */
#include <stdio.h>
#include <stdlib.h>
int onbits(int num);
int main(void)
{
	int bitcount;
	int num;
	printf("Enter an integer:\n");
	while (scanf("%d", &num) == 1)
	{
		bitcount = onbits(num);
		printf("The number of \"on\" bit in the %d is %d.\n", num, onbits(num));
		printf("Enter an integer (q to quit):\n");
	}

	return 0;
}

int onbits(int num)
{
	int count = 0;
	while (num != 0)
	{
		if (num & 1)
			count++;
		num >>= 1;
	}

	return count;
}