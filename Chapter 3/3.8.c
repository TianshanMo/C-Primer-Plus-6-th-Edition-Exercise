/* Programming Exercise 3-8 */
#include <stdio.h>
int main(void)
{
	float pints;
	float cups;
	float ounces;
	float tablespoons;
	float teaspoons;
	printf("Enter the number of cups:");
	scanf("%f", &cups);
	pints = cups * 2;
	ounces = cups / 8;
	tablespoons = ounces / 2;
	teaspoons = tablespoons / 3;
	printf("\n%f cups equals %f pants %f ounces %f tablespoons %f teaspoons\n", cups, pints, ounces, tablespoons, teaspoons);

	return 0;
}