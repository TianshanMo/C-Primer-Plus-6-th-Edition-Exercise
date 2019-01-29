/* Programming Exercise 9 - 4 */
#include <stdio.h>
double HarmonicMean(double a, double b);

int main(void)
{
	double num1, num2;
	printf("Calculate the harmonic mean of two numbers.\n");
	printf("Enter two numbers (q to quit):\n");
	while (scanf("%lf %lf", &num1, &num2) == 2)
	{
		printf("The harmonic mean of these two numbers is %.2lf\n",
			HarmonicMean(num1, num2));
		printf("Enter two numbers (q to quit):\n");
	}
	
	return 0;
}

double HarmonicMean(double a, double b)
{
	double hm;
	hm = 2.0 / (1.0 / a + 1.0 / b);
	return hm;
}