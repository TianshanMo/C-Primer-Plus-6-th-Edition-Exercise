/* Programming Exercise 10-4 */
#include <stdio.h>
#define SIZE 10
int max_index(const double ar[], int n);

int main(void)
{
	double ran[SIZE] = { 0.893, 0.524, 0.036, 0.781, 0.771, 0.537, 0.262, 0.015, 0.936, 0.484 };
	printf("A random array is as follows:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%.3f ", ran[i]);
	printf("\nThe maximun element is %d.\n", max_index(ran, SIZE));

	return 0;
}

int max_index(const double ar[], int n)
{
	double MaxNum = ar[0];
	int Maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (MaxNum < ar[i])
		{
			MaxNum = ar[i];
			Maxi = i;
		}
	}

	return Maxi;
}