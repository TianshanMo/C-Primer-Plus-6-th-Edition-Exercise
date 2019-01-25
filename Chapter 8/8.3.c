/* Programming Exercise 8-3 */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char ch;
	int UpperNum = 0, SlowerNum = 0;
	while ((ch = getchar()) != EOF)
	{
		if (islower(ch))
			SlowerNum++;
		else if (isupper(ch))
			UpperNum++;
	}
	printf("The number of uppercase letters is %d\n", UpperNum);
	printf("The number of slowercase letters is %d\n", SlowerNum);

	return 0;
}