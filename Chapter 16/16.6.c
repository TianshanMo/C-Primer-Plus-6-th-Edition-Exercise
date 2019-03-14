/* Programming Exercise 16-6 */
/* qsorter.c -- using qsort to sort groups of numbers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 7

struct names {
	char first[40];
	char last[40];
};

void showarray(const struct names * ar, int n);
int mycomp(const void * p1, const void * p2);

int main(void)
{
	struct names name[] = {
		{"Michael", "Townley"},
		{"Trevor", "Philips"},
		{"Franklin", "Clinton"},
		{"Lester", "Crest"},
		{"Dave","Norton"},
		{"Devin","Weston"},
		{"Lamar","Davis"}
	};
	
	puts("Random list:");
	showarray(name, NUM);
	qsort(name, NUM, sizeof(struct names), mycomp);
	puts("\nSorted list:");
	showarray(name, NUM);

	return 0;
}


void showarray(const struct names * name, int n)
{
	int index;

	for (index = 0; index < n; index++)
		printf("%-9s %-9s\n", name[index].first, name[index].last);
}

int mycomp(const void * p1, const void * p2) /* mandatory form */
{
	/* get right type of pointer */
	const struct names *ps1 = (const struct names *) p1;
	const struct names *ps2 = (const struct names *) p2;
	int res;

	res = strcmp(ps1->last, ps2->last);  /* compare last names */
	if (res != 0)
		return res;
	else       /* last names identical, so compare first names */
		return strcmp(ps1->first, ps2->first);
}