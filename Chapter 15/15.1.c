/* Programming Exercise 15-1 */
#include <stdio.h>
int bstoi(const char * str);

int main(void)
{
	char * pbin = "01001001";
	printf("%d\n", bstoi(pbin));

	return 0;
}

int bstoi(const char * str)
{
	int val = 0;
	while (*str != '\0')
	{
		val <<= 1;
		if (*str == '1')
			val |= 1;
		str++;
	}

	return val;
}