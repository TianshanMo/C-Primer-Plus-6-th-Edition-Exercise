/* Programming Exercise 11-15 */
#include <stdio.h>
#include <ctype.h>
int atoi(char * st);

int main(int argc, char *argv[])
{
	int value;

	if (argc != 2)
		printf("Usage: %s positive-number\n", argv[0]);
	else
	{
		value = atoi(argv[1]);
		printf("The converted number is %d.", value);
	}

	return 0;
}

int atoi(char * st)
{
	int count;
	int value = 0;
	for (count = 0; st[count] != '\0'; count++)
	{
		if (!isdigit(st[count]))
			return 0;
		else
		{
			value *= 10;
			value += st[count] - '0';
		}
	}
	return value;
}