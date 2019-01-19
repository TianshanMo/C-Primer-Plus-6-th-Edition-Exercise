/* Programming Exercise 6-6 */
#include <stdio.h>
int main(void)
{
	int lower_limit, upper_limit;
	int num, square, cube;
	printf("Enter lower and upper integer limits (in that order): ");
	scanf("%d%d", &lower_limit, &upper_limit);
	while (lower_limit > upper_limit)
	{
		printf("Enter limit again:");
		scanf("%d%d", &lower_limit, &upper_limit);
	}
	printf("|--------------------------------|\n");
	printf("| Integer  | Square   | Cube     |\n");
	printf("|--------  |----------|----------|\n");
	for (num = lower_limit; num <= upper_limit; num++)
	{
		square = num * num;
		cube = num * num * num;
		printf("| %-9d| %-9d| %-9d|\n", num, square, cube);
	}
	printf("|-The End------------------------|\n");

	return 0;
}
