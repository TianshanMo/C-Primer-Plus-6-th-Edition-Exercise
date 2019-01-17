/* Programming Exercise 4-7 */
#include <stdio.h>
#include <float.h>
int main(void)
{
	double dou = 1.0 / 3.0;
	float flo = 1.0 / 3.0;
	printf(" float values: ");
	printf("%.6f %.12f %.16f\n", flo, flo, flo);
	printf(" double values: ");
	printf("%.6f %.12f %.16f\n", dou, dou, dou);
	printf("FLT_DIG: %d\n", FLT_DIG);
	printf("DBL_DIG: %d\n", DBL_DIG);

	return 0;
}