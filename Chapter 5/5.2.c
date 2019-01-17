/* Programming Exercise 5-2 */
#include <stdio.h>
int main(void)
{
	int number;
	int count = 0;
	printf("Enter an integer number:");
	scanf("%d", &number);
	while (count <= 10)
	{
		printf("%d\t", number);
		number = number + 1;
		count++;
	}
	
	return 0;
}