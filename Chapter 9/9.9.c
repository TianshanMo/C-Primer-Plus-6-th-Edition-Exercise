/* Programming Exercise 9 - 9 */
#include <stdio.h>
double power(double n, int p);	// ANSI prototype
int main(void)
{
	double x, xpow;
	int exp;

	printf("Enter a number and the positive integer power");
	printf(" to which\nthe number will be raised. Enter q");
	printf(" to quit.\n");
	while (scanf("%lf%d", &x, &exp) == 2)
	{
		xpow = power(x, exp);		// function call
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
		printf("Enter next pair of numbers or q to quit.\n");
	}
	printf("Hope you enjoyed this power trip -- bye!\n");

	return 0;
}

double power(double n, int p)	// function definition
{
	double pow;

	if (n == 0.0)
	{
		if (p == 0)
		{
			printf("The 0 power of 0 is undefined, so the value is treated as 1.\n");
			pow = 1;
		}
		else
			pow = 0;
	}
	if (p > 0 && n != 0)
		pow = power(n, p - 1) * n;
	else if (p < 0 && n != 0)
	{
		p = -p;
		pow = power(n, p - 1) * n;
		pow = 1 / pow;
	}
	else
		pow = 1;


	return pow;					// return the value of pow
}