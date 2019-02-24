/* Programming Exercise 10-6 */
#include <stdio.h>
#define SIZE 10
void sort(const double ar[], int n);

int main(void)
{
	double ran[SIZE] = { 0.893, 0.524, 0.036, 0.781, 0.771, 0.537, 0.262, 0.015, 0.936, 0.484 };
	printf("A random array is as follows:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%.3f ", ran[i]);
	sort(ran, SIZE);
	printf("\nAfter reverses the contents:\n");
	for (int i = 0; i < SIZE; i++)
		printf("%.3f ", ran[i]);
	putchar('\n');

	return 0;
}

void sort(double ar[], int n)
{
	int i;
	double temp;
	for (i = 0; i < n / 2; i++)
	{
		temp = ar[i];
		ar[i] = ar[n - i - 1];
		ar[n - i - 1] = temp;
	}
}