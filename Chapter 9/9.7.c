/* Programming Exercise 9 - 7 */
#include <stdio.h>
#include <ctype.h>
int iLetterValue(char letter);

int main(void)
{
	int ch;
	printf("Report if a character is a letter.\n");
	printf("Enter a string:\n");
	while ((ch = getchar()) != EOF)
	{
		if (iLetterValue(ch) == -1)
			printf("'%c' is not a letter.\n", ch);
		else
			printf("'%c' is a letter and its position is %d.\n",
					ch, iLetterValue(ch));
	}

	return 0;
}

int iLetterValue(char letter)
{
	int value;
	if (isalpha(letter))
	{
		if (isupper(letter))
			value = (int)letter - 'A' + 1;
		else
			value = (int)letter - 'a' + 1;
	}
	else
		value = -1;
	return value;
}