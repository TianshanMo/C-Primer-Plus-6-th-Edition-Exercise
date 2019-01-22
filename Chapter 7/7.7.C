/* Programming Exercise 7-7 */
#include <stdio.h>
#define BASIC_PAY_RATE 10.0
/*	The Chinese version of the textbook is incorrece here
	and should be $10 per hour							*/
#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLE 1.5
#define TAX_RATE_1 0.15
#define TAX_BRACKET_1 300.0
#define TAX_RATE_2 0.20
#define TAX_BRACKET_2 450.0
#define TAX_RATE_3 0.25
int main(void)
{
	float hours;
	float taxes;
	float income;
	float net_income;

	printf("Enter the number of hours worked this week: ");
	scanf("%f", &hours);
	if (hours <= OVERTIME_HOURS)
		income = hours * BASIC_PAY_RATE;
	else
		income = OVERTIME_HOURS * BASIC_PAY_RATE +
			(hours - OVERTIME_HOURS) * OVERTIME_MULTIPLE * BASIC_PAY_RATE;
	if (income <= TAX_BRACKET_1)
		taxes = income * TAX_RATE_1;
	else if (income <= TAX_BRACKET_2)
		taxes = TAX_BRACKET_1 * TAX_RATE_1 + (income - TAX_BRACKET_1) * TAX_RATE_2;
	else
		taxes = TAX_BRACKET_1 * TAX_RATE_1 + (TAX_BRACKET_2 - TAX_BRACKET_1) * TAX_RATE_2
			+ (income - TAX_BRACKET_2) * TAX_RATE_3;
	net_income = income - taxes;
	printf("You have worked for %.1f hours, with a\n", hours);
	printf("total income of $%.2f,\n", income);
	printf("a tax of $%.2f\n", taxes);
	printf("and a net income of $%.2f.\n", net_income);

	return 0;
}