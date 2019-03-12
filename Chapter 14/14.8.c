/* Programming Exercise 14-8 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SEATNUM 12
#define LEN 20

struct holder {
	int seat_id;
	bool seat_flag;
	char first[LEN];
	char last[LEN];
};

char getMenu(void);
void showEmptyNum(struct holder * seat, int n);
void showEmptyList(struct holder * seat, int n);
void showAlphaList(struct holder * seat, int n);
void assignSeatAssignment(struct holder * seat, int n);
void deleteSeatAssignment(struct holder * seat, int n);
char * s_gets(char * st, int n);

int main(void)
{
	struct holder seat[SEATNUM];
	struct holder * pt;
	FILE * fp;
	char choice;
	int count = 0, fullcount = 0;
	int size = sizeof(struct holder);

	if ((fp = fopen("database.dat", "a+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(fp);
	while (count < SEATNUM && fread(&seat[count], size, 1, fp) == 1)
	{
		if (seat[count].seat_flag == 1)
		{
			printf("No.%d: %s %s\n",
				count + 1, seat[count].first, seat[count].last);
			fullcount++;
		}
		count++;
	}
	count = 0;
	fclose(fp);
	putchar('\n');

	if (fullcount == 0)
		for (int i = 0; i < SEATNUM; i++)
			seat[i] = (struct holder) { .seat_flag = 0 };

	while ((choice = getMenu()) != 'f')
	{
		switch (choice)
		{
		case 'a': showEmptyNum(seat, SEATNUM);
			break;
		case 'b': showEmptyList(seat, SEATNUM);
			break;
		case 'c': showAlphaList(seat, SEATNUM);
			break;
		case 'd': assignSeatAssignment(seat, SEATNUM);
			break;
		case 'e': deleteSeatAssignment(seat, SEATNUM);
			break;
		case 'f':
			break;
		default:
			break;
		}
	}

	if ((fp = fopen("database.dat", "w+b")) == NULL)
	{
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	while (count < SEATNUM && fwrite(&seat[count], size, 1, fp) == 1)
		count++;
	fclose(fp);

	return 0;
}

char getMenu(void)
{
	char choice;
	puts("-Start-------------------------------------");
	puts("To choose a function, enter its letter label:");
	puts("a) Show number of empty seats");
	puts("b) Show list of empty seats");
	puts("c) Show alphabetical list of seats");
	puts("d) Assign a customer to a seat assignment");
	puts("e) Delete a seat assignment");
	puts("f) Quit");

	while ((choice = getchar()) && (choice < 'a' || choice > 'f'))
	{
		while (getchar() != '\n')
			continue;
		puts("Invalid input. enter again:");
		continue;
	}
	while (getchar() != '\n')
		continue;

	return choice;
}

void showEmptyNum(struct holder * seat, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (seat[i].seat_flag == 0)
			count++;
	printf("A total of %d seats are empty.\n", count);
	printf("-End-----------\n");
}

void showEmptyList(struct holder * seat, int n)
{
	int emptycount = 0;
	for (int i = 0; i < n; i++)
	{
		if (seat[i].seat_flag == 0)
			emptycount++;
	}
	if (emptycount == 0)
		printf("No empty seats are available.\n");
	else
	{
		printf("The following seats are empty:\n");
		for (int i = 0; i < n; i++)
			if (seat[i].seat_flag == 0)
				printf("%d ", i + 1);
		putchar('\n');
	}
	printf("-End-----------\n");
}

void showAlphaList(struct holder * seat, int n)
{
	int fullcount = 0;
	printf("This is alphabetical list of seats:\n");
	for (int i = 0; i < n; i++)
		if (seat[i].seat_flag == 1)
		{
			printf("No.%d: %s %s\n", i + 1, seat[i].first, seat[i].last);
			fullcount++;
		}
	if (fullcount == 0)
		printf("All seats are empty\n");
	printf("-End-----------\n");
}

void assignSeatAssignment(struct holder * seat, int n)
{
	int emptycount = 0;
	int order;
	char confirm;
	for (int i = 0; i < n; i++)
	{
		if (seat[i].seat_flag == 0)
			emptycount++;
	}
	if (emptycount == 0)
		printf("No empty seats are available.\n");
	else
	{
		printf("The following seats are empty:\n");
		for (int i = 0; i < n; i++)
			if (seat[i].seat_flag == 0)
				printf("%d ", i + 1);
		putchar('\n');
	}

	printf("Enter 'a' to confirm the ordering of the seat. Other input to cancel.\n");
	confirm = getchar();
	if (confirm != 'A' && confirm != 'a')
	{
		while (getchar() != '\n')
			continue;
		return;
	}
	while (getchar() != '\n')
		continue;

	printf("Which seat do you want to order?\n");
	while ((scanf("%d", &order) != 1) || (order < 1 || order > n)
		|| (seat[order - 1].seat_flag == 1))
	{
		while (getchar() != '\n')
			continue;
		puts("Invalid input. enter again:");
		continue;
	}
	while (getchar() != '\n')
		continue;

	order--;
	printf("Enter first name:\n");
	s_gets(seat[order].first, LEN);
	printf("Enter last name:\n");
	s_gets(seat[order].last, LEN);
	seat[order].seat_flag = 1;
	printf("-End-----------\n");
}

void deleteSeatAssignment(struct holder * seat, int n)
{
	char confirm;
	int del;
	int fullcount = 0;
	printf("This is alphabetical list of seats:\n");
	for (int i = 0; i < n; i++)
		if (seat[i].seat_flag == 1)
		{
			printf("No.%d: %s %s\n", i + 1, seat[i].first, seat[i].last);
			fullcount++;
		}
	if (fullcount == 0)
	{
		printf("All seats are empty\n");
		return;
	}

	printf("Enter 'd' to confirm deleting the seat. Other input to cancel.\n");
	confirm = getchar();
	if (confirm != 'D' && confirm != 'd')
	{
		while (getchar() != '\n')
			continue;
		return;
	}
	while (getchar() != '\n')
		continue;

	printf("Which seat do you want to delete?\n");
	while ((scanf("%d", &del) != 1) || (del < 1 || del > n)
		|| (seat[del - 1].seat_flag == 0))
	{
		while (getchar() != '\n')
			continue;
		puts("Invalid input. enter again:");
		continue;
	}
	while (getchar() != '\n')
		continue;

	del--;
	seat[del].first[0] = '\0';
	seat[del].last[0] = '\0';
	seat[del].seat_flag = 0;
	printf("-End-----------\n");
}

char * s_gets(char * st, int n)
{
	char * ret_val;
	char * find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n'); // look for newline
		if (find) // if the address is not NULL,
			*find = '\0'; // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}