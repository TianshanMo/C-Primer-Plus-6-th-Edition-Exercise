/* Programming Exercise 7-10 */
#include <stdio.h>
#define SINGLE 17850
#define HOUSEHOLD 23900
#define MARRIED_JOINT 29750
#define MARRIED_SEPARATE 14875
#define FIRST 0.15
#define PLUS 0.28
int main(void)
{
	float income;
	float tax;
	float type;
	int choice;
	int status = 0;
	while (1)
	{
		printf("******************************************\n");
		printf("Enter the type of tax payment\n");
		printf("1) Single            2) Head of Household\n");
		printf("3) Married, Joint    4) Married, Separate\n");
		printf("5) quit\n");
		printf("******************************************\n");
		scanf("%d", &choice);
		printf("Your choice is %d.\n", choice);
		switch (choice)
		{
		case 1:
			type = SINGLE;
			break;
		case 2:
			type = HOUSEHOLD;
			break;
		case 3:
			type = MARRIED_JOINT;
			break;
		case 4:
			type = MARRIED_SEPARATE;
			break;
		case 5:
			status = 1;		// quit
			break;
		default:
			printf("%d is an incorrect input\n", choice), status = 2;	// reelect
			break;
		}
		if (status == 1)	// quit program
			break;
		if (status == 2)	// reelect
		{
			status = 0;
			continue;
		}

		printf("Enter taxable income: \n");
		while (scanf("%f", &income) == 1)	// Determine if the time is entered correctly
		{
			if (income <= 0)
			{
				printf("%.2f is an incorrect input, please re-enter: \n", income);
				continue;
			}
			else
				break;
		}
		if (income <= type)
			tax = income * FIRST;
		else
			tax = type * FIRST + (income - type) * PLUS;
		printf("The tax is %.2f\n", tax);
	}
	printf("Done\n");

	return 0;
}