/* Programming Exercise 14-11 */
#include <stdio.h>
#include <math.h>
#define SIZE 100
void transform(const double * source, double * target, int n, double (*pf)(double));
double square(double num);
double Double(double num);

int main(void)
{
	double source[SIZE];
	double target[SIZE];
	for (int i = 0; i < SIZE; i++)
		source[i] = i;

	printf("test sin:\n");
	transform(source, target, SIZE, sin);
	printf(" source    target:\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("|%.2f      |%-3.2f", source[i], target[i]);
		if (i % 1 == 0)
			putchar('\n');
	}

	printf("test cos:\n");
	transform(source, target, SIZE, cos);
	for (int i = 0; i < SIZE; i++)
	{
		printf("|%.2f      |%-3.2f", source[i], target[i]);
		if (i % 1 == 0)
			putchar('\n');
	}

	printf("test square:\n");
	transform(source, target, SIZE, square);
	for (int i = 0; i < SIZE; i++)
	{
		printf("|%.2f      |%-3.2f", source[i], target[i]);
		if (i % 1 == 0)
			putchar('\n');
	}

	printf("test double:\n");
	transform(source, target, SIZE, Double);
	for (int i = 0; i < SIZE; i++)
	{
		printf("|%.2f      |%-3.2f", source[i], target[i]);
		if (i % 1 == 0)
			putchar('\n');
	}
	
	return 0;
}

void transform(const double * source, double * target, int n, double(*pf)(double))
{
	for (int i = 0; i < n; i++)
		target[i] = pf(source[i]);
}

double square(double num)
{
	return num * num;
}

double Double(double num)
{
	return num * 2;
}