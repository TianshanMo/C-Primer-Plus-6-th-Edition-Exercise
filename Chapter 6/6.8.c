/* Programming Exercise 6-8 */
#include <stdio.h>
int main(void)
{
	float num1, num2;
	printf("Enter two floating-point numbers, q to quit: \n");
	while ((scanf(" %f %f", &num1, &num2)) == 2)
	{
		printf("(%.2f - %.2f ) / (%.2f * %.2f) = %.2f\n", num1, num2, num1, num2, (num1 - num2) / (num1*num2));
		printf("Enter two floating-point numbers, q to quit: \n");
	}

	return 0;
}