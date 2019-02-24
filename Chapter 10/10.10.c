/* Programming Exercise 10-10 */
#include <stdio.h>
#define SIZE 4
void add_arr(const int * ar1, const int * ar2, int * ar3, int n);
void print_arr(const int * ar, int n);

int main(void)
{
	const int source1[SIZE] = { 2, 4, 5, 8 };
	const int source2[SIZE] = { 1, 0, 4, 6 };
	int target[SIZE];

	printf("Source array 1:\n");
	print_arr(source1, SIZE);
	printf("Source array 2:\n");
	print_arr(source2, SIZE);

	add_arr(source1, source2, target, SIZE);

	printf("Target array:\n");
	print_arr(target, SIZE);

	return 0;
}

void add_arr(const int * ar1, const int * ar2, int * ar3, int n)
{
	for (int i = 0; i < n; i++)
		*(ar3 + i) = *(ar1 + i) + *(ar2 + i);
}

void print_arr(const int * ar, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", *(ar + i));
	putchar('\n');
}