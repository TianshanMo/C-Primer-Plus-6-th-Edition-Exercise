/* Programming Exercise 6-10 */
#include <stdio.h>
int main(void)
{
	int lower_limit, upper_limit;
	int num, square, sum;
	printf("Enter lower and upper integer limits: ");
	scanf("%d%d", &lower_limit, &upper_limit);
	while (lower_limit < upper_limit)
	{
		for (num = lower_limit, sum = 0; num <= upper_limit; num++)
		{
			square = num * num;
			sum += square;
		}
		printf("The sums of the square  from %d to %d is %d\n", lower_limit * lower_limit, square, sum);
		printf("Enter next set of limits: ");
		scanf("%d%d", &lower_limit, &upper_limit);
	}
	printf("Done\n");

	return 0;


}
