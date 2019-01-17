/* Programming Exercise 4-8 */
#include <stdio.h>
#define G2L 3.785		// 1 gallon is approximately equal to 3.785 liters
#define M2K 1.609		// 1 mile is approximately equal to 1.609 kilometers
int main(void)
{
	float mileage;
	float gasoline_amount;
	float mile;
	float kilometer;
	float liter;
	printf("Enter the milage:");
	scanf("%f", &mileage);
	printf("Enter the gasoline amount:");
	scanf("%f", &gasoline_amount);
	mile = mileage / gasoline_amount;
	printf("%.1f miles per gallon of gasoline.\n", mile);
	liter = 100.0 / mile * G2L / M2K;
	printf("%.1f liters per 100 kilometers.\n", liter);

	return 0;
}