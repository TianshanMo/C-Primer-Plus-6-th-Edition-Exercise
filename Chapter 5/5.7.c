/* Programming Exercise 5-7 */
#include <stdio.h>
double cubed(double i);
int main(void)
{
	double number;
	printf("Enter a number to cube: \n");
	scanf("%lf", &number);

	printf("%.3lf cubed is %.3lf\n", number, cubed(number));

	return 0;
}

double cubed(double i)
{
	return i * i * i;
}