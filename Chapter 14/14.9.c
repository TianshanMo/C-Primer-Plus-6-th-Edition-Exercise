/* Programming Exercise 14-9 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SEATNUM 12
#define FLIGHTNUM 4
#define LEN 20

struct holder {
	int seat_id;
	bool seat_flag;
	char first[LEN];
	char last[LEN];
};

char getTopMenu(void);
void subMenu(struct holder * seat, char flightname[LEN]);
void showEmptyNum(struct holder * temp, int n);
void showEmptyList(struct holder * temp, int n);
void showAlphaList(struct holder * temp, int n);
void assignSeatAssignment(struct holder * temp, int n);
void deleteSeatAssignment(struct holder * temp, int n);
void confirmSeatAssignment(struct holder * seat, struct holder * temp, int n, char filename[LEN]);
char * s_gets(char * st, int n);

int main(void)
{
	struct holder seat102[SEATNUM];
	struct holder seat311[SEATNUM];
	struct holder seat444[SEATNUM];
	struct holder seat519[SEATNUM];
	char mainchoice;

	while ((mainchoice = getTopMenu()) != 'e')
	{
		switch (mainchoice)
		{
		case 'a': subMenu(seat102, "flight102.dat");
			break;
		case 'b': subMenu(seat311, "flight311.dat");
			break;
		case 'c': subMenu(seat444, "flight444.dat");
			break;
		case 'd': subMenu(seat519, "flight519.dat");
			break;
		}
	}
	printf("Done.\n");

	return 0;
}

char getTopMenu(void)
{
	char choice;
	puts("--Choose the flight:------------");
	puts("a) Flight 102");
	puts("b) Flight 311");
	puts("c) Flight 444");
	puts("d) Flight 519");
	puts("e) quit");


	while ((choice = getchar()) && (choice < 'a' || choice > 'e'))
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

void subMenu(struct holder * seat, char flightname[LEN])
{
	FILE * fp;
	char choice;
	struct holder temp[SEATNUM];
	int count = 0, fullcount = 0;
	int size = sizeof(struct holder);

	if ((fp = fopen(flightname, "a+b")) == NULL)
	{
		fprintf(stderr,"Can't open %s file\n", flightname);
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
	fclose(fp);
	putchar('\n');

	if (fullcount == 0)
		for (int i = 0; i < SEATNUM; i++)
			seat[i] = (struct holder) { .seat_flag = 0 };

	for (int i = 0; i < SEATNUM; i++)
		temp[i] = seat[i];

	while (1)
	{
		puts("-Start-------------------------------------");
		puts("To choose a function, enter its letter label:");
		puts("a) Show number of empty seats");
		puts("b) Show list of empty seats");
		puts("c) Show alphabetical list of seats");
		puts("d) Assign a customer to a seat assignment");
		puts("e) Delete a seat assignment");
		puts("f) Confirming a seat assignment");
		puts("g) Quit");
		while ((choice = getchar()) && (choice < 'a' || choice > 'g'))
		{
			while (getchar() != '\n')
				continue;
			puts("Invalid input. enter again:");
			continue;
		}
		while (getchar() != '\n')
			continue;

		switch (choice)
		{
		case 'a': showEmptyNum(temp, SEATNUM);
			break;
		case 'b': showEmptyList(temp, SEATNUM);
			break;
		case 'c': showAlphaList(temp, SEATNUM);
			break;
		case 'd': assignSeatAssignment(temp, SEATNUM);
			break;
		case 'e': deleteSeatAssignment(temp, SEATNUM);
			break;
		case 'f':confirmSeatAssignment(seat, temp, SEATNUM, flightname);
			break;
		case 'g':
			break;
		}

		if (choice == 'g' || choice == 'f')
			break;
	}
}

void showEmptyNum(struct holder * temp, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
		if (temp[i].seat_flag == 0)
			count++;
	printf("A total of %d seats are empty.\n", count);
	printf("-End-----------\n");
}

void showEmptyList(struct holder * temp, int n)
{
	int emptycount = 0;
	for (int i = 0; i < n; i++)
	{
		if (temp[i].seat_flag == 0)
			emptycount++;
	}
	if (emptycount == 0)
		printf("No empty seats are available.\n");
	else
	{
		printf("The following seats are empty:\n");
		for (int i = 0; i < n; i++)
			if (temp[i].seat_flag == 0)
				printf("%d ", i + 1);
		putchar('\n');
	}
	printf("-End-----------\n");
}

void showAlphaList(struct holder * temp, int n)
{
	int fullcount = 0;
	printf("This is alphabetical list of seats:\n");
	for (int i = 0; i < n; i++)
		if (temp[i].seat_flag == 1)
		{
			printf("No.%d: %s %s\n", i + 1, temp[i].first, temp[i].last);
			fullcount++;
		}
	if (fullcount == 0)
		printf("All seats are empty\n");
	printf("-End-----------\n");
}

void assignSeatAssignment(struct holder * temp, int n)
{
	int emptycount = 0;
	int order;
	char confirm;
	for (int i = 0; i < n; i++)
	{
		if (temp[i].seat_flag == 0)
			emptycount++;
	}
	if (emptycount == 0)
		printf("No empty seats are available.\n");
	else
	{
		printf("The following seats are empty:\n");
		for (int i = 0; i < n; i++)
			if (temp[i].seat_flag == 0)
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
		|| (temp[order - 1].seat_flag == 1))
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
	s_gets(temp[order].first, LEN);
	printf("Enter last name:\n");
	s_gets(temp[order].last, LEN);
	temp[order].seat_flag = 1;
	printf("-End-----------\n");
}

void deleteSeatAssignment(struct holder * temp, int n)
{
	char confirm;
	int del;
	int fullcount = 0;
	printf("This is alphabetical list of seats:\n");
	for (int i = 0; i < n; i++)
		if (temp[i].seat_flag == 1)
		{
			printf("No.%d: %s %s\n", i + 1, temp[i].first, temp[i].last);
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
		|| (temp[del - 1].seat_flag == 0))
	{
		while (getchar() != '\n')
			continue;
		puts("Invalid input. enter again:");
		continue;
	}
	while (getchar() != '\n')
		continue;

	del--;
	temp[del].first[0] = '\0';
	temp[del].last[0] = '\0';
	temp[del].seat_flag = 0;
	printf("-End-----------\n");
}

void confirmSeatAssignment(struct holder * seat, struct holder * temp, int n, char filename[LEN])
{
	FILE * fp;
	int count = 0;
	int size = sizeof(struct holder);

	if ((fp = fopen(filename, "w+b")) == NULL)
	{
		fprintf(stderr, "Can't open %s file\n", filename);
		exit(1);
	}
	for (int i = 0; i < n; i++)
		seat[i] = temp[i];
	while (count < SEATNUM && fwrite(&seat[count], size, 1, fp) == 1)
		count++;
	printf("-End-----------\n");

	fclose(fp);
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