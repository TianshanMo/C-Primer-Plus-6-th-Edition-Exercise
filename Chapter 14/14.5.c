/* Programming Exercise 14-5 */
#include <stdio.h>
#define LEN 20
#define SSIZE 3
#define CSIZE 4

void getscore(struct student * ps, int n);
void stuaverage(struct student * ps, int n);
void showaverage(struct student * ps, int n);


struct name {
	char first[LEN];
	char last[LEN];
};

struct student {
	struct name sname;
	float grade[SSIZE];
	float average;
};

int main(void)
{
	struct student group[CSIZE] = {
		{"Tomas", "Nelson"},
		{"Donald", "Williams"},
		{"Charles", "Richard"},
		{"Carmen", "Evans"},
	};

	getscore(group, CSIZE);
	stuaverage(group, CSIZE);
	showaverage(group, CSIZE);

	return 0;
}

void getscore(struct student * ps, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter %s %s's scores (three object): ",
			ps[i].sname.first, ps[i].sname.last);
		for (int j = 0; j < SSIZE; j++)
		{
			while ((scanf("%f", &ps[i].grade[j])) != 1)
			{
				while (getchar() != '\n')
					continue;
				printf("Invalid input. Enter a number: ");
				continue;
			}
		}
		while (getchar() != '\n')
			continue;
	}
}

void stuaverage(struct student * ps, int n)
{
	float sum = 0.0f;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < SSIZE; j++)
			sum += ps[i].grade[j];
		ps[i].average = sum / SSIZE;
		sum = 0.0f;
	}
}

void showaverage(struct student * ps, int n)
{
	float total = 0.0f;
	printf("------------------------------------------------------\n");
	printf(" student          |score 1 |score 2 |score 3 |average \n");
	for (int i = 0; i < n; i++)
	{
		printf("%-8s %-8s ", ps[i].sname.first, ps[i].sname.last);
		for (int j = 0; j < SSIZE; j++)
		{
			printf("| %-6.2f ", ps[i].grade[j]);
			total += ps[i].grade[j];
		}
		printf("| %-6.2f \n", ps[i].average);
	}

	printf("Group average : %.2f\n", total / (n * SSIZE));
	printf("------------------------------------------------------\n");
}