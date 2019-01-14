/* Programming Exercise 3-1 */
#include <stdio.h>
int main(void)
{
	int integer_overflow;
	float float_point_overflow;
	float float_point_underflow;
	integer_overflow = 2147483647;
	float_point_overflow = 3.4e38f;
	float_point_underflow = 1.2e-38f;

	integer_overflow = integer_overflow + 1;
	float_point_overflow = float_point_overflow * 100.0f;
	float_point_underflow = float_point_underflow / 100.0f;

	printf("integer overflow = %d\n", integer_overflow);
	printf("float point overflow = %f\n", float_point_overflow);
	printf("float point underflow = %f\n", float_point_underflow);

	return 0;
}