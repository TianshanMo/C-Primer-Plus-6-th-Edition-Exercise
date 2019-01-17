/* Programming Exercise 4-3 */
#include <stdio.h>
int main(void)
{
	float number;
	printf("Enter a float number:");
	scanf("%f", &number);
	printf("a.The input is %-10.1f %-10.1e\n", number, number);
	printf("b.The input is %-+10.3f %-10.3e\n", number, number);

	return 0;
}