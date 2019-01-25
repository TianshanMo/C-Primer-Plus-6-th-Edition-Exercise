/* Programming Exercise 8-7 */
#include <stdio.h>

#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLE 1.5
#define TAX_RATE_1 0.15
#define TAX_BRACKET_1 300.0
#define TAX_RATE_2 0.20
#define TAX_BRACKET_2 450.0
#define TAX_RATE_3 0.25
#define SALARY_LEVEL_1 8.75
#define SALARY_LEVEL_2 9.33
#define SALARY_LEVEL_3 10.00
#define SALARY_LEVEL_4 11.20
char get_first(void);
int main(void)
{
	float hours;
	float taxes;
	float income;
	float net_income;
	float basic_pay;
	char choice;
	int status = 0;
	while (1)
	{
		printf("*****************************************************************\n");
		printf("Enter the number corresponding to the desired pay rate or action:\n");
		printf("1) $8.75/hr                         2) $9.33/hr\n");
		printf("3) $10.00/hr                        4) $11.20/hr\n");
		printf("5) quit\n");
		printf("*****************************************************************\n");
		choice = get_first();
		printf("Your choice is %c.\n", choice);
		switch (choice)
		{
		case '1':
			basic_pay = SALARY_LEVEL_1;
			break;
		case '2':
			basic_pay = SALARY_LEVEL_2;
			break;
		case '3':
			basic_pay = SALARY_LEVEL_3;
			break;
		case '4':
			basic_pay = SALARY_LEVEL_4;
			break;
		case '5':
			status = 1;		// quit
			break;
		default:
			printf("%c is an incorrect input\n", choice), status = 2;	// reelect
			break;
		}
		if (status == 1)	// quit program
			break;
		if (status == 2)	// reelect
		{
			status = 0;
			continue;
		}


		printf("Enter the number of hours worked this week: ");
		while (scanf("%f", &hours) == 1)	// Determine if the time is entered correctly
		{
			if (hours <= 0)
			{
				printf("%.2f is an incorrect input, please re-enter: \n", hours);
				continue;
			}
			else
				break;
		}

		if (hours <= OVERTIME_HOURS)
			income = hours * basic_pay;
		else
			income = OVERTIME_HOURS * basic_pay +
			(hours - OVERTIME_HOURS) * OVERTIME_MULTIPLE * basic_pay;
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
		printf("and a net income of $%.2f.\n\n", net_income);
	}
	printf("Done\n");

	return 0;
}
char get_first(void)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}