/* Programming Exercise 7-11 */
#include <stdio.h>
#define ARTICHOKE 2.05
#define BEET 1.15
#define CARROT 1.09

#define DISCOUNT 0.05

#define FIRST_FREIGHT 6.5
#define SECOND_FREIGHT 14.0
#define CONTINUE_FREIGHT 0.5
int main(void)
{
	float weight;
	float Artichoke_Weight = 0;
	float Beet_Weight = 0;
	float Carrot_Weight = 0;
	float totalWeight;
	float Artichoke_Price;
	float Beet_Price;
	float Carrot_Price;
	float basicPrice;
	float freight;
	float totalPrice;

	char choice;
	int status = 0;
	while (1)
	{
		printf("****************************\n");
		printf("What do you want to order?\n");
		printf("a: artichoke  b: beet\n");
		printf("c: carrot     q: quit\n");
		printf("****************************\n");
		scanf("%c%*c", &choice);					// %*c to get 'enter' character
		switch (choice)
		{
		case 'a':
			printf("Enter the weight of the artichoke to be added:\n");
			if (scanf("%f%*c", &weight) == 1)		// %*c to get 'enter' character
				Artichoke_Weight += weight;
			else
			{
				printf("Incorrect input, please re-enter:\n");
				while (getchar() != '\n')
					;
				continue;
			}
			break;
		case 'b':
			printf("Enter the weight of the beet to be added:\n");
			if (scanf("%f%*c", &weight) == 1)		// %*c to get 'enter' character
				Beet_Weight += weight;
			else
			{
				printf("Incorrect input, please re-enter:\n");
				while (getchar() != '\n')
					;
				continue;
			}
			break;
		case 'c':
			printf("Enter the weight of the carrot to be added:\n");
			if (scanf("%f%*c", &weight) == 1)		// %*c to get 'enter' character
				Carrot_Weight += weight;
			else
			{
				printf("Incorrect input, please re-enter:\n");
				while (getchar() != '\n')
					;
				continue;
			}
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

		Artichoke_Price = Artichoke_Weight * ARTICHOKE;
		Beet_Price = Beet_Weight * BEET;
		Carrot_Price = Carrot_Weight * CARROT;
		basicPrice = Artichoke_Price + Beet_Price + Carrot_Price;

		if (basicPrice >= 100)
			basicPrice *= DISCOUNT;

		totalWeight = Artichoke_Weight + Beet_Weight + Carrot_Weight;
		if (totalWeight <= 5)
			freight = FIRST_FREIGHT;
		else if (totalWeight <= 20)
			freight = SECOND_FREIGHT;
		else
			freight = 20.0 * SECOND_FREIGHT + totalWeight * CONTINUE_FREIGHT;

		totalPrice = basicPrice + freight;


		printf("------Unit price:------\n");
		printf("artichoke : %.2f per pound\n", ARTICHOKE);
		printf("beet : %.2f per pound\n", BEET);
		printf("carrot : %.2f per pound\n", CARROT);
		printf("------Your order:------\n");
		printf("%.2f pounds of artichokes for a total of $%.2f.\n", Artichoke_Weight, Artichoke_Price);
		printf("%.2f pounds of beets for a total of $%.2f.\n", Beet_Weight, Beet_Price);
		printf("%.2f pounds of carrots for a total of $%.2f.\n", Carrot_Weight, Carrot_Price);
		printf("Subtotal: $%.2f\n", basicPrice);
		printf("freight: $%.2f\n", freight);
		printf("Total Price: $%.2f\n\n", totalPrice);

	}
	printf("Done\n");

	return 0;
}