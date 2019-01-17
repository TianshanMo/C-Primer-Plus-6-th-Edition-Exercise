/* Programming Exercise 5-6 */
#include <stdio.h>
int main(void)
{
	int count, sum, i;
	printf("Enter the upper limit:");
	scanf("%d", &count);
	while (count > 0)
	{
		i = 0;
		sum = 0;
		while (i++ < count)
			sum = sum + i * i;
		printf("sum = %d\n", sum);
		printf("Enter the upper limit (0 to exit):");
		scanf("%d", &count);
	}
	
	return 0;
}