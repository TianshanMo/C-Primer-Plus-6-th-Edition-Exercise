/* Programming Exercise 12-9 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 200
char ** trouble(int n);

int main(void)
{
	int n;
	char ** words;
	printf("How many words do you wish to enter? ");
	while (scanf("%d", &n) == 1)
	{
		while (getchar() != '\n')
			continue;
		printf("Enter %d words now: \n", n);
		words = trouble(n);
		printf("Here are your words:\n");
		for (int i = 0; i < n; i++)
		{
			printf("%s\n", words[i]);
			free(words[i]);
		}

		free(words);
		printf("How many words do you wish to enter? ");
	}

	return 0;
}

char ** trouble(int n)
{
	char ** ptd = (char **)malloc(n * sizeof(char *));
	char * temp = (char *)malloc(SIZE * sizeof(char));
	for (int i = 0; i < n; i++)
	{
		scanf("%s", temp);
		ptd[i] = (char *)malloc((strlen(temp) + 1) * sizeof(char));
		strcpy(ptd[i], temp);
	}
	while (getchar() != '\n')
		continue;
	free(temp);

	return ptd;
}