/* Programming Exercise 5-1 */
#include <stdio.h>
#define M_PER_H 60
int main(void)
{
	int hour, minute, total_minute;
	printf("Enter the number of minutes to convert:");
	scanf("%d", &total_minute);
	while (total_minute > 0)
	{
		hour = total_minute / M_PER_H;
		minute = total_minute % M_PER_H;
		printf("%d minute = %d hour,%d minutes\n", total_minute, hour, minute);
		printf("Enter next minutes value (0 to quit):");
		scanf("%d", &total_minute);
	}
	
	return 0;
}