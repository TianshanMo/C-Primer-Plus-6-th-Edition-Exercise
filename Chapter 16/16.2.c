/* Programming Exercise 16-2 */
#include <stdio.h>
#define HMEAN(X, Y) (2.0 * (X) *(Y) / ((X) + (Y)))

int main(void)
{
	printf("The harmonic mean of %.2f and %.2f is %.2f\n",
		5.2, 3.14, HMEAN(5.2, 3.14));

	return 0;
}