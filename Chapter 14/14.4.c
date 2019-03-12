/* Programming Exercise 14-4 */
#include <stdio.h>
#include <ctype.h>
#define LEN 20
#define N 5

void print_a(struct guy person);
void print_b(struct guy * person);

struct names {
	char first[LEN];
	char middle[LEN];
	char last[LEN];
};

struct guy {
	long SSN;
	struct names handle;
};

int main(void)
{
	struct guy fellow[N] = {
		{302039823, {"Dribble", "Mc", "Flossie"} },
		{659032656, {"Eric", "Eills", "Yates"} },
		{505087622, {"Marie", "Jack", "Classen"} },
		{458916071, {"Steven", " ", "Morin"} },
		{311467440, {"Maureen", " ", "Costin"} },
	};

	puts("------------------------------------------");
	for (int i = 0; i < N; i++)
		print_a(fellow[i]);

	puts("------------------------------------------");
	for (int i = 0; i < N; i++)
		print_b(&fellow[i]);


	return 0;
}

void print_a(struct guy person)
{
	printf("%s, %s ", person.handle.first, person.handle.last);
	if (isalpha(person.handle.middle[0]))
		printf("%c. ", person.handle.middle[0]);
	printf("-- %ld\n", person.SSN);
}

void print_b(struct guy * person)
{
	printf("%s, %s ", person->handle.first, person->handle.last);
	if (isalpha(person->handle.middle[0]))
		printf("%c. ", person->handle.middle[0]);
	printf("-- %ld\n", person->SSN);
}