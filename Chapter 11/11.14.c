/* Programming Exercise 11-14 */
#include <stdio.h>
double power(double n, int p);

int main(int argc, char *argv[])
{
	int i;
	double x, xpow;
	int exp;

	if (argc != 3)
		printf("Usage:[PROGRAMNAME][DOUBLE][INTEGER]");
	else
	{
		x = atof(argv[1]);
		exp = atoi(argv[2]);
		xpow = power(x, exp);
		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
	}

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