/* Programming Exercise 11-12 */
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
int main(void)
{
	char ch;
	int Words = 0;				// the number of words
	int UppercaseLetters = 0;	// the number of uppercase letters
	int LowercaseLetters = 0;	// the number of lowercase letters
	int	PunctChars = 0;			// the number of punctuation characters
	int Digits = 0;				// the number of digits
	bool WordsFlag = 0;
	puts("Enter a string (EOF to quit):");
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			if (WordsFlag == 0)
			{
				Words++;
				WordsFlag = 1;
			}
			if (isupper(ch))
				UppercaseLetters++;
			else if (islower(ch))
				LowercaseLetters++;
		}
		else if (ispunct(ch))
			PunctChars++;
		else if (isdigit(ch))
			Digits++;
		if (isspace(ch) && WordsFlag)
			WordsFlag = 0;
	}

	printf("the number of words is %d:\n", Words);
	printf("the number of uppercase letters is %d\n", UppercaseLetters);
	printf("the number of lowercase letters is %d\n", LowercaseLetters);
	printf("the number of punctuation characters is %d\n", PunctChars);
	printf("the number of digits is %d\n", Digits);

	return 0;
}