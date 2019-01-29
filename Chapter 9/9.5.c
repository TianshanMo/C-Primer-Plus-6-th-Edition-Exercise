/* Programming Exercise 9 - 5 */
#include <stdio.h>
void larger_of(double * a, double * b);

int main(void)
{
	double x, y;
	printf("Replaces the contents of two double variables"
		"\nwith the maximum of two values.\n");
	printf("Enter two numbers (q to quit):\n");
	while (scanf("%lf %lf", &x, &y) == 2)
	{
		printf("Originally x = %.2lf and y = %.2lf\n", x, y);
		larger_of(&x, &y);
		printf("Replacing...\n");
		printf("Now x = %.2lf, y = %.2lf\n", x, y);
		printf("Enter two numbers (q to quit):\n");
	}

	return 0;
}

void larger_of(double * a, double * b)
{
	if (*a < *b)
		*a = *b;
	else
		*b = *a;
}