/* Programming Exercise 12-4 */
#include <stdio.h>

int test(void);

int main(void)
{
	int i;
	printf("Test the number of times a function is called\n");
	printf("Enter the number of test(q to quit):");
	while (scanf("%d", &i) == 1)
	{
		if (i <= 0)
			break;
		for (int count = 0; count < i; count++)
			printf("test %d\n", test());
		printf("Enter the number of test(q to quit):");
	}

	return  0;
}

int test(void)
{
	static int count = 0;
	count++;
	return count;
}