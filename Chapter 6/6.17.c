/* Programming Exercise 6-17 */
#include <stdio.h>
#define INTEREST 0.08f
int main(void)
{
	float captial = 1000000.0;
	int years = 0;
	while (captial >= 0)
	{
		captial -= 100000.0;
		captial *= (1.0 + INTEREST);
		years++;
	}
	printf("After %d years, Chuckie Lucky will have withdrawed all his money, and balance are $%.2f.\n", years, captial);

	return 0;
}