/* Programming Exercise 10-5 */
#include <stdio.h>
#define SIZE 10
double difference(const double ar[], int n);

int main(void)
{
	double ran[SIZE] = { 0.893, 0.524, 0.036, 0.781, 0.771, 0.537, 0.262, 0.015, 0.936, 0.484 };
	printf("A random array is as follows:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%.3f ", ran[i]);
	printf("\nThe difference between the largest and smallest is %.3f\n", difference(ran, SIZE));

	return 0;
}

double difference(const double ar[], int n)
{
	double MaxNum = ar[0];
	double MinNum = ar[0];
	for (int i = 0; i < n; i++)
	{
		if (MaxNum < ar[i])
			MaxNum = ar[i];
		if (MinNum > ar[i])
			MinNum = ar[i];
	}

	return MaxNum - MinNum;
}