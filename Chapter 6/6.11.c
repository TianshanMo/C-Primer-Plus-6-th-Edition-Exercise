/* Programming Exercise 6-11 */
#include <stdio.h>
#define SIZE 8
int main(void)
{
	int number[SIZE];
	int count;
	printf("Enter eight numbers: ");
	for (count = 0; count < SIZE; count++)
		scanf("%d", &number[count]);
	for (count--; count >= 0; count--)
		printf("%d ", number[count]);
	printf("\n");

	return 0;
}