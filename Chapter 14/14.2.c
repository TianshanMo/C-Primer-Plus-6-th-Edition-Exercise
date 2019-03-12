/* Programming Exercise 14-2 */
#include <stdio.h>
#include <string.h>

int days(const char * name, int year, int * day_limit);
char * s_gets(char *st, int n);

struct month {
	char name[10];
	char abbrev[4];
	int days;
	int monumb;
};

const struct month months[12] = {
	{"January", "Jan", 31, 1},
	{"February", "Feb", 28, 2},
	{"March", "Mar", 31, 3},
	{"April", "Apr", 30, 4},
	{"May", "May", 31, 5},
	{"June", "Jun", 30, 6},
	{"July", "Jul", 31, 7},
	{"August", "Aug", 31, 8},
	{"September", "Sep", 30, 9},
	{"October", "Oct", 31, 10},
	{"November", "Nov", 30, 11},
	{"December", "Dec", 31, 12}
};

int main(void)
{
	int year, day;
	char month[20];
	int day_limit;	// date limit

	printf("Enter the year: ");
	while ((scanf("%d", &year)) == 1)
	{
		while (getchar() != '\n')
			continue;
		printf("Enter month by month number, month name, "
			"or abbrevation, such as 9, September, Sep : ");
		s_gets(month, 20);

		int totaldays = days(month, year, &day_limit);

		if (totaldays < 0)
		{
			printf("Invalid input. Enter the year: ");
			continue;
		}

		printf("Enter the day: ");
		if (scanf("%d", &day) != 1 || (day <= 0 || day > day_limit))
		{
			printf("Invalid input. Enter the year: ");
			continue;
		}
		while (getchar() != '\n')
			continue;

		totaldays += day;

		/* The total number of days in leap years should be increased by 1 */
		if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
			totaldays++;
		
		printf("There are %d days.\n", totaldays);
		printf("Enter the year, q to quit: ");
	}

	return 0;
}

int days(const char * name, int year, int * day_limit)
{
	int i;
	int index, total;
	for (i = 0; i < 12; i++)
	{
		char temp[10];
		sprintf(temp, "%d", months[i].monumb);

		if (strcmp(months[i].name, name) == 0)
			break;
		else if (strcmp(months[i].abbrev, name) == 0)
			break;
		else if (strcmp(temp, name) == 0)
			break;
	}

	if (i == 12)
		return -1;
	for (index = 0, total = 0; index < i; index++)
		total += months[index].days;
	*day_limit = months[i].days;	// Date limit

	/* February of leap year */
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		if (i == 1)
			(*day_limit)++;

	return total;
}

char * s_gets(char *st, int n)
{
	char * ret_val;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return ret_val;
}