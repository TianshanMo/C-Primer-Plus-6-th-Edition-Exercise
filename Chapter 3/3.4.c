/* Programming Exercise 3-4 */
#include <stdio.h>
int main(void)
{
	float float_point;
	printf("Enter a floating-point value:");
	scanf("%f", &float_point);
	printf("\nfixed-point notation: %f\n", float_point);
	printf("exponential notation: %e\n", float_point);
	printf("p notation: %a\n", float_point);

	return 0;
}