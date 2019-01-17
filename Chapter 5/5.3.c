/* Programming Exercise 5-3 */
#include <stdio.h>
int main(void)
{
	int total_days, weeks, days;
	printf("Enter the number of days to convert:");
	scanf("%d", &total_days);
	while (total_days > 0)
	{
		weeks = total_days / 7;
		days = total_days % 7;
		printf("%d days are %d weeks,%d days\n", total_days, weeks, days);
		printf("Enter next days value (0 to quit): ");
		scanf("%d", &total_days);
	}
	
	return 0;
}