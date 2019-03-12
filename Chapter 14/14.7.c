/* Programming Exercise 14-7 */
/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10				/* maximum number of books */
char * s_gets(char * st, int n);
void showrecord(void);
void addrecord(void);
void deleterecord(void);
void modifyrecord(void);


struct book {					/* set up book template	   */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};


int main(void)
{
	char mainchoice;
	while (1)
	{
		showrecord();

		printf("-----------------------------------------\n");
		printf("Enter you choice:\n");
		printf("a. add record        d. delete record \n");
		printf("m. modify record     q. quit \n");
		mainchoice = getchar();
		while (getchar() != '\n')
			continue;

		switch (mainchoice)
		{
		case 'a': addrecord();
			break;
		case 'd': deleterecord();
			break;
		case 'm': modifyrecord();
			break;
		case 'q': printf("Done!\n");
			exit(EXIT_SUCCESS);
		default: printf("%c is an invalid input, enter again :\n", mainchoice);
			break;
		}
	}

	return 0;
}

void showrecord(void)
{
	struct book library[MAXBKS];
	FILE * pbooks;
	int count = 0;
	int size = sizeof(struct book);

	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		if (count == 0)
			puts("Current contents of book.dat:");
		printf("%d: %s by %s: $%.2f\n", count + 1, library[count].title,
			library[count].author, library[count].value);
		count++;
	}
	fclose(pbooks);
}

void addrecord(void)
{
	struct book library[MAXBKS];
	FILE * pbooks;
	int count = 0;
	int size = sizeof(struct book);
	if ((pbooks = fopen("book.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
		continue;

	if (count == MAXBKS)
	{
		fputs("The book.dat file is full.", stderr);
		return;	// quit this function
	}

	puts("Please add new book titles.");
	puts("Press [enter] at the start of a line to stop.");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL && library[count].title[0] != '\0')
	{
		puts("Now enter the author.");
		s_gets(library[count].author, MAXAUTL);
		puts("Now enter the value.");
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue;				 /* clear input line */
		if (count < MAXBKS)
			puts("Enter the next title.");
	}
	for (int i = 0; i < count; i++)
		fwrite(&library[i], size, 1, pbooks);

	fclose(pbooks);
}

void deleterecord(void)
{
	struct book library[MAXBKS];
	FILE * pbooks;
	int count = 0;
	int size = sizeof(struct book);
	int choice;
	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		count++;
		continue;
	}

	if (count == 0)
	{
		printf("No record!\n");
		return;
	}

	fclose(pbooks);

	if ((pbooks = fopen("book.dat", "w+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	puts("Select the number of the record you want to delete, q to quit: ");
	while ((scanf("%d", &choice) != 1) || (choice < 1 || choice > count + 1))
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid input. Please enter a number.\n");
		continue;
	}
	while (getchar() != '\n')
		continue;

	choice--;
	for (int i = choice; i < count; i++)
		library[i] = library[i + 1];
	for (int i = 0; i < count - 1; i++)
		fwrite(&library[i], size, 1, pbooks);

	fclose(pbooks);
}

void modifyrecord(void)
{
	struct book library[MAXBKS];
	FILE * pbooks;
	int count = 0;
	int size = sizeof(struct book);
	int choice;
	if ((pbooks = fopen("book.dat", "r+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1)
	{
		count++;
		continue;
	}

	if (count == 0)
	{
		printf("No record!\n");
		return;
	}

	fclose(pbooks);

	if ((pbooks = fopen("book.dat", "w+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}

	puts("Select the number of the record you want to modify, q to quit: ");
	while ((scanf("%d", &choice) != 1) || (choice < 1 || choice > count + 1))
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid input. Please enter a number.\n");
		continue;
	}
	while (getchar() != '\n')
		continue;

	choice--;

	printf("Now enter the book titles: ");
	s_gets(library[choice].title, MAXTITL);
	printf("Now enter the author: ");
	s_gets(library[choice].author, MAXAUTL);
	puts("Now enter the value.");
	scanf("%f", &library[choice].value);
	while (getchar() != '\n')
		continue;

	for (int i = 0; i < count; i++)
		fwrite(&library[i], size, 1, pbooks);

	fclose(pbooks);
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