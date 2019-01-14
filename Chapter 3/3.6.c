/* Programming Exercise 3-6 */
#include <stdio.h>
int main(void)
{
	float quarts;
	float grams;
	float molecule_counts;
	printf("Please input water quarts:");
	scanf("%f", &quarts);
	grams = quarts * 950.0f;
	molecule_counts = grams / 3.0e-23;
	printf("%f quarts of water contain %e molecules.\n", quarts, molecule_counts);

	return 0;
}