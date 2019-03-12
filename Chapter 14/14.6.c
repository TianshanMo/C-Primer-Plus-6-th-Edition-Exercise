/* Programming Exercise 14-6 */

/* test data:
	4 Jessie Joybat 5 2 1 1
	10 Robert Capers 11 10 9 8
	6 William Smith 16 14 10 3
	9 Frederick Redden 2 2 0 1
	5 George Kauffman 9 6 4 3
	2 Michael Schneider 5 3 4 1
	18 Tianshan Mo 11 10 9 8
	16 Melvin Smalley 2 1 0 0
	7 Fernando Jackson 3 2 0 1
	1 Raymond Gerrity 7 6 4 3
	12 Cory Bustos 8 6 0 1
	14 Paul Smith 12 9 8 5
	10 Robert Capers 9 8 1 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 19
#define LEN 20
#define FILELEN 100

char * s_gets(char *st, int n);

struct player {
	char first[LEN];
	char last[LEN];
	int atbats;
	int hits;
	int walks;
	int RBIs;
	float battingaverage;
};

int main(void)
{
	FILE * fp;
	char filename[FILELEN];
	struct player players[RANGE];
	char first[LEN];
	char last[LEN];
	int index, atbats, hits, walks, RBIs;
	for (int i = 0; i < RANGE; i++)
		players[i] = (struct player) {"", "",0, 0, 0, 0, 0.0f };

	printf("Enter a file name:\n");
	s_gets(filename, FILELEN);
	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "I couldn't open the file \"%s\"\n", filename);
		exit(EXIT_FAILURE);
	}

	while (fscanf(fp, "%d %s %s %d %d %d %d",
		&index, first, last, &atbats, &hits, &walks, &RBIs) == 7)
	{
		strncpy(players[index].first, first, LEN);
		strncpy(players[index].last, last, LEN);
		players[index].atbats += atbats;
		players[index].hits += hits;
		players[index].walks += walks;
		players[index].RBIs += RBIs;
	}
	fclose(fp);

	for (int i = 0; i < RANGE; i++)
		if (strlen(players[i].first) != 0)
			players[i].battingaverage = (float)players[i].hits / (float)players[i].atbats;

	printf("-----------------------------------------------------------------\n");
	printf("Statics: \n");
	printf("| name:                |times |hits |walks |RBIs |batting average\n");
	for (int i = 0; i < RANGE; i++)
		if (strlen(players[i].first) != 0)
			printf("|%-10s %-10s: %-5d  %-5d %-5d  %-5d %-5.2f\n",
				players[i].first, players[i].last, players[i].atbats,
				players[i].hits, players[i].walks, players[i].RBIs,
				players[i].battingaverage);
	printf("-----------------------------------------------------------------\n");
	
	return 0;
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