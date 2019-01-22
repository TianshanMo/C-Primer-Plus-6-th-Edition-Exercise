/* Programming Exercise 7-6 */
#include <stdio.h>
#define STOP '#'
#define FLAG "ei"
int main(void)
{
	char ch;
	char prev_ch = 0;
	int count = 0;
	printf("Enter input (# to exit):\n");
	while ((ch = getchar()) != STOP)
	{
		if (ch == 'e')
		{
			prev_ch = 'e';
			continue;
		}
		if (ch != 'i')
			prev_ch = 0;

		if ((prev_ch == 'e') && (ch == 'i'))
		{
			count++;
			prev_ch = 0;
		}
	}
	printf("A total of %d %s were made.\n", count, FLAG);

	return 0;
}