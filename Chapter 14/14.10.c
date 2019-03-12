/* Programming Exercise 14-10 */
#include <stdio.h>
void helloworld(void);
void isPHPbest(void);
void wastetime(void);
void secretcode(void);

int main(void)
{
	void(*pf[4])(void) =
	{
		helloworld,
		isPHPbest,
		wastetime,
		secretcode
	};
	char choice;

	puts("What are you going to do");
	puts("a) Hello world!");
	puts("b) Is PHP the best language in the world?");
	puts("c) I want to waste my dear life");
	puts("d) I want a bunch of secret code");
	puts("q) Good bye!");
	while ((choice = getchar()) && choice != 'q')
	{
		while (getchar() != '\n')
			continue;
		if (choice < 'a' || choice > 'd')
		{
			printf("Invalid input, enter again:\n");
			continue;
		}
		switch (choice)
		{
		case 'a': pf[0]();
			break;
		case 'b': pf[1]();
			break;
		case 'c': (*pf[2])();
			break;
		case 'd': (*pf[3])();
			break;
		}
		puts("What are you going to do");
		puts("a) Hello world!");
		puts("b) Is PHP the best language in the world?");
		puts("c) I want to waste my dear life");
		puts("d) I want a bunch of secret code");
		puts("q) Good bye!");
	}

	return 0;
}

void helloworld(void)
{
	printf("Hello, world!\n");
}

void isPHPbest(void)
{
	printf("No, C is the best programming language in the world!\n");
}

void wastetime(void)
{
	printf("-1s\n");
	for (long i = 0; i < 900388533; i++)
		;
}

void secretcode(void)
{
	printf("magnet:?xt=urn:btih:0FC319DC76FEFF3B91F0DBE3C00230F5CA49E24E\n");
}