/* Programming Exercise 6-16 */
#include <stdio.h>
int main(void)
{
	float simple_interest = 100, compound_interest = 100;
	float investment_amount_s = 0, investment_amount_c = 0;
	int year = 0;
	while (simple_interest >= compound_interest)
	{
		simple_interest += 10.0f;
		compound_interest *= 1.05f;
		year++;
	}
	printf("After %d years, Daphne have $%.2f money, Deride have $%.2f money.\n", year, simple_interest, compound_interest);

	return 0;
}