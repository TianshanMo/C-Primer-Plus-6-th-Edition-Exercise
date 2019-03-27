/* Programming Exercise 17-7 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "17.7 tree.h"

#define EATLINE while (getchar() != '\n') continue

char getmenu(void);
void showwords(Item item);
void findwords(const Tree * pt);

char * s_gets(char * st, int n);

int main(void)
{
	FILE * fp;
	char ch;
	char choice;
	char filename[100];
	char word[SLEN];
	int i = 0;
	Item temp = {"", 0};
	Tree dict;

	printf("Enter name of destination file: \n");
	s_gets(filename, 100);
	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	InitializeTree(&dict);

	while ((ch = getc(fp)) != EOF && !TreeIsFull(&dict))
	{
		putchar(ch);
		if (isalpha(ch))
		{
			tolower(ch);
			word[i++] = ch;
		}
		else
		{
			word[i] = '\0';
			if (i > 0)
			{
				strcpy(temp.word, word);
				AddItem(&temp, &dict);
			}
			i = 0;
		}
	}
	while ((choice = getmenu()) != 'q')
	{
		switch (choice)
		{
		case 'l' :	if (TreeIsEmpty(&dict))
						printf("No words!\n");
					else
						Traverse(&dict, showwords);
			break;
		case 'f': findwords(&dict);
			break;
		default: puts("Switching error");
		}
	}

	return 0;
}

char getmenu(void)
{
	int ch;
	puts("Enter the letter corresponding to your choice:");
	puts("l) lists words     f) find words       q) quit");
	while ((ch = getchar()) != EOF)
	{
		EATLINE;
		ch = tolower(ch);
		if (strchr("lfq", ch) == NULL)
			puts("Please enter a l, f or q:");
		else
			break;
	}
	if (ch == EOF)        /* make EOF cause program to quit */
		ch = 'q';

	return ch;
}

void showwords(Item item)
{
	printf("%-10s :%d\n", item.word, item.count);
}

void findwords(const Tree * pt)
{
	Item temp;
	Trnode * find;
	char word[SLEN];
	printf("Enter a word: ");
	s_gets(word, SLEN);
	strcpy(temp.word, word);
	temp.count = 1;

	find = InTree(&temp, pt);
	if (find)
		printf("%-10s :%d\n", find->item.word, find->item.count);
	else
		printf("404 not found.\n");
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
		else
			EATLINE;
	}

	return ret_val;
}