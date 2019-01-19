/* Programming Exercise 6-12 */
#include <stdio.h>
int main(void)
{
	unsigned long infinite, count;
	double sum1 = 0, sum2 = 0, sign = 1.0f;
	printf("Enter a number of terms to sum: ");
	scanf("%lu", &infinite);
	for (count = 1; count <= infinite; count++)
	{
		sum1 += 1.0f / count;
		sum2 += (1.0f / count) * sign;
		sign = -sign;
	}
	printf("The %luth partial sum for sum 1 is: %.5lf\n", infinite, sum1);
	printf("The %luth partial sum for sum 2 is: %.5lf\n", infinite, sum2);

	return 0;
}