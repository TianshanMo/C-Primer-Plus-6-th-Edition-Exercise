/* Programming Exercise 10-2 */
#include <stdio.h>
void copy_arr(double target[], double source[], int n);
void copy_ptr(double * target, double * source, int n);
void copy_ptrs(double * target, double * start, double * end);

int main(void)
{
	double source[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	double target1[5];
	double target2[5];
	double target3[5];

	copy_arr(target1, source, 5);
	copy_ptr(target2, source, 5);
	copy_ptrs(target3, source, source + 5);
	printf(" |elements   |target1  |target2  |target3\n");
	for (int i = 0; i < 5; i++)
	{
		printf(" | %d         | %.1f     | %.1f     | %.1f    \n",
			i, target1[i], target2[i], target3[i]);
	}

	return 0;
}

void copy_arr(double target[], double source[], int n)
{
	for (int i = 0; i < n; i++)
		target[i] = source[i];
}

void copy_ptr(double * target, double * source, int n)
{
	for (int i = 0; i < n; i++)
		*(target + i) = *(source + i);
}

void copy_ptrs(double * target, double * start, double * end)
{
	while (start < end)
	{
		*target++ = *start++;
	}
}