/* Programming Exercise 3-5 */
#include <stdio.h>
int main(void)
{
	int ages;
	float seconds;
	printf("Please input your ages: ");
	scanf("%d", &ages);
	seconds = ages * 3.156e7;
	printf("\nYou have lived for %f seconds", seconds);

	return 0;
}