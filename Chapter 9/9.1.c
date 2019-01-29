/* Programming Exercise 9-1 */
#include <stdio.h>
double min(double a, double b);

int main(void)
{
	double x, y;

	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("The smaller number is %f.\n", min(x, y));
		printf("Next two values (q to quit): ");
	}

	return 0;
}

double min(double a, double b)
{
	return a < b ? a : b;
}