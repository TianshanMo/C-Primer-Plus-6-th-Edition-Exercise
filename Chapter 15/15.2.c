/* Programming Exercise 15-2 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SIZE 33
int bstoi(const char * st);
char * itobs(int n, char * ps);
char * s_gets(char * st, int n);

int main(void)
{
	char bin1[SIZE];
	char bin2[SIZE];
	char temp[SIZE];
	_Bool binflag1 = 1, binflag2 = 1;
	int binary1, binary2;
	printf("Enter a binary string:\n");
	s_gets(bin1, SIZE);
	for (int i = 0; bin1[i] != '\0'; i++)
		if (bin1[i] != '1' && bin1[i] != '0')
			binflag1 = 0;
	printf("Enter another binary string:\n");
	s_gets(bin2, SIZE);
	for (int i = 0; bin2[i] != '\0'; i++)
		if (bin2[i] != '1' && bin2[i] != '0')
			binflag2 = 0;
	if (binflag1 == 0 || binflag2 == 0 || bin1[1] == '\0' || bin2[0] == '\0')
	{
		printf("Invalid input.\n");
		exit(EXIT_FAILURE);
	}

	binary1 = bstoi(bin1);
	binary2 = bstoi(bin2);
	puts("----------------------------");
	printf("Decimal: %d, %d\n", binary1, binary2);
	printf("~%s : %s \n", bin1, itobs(~binary1, temp));
	printf("~%s : %s \n", bin2, itobs(~binary2, temp));
	printf("%s&%s : %s \n", bin1, bin2, itobs(binary1&binary2, temp));
	printf("%s|%s : %s \n", bin1, bin2, itobs(binary1 | binary2, temp));
	printf("%s^%s : %s \n", bin1, bin2, itobs(binary1^binary2, temp));

	return 0;
}

char * itobs(int n, char * ps)
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);

	for (i = size - 1; i >= 0; i--, n >>= 1)
		ps[i] = (01 & n) + '0';
	ps[size] = '\0';

	return ps;
}

int bstoi(const char * st)
{
	int val = 0;
	while (*st != '\0')
	{
		val <<= 1;
		if (*st == '1')
			val |= 1;
		st++;
	}

	return val;
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}