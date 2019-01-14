/* Programming Exercise 3-7 */
#include <stdio.h>
int main(void)
{
	float inches;
	float centimeters;
	float convert_num;

	convert_num = 2.54f;
	printf("Enter the number of inches of tall:");
	scanf("%f", &inches);
	centimeters = inches * convert_num;
	printf("%f inches equals %0.8f centimeters.\n", inches, centimeters);

	return 0;
}