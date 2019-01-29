/* Programming Exercise 9 - 11 */
#include <stdio.h>
unsigned long Fibonacci(unsigned n);

int main(void)
{
	int i;
	printf("Calculate the Fibonacci number.\n");
	printf("Enter an integer(q to quit):\n");
	while (scanf("%d", &i) == 1)
	{
		if (i < 1)
		{
			printf("Invalid input, please try again.\n");
			continue;
		}
		else
		{
			printf("The Fibonacci number is %lu.\n", Fibonacci(i));
			printf("Enter an integer(q to quit):\n");
		}
	}

	return 0;
}

unsigned long Fibonacci(unsigned n)
{
	unsigned i;
	unsigned long fi = 2;
	unsigned long f1 = 1;
	unsigned long f2 = 1;
	if (n == 1)
		fi = 1;
	else if (n == 2)
		fi = 1;
	else
		for (i = 3; i < n; i++)
		{
			f1 = f2;
			f2 = fi;
			fi = f1 + f2;
		}

	return fi;
}