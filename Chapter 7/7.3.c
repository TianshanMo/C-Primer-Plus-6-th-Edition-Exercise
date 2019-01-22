/* Programming Exercise 7-3 */
#include <stdio.h>
int main(void)
{
	int num;
	int even_count = 0, odd_count = 0;
	int even_sum = 0, odd_sum = 0;
	printf("Please enter the unsigned integer(0 to quit):\n");
	scanf("%d", &num);
	while (num)
	{
		if (num % 2 == 0)
		{
			even_count++;
			even_sum += num;
		}
		if (num % 2 == 1)
		{
			odd_count++;
			odd_sum += num;
		}
		scanf("%d", &num);
	}
	printf("Even number count:%-3d, Even number average:%-3.2f\n",
		even_count, (float)even_sum / (float)even_count);
	printf("Odd number count:%-3d, Odd number average:%-3.2f\n",
		odd_count, (float)odd_sum / (float)odd_count);

	return 0;
}