/* Programming Exercise 6-9 */
#include <stdio.h>

float calculate(float n1, float n2);

int main(void)
{
	float num1, num2;
	printf("Enter two floating-point numbers, q to quit: \n");
	while ((scanf(" %f %f", &num1, &num2)) == 2)
	{
		printf("(%.2f - %.2f ) / (%.2f * %.2f) = %.2f\n", num1, num2, num1, num2, calculate(num1, num2));
		printf("Enter two floating-point numbers, q to quit: \n");
	}
	
	return 0;
}

float calculate(float n1, float n2)
{
	return (n1 - n2) / (n1 * n2);
}