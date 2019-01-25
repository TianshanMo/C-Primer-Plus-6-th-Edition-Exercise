/* Programming Exercise 8-4 */
#include <stdio.h>
#include <ctype.h>
int main(void)
{
	int ch;
	int WordNum = 0, LetterNum = 0;
	int WordFlag = 0;
	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			LetterNum++;
			if (WordFlag == 0)
			{
				WordNum++;
				WordFlag = 1;
			}
		}
		else
			WordFlag = 0;
	}
	printf("Average letters per word is %.2f\n", (float)LetterNum / WordNum);

	return 0;
}