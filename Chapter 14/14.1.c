/* Programming Exercise 14-1 */
#include <stdio.h>
#include <string.h>

int days(const char * name);

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
	char mname[20];
	int totaldays;

	printf("Please enter the name of a month, or abbreviation for the month.\n");
	printf("such as Septmber or Step.\n");

	scanf("%s", mname);
	while (getchar() != '\n')
		continue;

	totaldays = days(mname);

	if (totaldays > 0)
		printf("There are %d days through %s.\n", totaldays, mname);
	else
		printf("Invalid input.\n");

	return 0;
}

int days(const char * name)
{
	int i;
	int index, total;
	for (i = 0; i < 12; i++)
	{
		if (strcmp(months[i].name, name) == 0)
			break;
		else if (strcmp(months[i].abbrev, name) == 0)
			break;
	}
	if (i == 12)
		return -1;
	for (index = 0, total = 0; index <= i; index++)
		total += months[index].days;

	return total;
}