/* Programming Exercise 16-4 */
#include <stdio.h>
#include <time.h>
void delay(double t);

int main(void)
{
	double t;
	printf("Enter a time to test: ");
	while (scanf("%lf", &t) == 1)
	{
		delay(t);
		printf("Enter a time to waste your dear life (q to quit): ");
	}
	
	return 0;
}

void delay(double t)
{
	clock_t time = clock();

	while (((double)(clock() - time) / (double)CLOCKS_PER_SEC) < t)
		continue;

	printf("+%.1fs\n", t);
}