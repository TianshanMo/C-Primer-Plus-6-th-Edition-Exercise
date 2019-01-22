/* Programming Exercise 7-9 */
#include <stdio.h>
int main(void)
{
	int num, div;
	_Bool isPrime;
	int count;
	printf("To display all positive numbers less than or equal to a certain number,\n");
	printf("enter an integer greater than 1:\n");
	while (scanf("%d", &num) == 1)
	{
		if (num <= 1)
			printf("Invalid input, please re-enter:\n");
		else
			break;
	}
	printf("The prime numbers before %d are:\n", num);
	for (count = 2; count <= num; count++)
	{
		for (div = 2, isPrime = 1; (div * div) < count; div++)
		{
			if (count % div == 0)
				isPrime = 0;
		}
		if (isPrime)
			printf("%d ", count);
	}

	printf("\nDone\n");
	return 0;
}