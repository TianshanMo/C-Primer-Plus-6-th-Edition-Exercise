/* Programming Exercise 6-18 */
#include <stdio.h>
#define DUNBAR 150
int main(void)
{
	int friends_count = 5;
	int week = 0;
	printf("|-----------------|\n");
	printf("| weeks | friends |\n");
	while (friends_count <= DUNBAR)
	{
		printf("| %-5d | %-7d |\n", week, friends_count);
		week++;
		friends_count -= week;
		friends_count *= 2;
	}
	printf("|-----------------|\n");

	return 0;
}