/* Programming Exercise 10-3 */
#include <stdio.h>
#define SIZE 10
int max(const int ar[], int n);

int main(void)
{
	int integer[SIZE] = { 41, 79, 83, 80, 75, 2, 38, 24, 3, 96 };
	printf("A random array is as follows:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%d ", integer[i]);
	printf("\nThe maximun value is %d.\n", max(integer, SIZE));

	return 0;
}

int max(const int ar[], int n)
{
	int MaxNum = ar[0];
	for (int i = 0; i < n; i++)
	{
		if (MaxNum < ar[i])
			MaxNum = ar[i];
	}
	
	return MaxNum;
}