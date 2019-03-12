/* Programming Exercise 14-3 */
/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100				 /* maximum number of books  */

char * s_gets(char * st, int n);
void sortt(struct book * pt, int n);		// using the structure address
void sortv(struct book library[], int n);	// passing a structure as an argument

struct book {					 /* set up book template     */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

int main(void)
{
	struct book library[MAXBKS]; /* array of book structures */
	int count = 0;
	int index;

	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
		&& library[count].title[0] != '\0')
	{
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;			/* clear input line         */
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}

	if (count > 0)
	{
		printf("Here is the list of your books:\n");
		for (index = 0; index < count; index++)
			printf("%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);
		printf("\nHere is the list of your books sort by title:\n");
		sortt(library, count);
		printf("\nHere is the list of your books sort by value:\n");
		sortv(library, count);
	}
	else
		printf("No books? Too bad.\n");

	return 0;
}

void sortt(struct book * pt, int n)
{
	struct book temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp((pt + i)->title, (pt + j)->title) > 0)
			{
				temp = *(pt + i);
				*(pt + i) = *(pt + j);
				*(pt + j) = temp;
			}
		}

	for (int index = 0; index < n; index++)
		printf("%s by %s: $%.2f\n", (pt + index)->title,
		(pt + index)->author, (pt + index)->value);
}

void sortv(struct book library[], int n)
{
	struct book temp;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (library[i].value > library[j].value)
			{
				temp = library[i];
				library[i] = library[j];
				library[j] = temp;
			}

	for (int index = 0; index < n; index++)
		printf("%s by %s: $%.2f\n", library[index].title,
			library[index].author, library[index].value);
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');	// look for newline
		if (find)					// if the address is not NULL,
			*find = '\0';			// place a null character there
		else
			while (getchar() != '\n')
				continue;			// dispose of rest of line
	}
	return ret_val;
}