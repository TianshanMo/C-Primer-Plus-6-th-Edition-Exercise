/* Programming Exercise 15-5 */
#include <stdio.h>
#include <limits.h>
unsigned int rotate_l(unsigned int val, int position);
char * itobs(int, char *);
void show_bstr(const char *);

int main(void)
{
	unsigned int val;
	int position;
	char bin_str[CHAR_BIT * sizeof(int) + 1];
	printf("Enter an integer:\n");
	while (scanf("%ud", &val) == 1)
	{
		printf("Enter a position:\n");
		while (scanf("%d", &position) == 1)
		{
			printf("Before rotation: ");
			itobs(val, bin_str);
			show_bstr(bin_str);
			val = rotate_l(val, position);
			printf("\nAfter rotation:  ");
			itobs(val, bin_str);
			show_bstr(bin_str);
			printf("\nEnter a position(q to quit): \n");
		}
	}
}

unsigned int rotate_l(unsigned int val, int position)
{
	unsigned int temp;
	temp = val >> (CHAR_BIT * sizeof(int) - position);
	val <<= position;
	val |= temp;

	return val;
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';	// assume ASCII or similar
	ps[size] = '\0';

	return ps;
}

void show_bstr(const char * str)
{
	int i = 0;

	while (str[i])	/* not the null character */
	{
		putchar(str[i]);
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}