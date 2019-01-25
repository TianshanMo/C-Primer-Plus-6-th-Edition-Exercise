/* Programming Exercise 8-5 */
#include <stdio.h>
int main(void)
{
	char ch;
	int guess = 50;
	int up = 100;
	int down = 0;

	printf("Pick an integer from 1 to 100. I will try to guess ");
	printf("it.\nRespond with a y if my guess is right and with");
	printf("\na b if it is bigger and a s if it is smaller.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((ch = getchar()) != 'y')	  /* get response, compare to y */
	{
		while (getchar() != '\n')
			continue;
		if (ch == 'b')
			up = guess;
		else if (ch == 's')
			down = guess;
		else
		{
			printf("Is the number I guess bigger or smaller ");
			printf("than yours?\n");
			printf("b. bigger   s. smaller   y. guess right\n");
			continue;
		}
		guess = (up + down) / 2;

		printf("Well, then, is it %d?\n", guess);
	}
	printf("I knew I could do it!\n");

	return 0;
}