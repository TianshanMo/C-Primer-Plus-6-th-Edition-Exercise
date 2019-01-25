/* Programming Exercise 8-8 */
#include <stdio.h>

char get_choice(void);
float get_number(void);

int main(void)
{
	char choice;
	int status = 0;
	float num1, num2;

	while (1)
	{
		printf("Enter the operation of your choice:\n");
		printf("a. add          s. subtract\n");
		printf("m. multiply     d.divide\n");
		printf("q. quit\n");
		choice = get_choice();

		switch (choice)
		{
		case 'a':
			printf("Enter first number:");
			num1 = get_number();
			printf("Enter second number:");
			num2 = get_number();
			printf("%.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
			break;
		case 's':
			printf("Enter first number:");
			num1 = get_number();
			printf("Enter second number:");
			num2 = get_number();
			printf("%.2f - %.2f = %.2f\n", num1, num2, num1 - num2);
			break;
		case 'm':
			printf("Enter first number:");
			num1 = get_number();
			printf("Enter second number:");
			num2 = get_number();
			printf("%.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
			break;
		case 'd':
			printf("Enter first number:");
			num1 = get_number();
			printf("Enter second number:");
			num2 = get_number();
			while (num2 == 0)
			{
				printf("Enter a number other than 0: ");
				num2 = get_number();
			}
			printf("%.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
			break;
		case 'q':
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
	}
	printf("Bye.\n");

	return 0;
}

char get_choice(void)
{
	int ch;

	ch = getchar();
	while (getchar() != '\n')
		continue;

	return ch;
}

float get_number(void)
{
	float num;
	int ch;
	while (scanf("%f", &num) != 1)
	{
		while ((ch = getchar()) != '\n')
			putchar(ch);
		printf(" is not an number.\n");
		printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
	}
	while (getchar() != '\n')
		continue;

	return num;
}