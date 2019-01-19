/* Programming Exercise 6-13 */
#include <stdio.h>
int main(void)
{
	int powers_of_2[8];
	int power, count;
	for (count = 0, power = 2; count < 8; count++)
	{
		powers_of_2[count] = power;
		power = 2 * power;
	}
	count = 0;
	do
	{
		printf("%d ", powers_of_2[count]);
		count++;
	} while (count < 8);

	return 0;
}