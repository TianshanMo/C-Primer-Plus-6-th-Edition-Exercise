/* Programming Exercise 10-8 */
#include <stdio.h>
void copy_ptrs(double * target, const double * start, const double * end);

int main(void)
{
	const double source[7] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7 };
	double target[3];
	
	printf("Source array:\n");
	for (int i = 0; i < 7; i++)
		printf("%.1f ", source[i]);

	printf("\nCopying...\n");
	copy_ptrs(target, source + 2, source + 5);
	printf("Target array:\n");
	for (int i = 0; i < 3; i++)
		printf("%.1f ", target[i]);

	return 0;
}

void copy_ptrs(double * target, const double * start, const double * end)
{
	while (start < end)
	{
		*(target)++ = *(start++);
	}
}