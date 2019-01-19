/* Programming Exercise 6-14 */
#include <stdio.h>
int main(void)
{
	double array1[8];
	double array2[8] = { 0 };
	int count, sum = 0;

	printf("Enter 8 integers:\n");
	for (count = 0; count < 8; count++)
	{
		scanf("%lf", &array1[count]);
		sum += array1[count];
		array2[count] = sum;
	}
	printf("---Integers: ---------\n");
	for (count = 0; count < 8; count++)
		printf("| %-10.2lf", array1[count]);
	printf("\n---Cumulative sum: ---\n");
	for (count = 0; count < 8; count++)
		printf("| %-10.2lf", array2[count]);
	printf("\n");

	return 0;
}