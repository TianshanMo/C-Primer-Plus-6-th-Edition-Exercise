/* Programming Exercise 11-11 */
#include <stdio.h>
#include <string.h>
#define SIZE 80
#define LIM 10

void menu(void);
void OriginSort(char * target[], char (*source)[SIZE], int num);
void ASCIISort(char *st[], int num);
void LengthSort(char *st[], int num);
void WordSort(char *st[], int num);
int WordLen(char * st);
char * s_gets(char * st, int n);

int main(void)
{
	char input[LIM][SIZE];
	char * ptstr[LIM];
	int ct = 0;
	int k;
	char choice;
	printf("Enter 10 strings, or EOF to quit:\n");
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL)
	{
		ptstr[ct] = input[ct];
		ct++;
	}

	menu();

	while ((choice = getchar()) != 'q')
	{
		if (choice != '\n')
			while (getchar() != '\n')
				continue;
		switch (choice)
		{
		case 'a':
			OriginSort(ptstr, input, ct);
			break;
		case 'b':
			ASCIISort(ptstr, ct);
			break;
		case 'c':
			LengthSort(ptstr, ct);
			break;
		case 'd':
			WordSort(ptstr, ct);
			break;
		default:
			puts("Input errors, please re_enter:");
			break;
		}
		puts(" Here's the sorted list:");
		puts("-------------------------");
		for (k = 0; k < ct; k++)
			puts(ptstr[k]);
		puts("-------------------------\n");
		menu();
	}
	puts("Done");

	return 0;
}

void OriginSort(char * target[], char(*source)[SIZE], int num) 
{
	for (int i = 0; i < num; i++)
		target[i] = source[i];
}


void ASCIISort(char *st[], int num)
{
	char * temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strcmp(st[top], st[seek]) > 0)
			{
				temp = st[top];
				st[top] = st[seek];
				st[seek] = temp;
			}
}

void LengthSort(char *st[], int num)
{
	char * temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strlen(st[top]) > strlen(st[seek]))
			{
				temp = st[top];
				st[top] = st[seek];
				st[seek] = temp;
			}
}

void WordSort(char *st[], int num)
{
	char * temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (WordLen(st[top]) > WordLen(st[seek]))
			{
				temp = st[top];
				st[top] = st[seek];
				st[seek] = temp;
			}
}

int WordLen(char * st)
{
	int length = 0;
	int i = 0;
	while (st[i] == ' ')
		i++;

	while (st[i] != ' ' && st[i] != '\0')
	{
		i++;
		length++;
	}

	return length;
}

void menu(void)
{
	puts("****************************************************************************");
	puts("Enter the operation of your choice:");
	puts(" a. Print the original list of strings");
	puts(" b. Print the strings in ASCII collating sequence");
	puts(" c. Print the strings in order of increasing length");
	puts(" d. Print the strings in order of the length of the first word in the string");
	puts(" q. quit");
	puts("****************************************************************************");
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
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}





















































/* Easter Eggs!
学业有成，事业进步，收获爱情，阿弥陀佛阿弥陀佛

祝福福福福福福福福福福福福福福福福福福福福福福福福
福福　　福福福福福福福福　　　　　　　　　　福福福
福福福　　福福福福福福福福福福福福福福福福福福福福
福　　　　　　　　福福福　　　　　　　　　　福福福
福　　　　　　　　福福福　福福福福福福福福　福福福
福福福福福福　　福福福福　福福福福福福福福　福福福
福福福福福　　福福福福福　　　　　　　　　　福福福
福福福福　　福福福福福福福福福福福福福福福福福福福
福福福　　　　福福福福　　　　　　　　　　　　福福
福福　　福　　　　福福　福福福福　　福福福福　福福
福　　福福　　福　　福　福福福福　　福福福福　福福
福福福福福　　福福福福　　　　　　　　　　　　福福
福福福福福　　福福福福　福福福福　　福福福福　福福
福福福福福　　福福福福　福福福福　　福福福福　福福
福福福福福　　福福福福　　　　　　　　　　　　福福
福福福福福福福福福福福福福福福福福福福福福福福福福

*/