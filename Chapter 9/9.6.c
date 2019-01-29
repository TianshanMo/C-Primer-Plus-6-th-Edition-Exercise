/* Programming Exercise 9 - 6 */
#include <stdio.h>

void sort(double * a, double * b, double *c);

int main(void)
{
	double x, y, z;
	printf("Sort the three numbers.\n");
	printf("Enter three numbers (q to quit):\n");
	while (scanf("%lf %lf %lf", &x, &y, &z) == 3)
	{
		printf("Originally x = %.2lf and y = %.2lf and c = %.2lf\n", x, y, z);
		sort(&x, &y, &z);
		printf("Sorting...\n");
		printf("Now x = %.2lf, y = %.2lf, z = %.2lf\n", x, y, z);
		printf("Enter three numbers (q to quit):\n");
	}

	return 0;
}

void sort(double * a, double * b, double *c)
{
	double temp;
	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
		if (*a > *b)
		{
			temp = *a;
			*a = *b;
			*b = temp;
		}
	}
}