/* Programming Exercise 15-6 */
#include <stdio.h>
#include <stdbool.h>

#define LEFT   0
#define CENTER 1
#define RIGHT  2
#define ON  1
#define OFF 0
#define IDMASK 0xff
#define SIZEMASK 0x7f

struct font {
	unsigned int Font_ID : 8;
	unsigned int Font_SIZE : 7;
	unsigned int : 1;
	unsigned int Alignment : 2;
	bool Bold : 1;
	bool Italic : 1;
	bool Underline : 1;
};

void showfont(struct font font_1);
void showmenu(void);
void change_font(struct font * pfont);
void change_size(struct font * pfont);
void change_alignment(struct font * pfont);
void clearinput(void);

int main(void)
{
	struct font font_1 = { 1, 12, LEFT , OFF, OFF, OFF };
	char choice;
	showfont(font_1);
	showmenu();
	while ((choice = getchar()) != 'q')
	{
		clearinput();
		switch (choice)
		{
		case 'f': change_font(&font_1);
			break;
		case 's': change_size(&font_1);
			break;
		case 'a': change_alignment(&font_1);
			break;
		case 'b': font_1.Bold = ~font_1.Bold;
			break;
		case 'i': font_1.Italic = ~font_1.Italic;
			break;
		case 'u': font_1.Underline = ~font_1.Underline;
			break;
		default: printf("Invalid input, enter again: ");
			     choice = 'q';
			break;
		}
		if (choice == 'q')
			continue;
		showfont(font_1);
		showmenu();
	}

	return 0;
}

void showfont(struct font font_1)
{
	printf("\n  ID SIZE ALIGNMENT   B   I   U\n");
	printf("%4u %4u ", font_1.Font_ID, font_1.Font_SIZE);
	if (font_1.Alignment == 0)
		printf("  left    ");
	else if (font_1.Alignment == 1)
		printf(" center   ");
	else
		printf(" right    ");
	printf("%s", (font_1.Bold == 0) ? " off" : "  on");
	printf("%s", (font_1.Italic == 0) ? " off" : "  on");
	printf("%s\n", (font_1.Underline == 0) ? " off" : "  on");
}

void showmenu(void)
{
	puts("f)change fonts	s)change size 	 a)change alignment");
	puts("b)toggle bold 	i)toggle italic  u)toggle underline");
	puts("q)quit");
}

void change_font(struct font * pfont)
{
	int id;
	printf("Enter font id (0 - 255): ");
	while (scanf("%d", &id) == 1)
	{
		if (id < 0 || id > 255)
		{
			printf("Invalid input, enter again: ");
			continue;
		}
		pfont->Font_ID = id & IDMASK;
		break;
	}
	clearinput();
}

void change_size(struct font * pfont)
{
	int size;
	printf("Enter font size (0 - 127): ");
	while (scanf("%d", &size) == 1)
	{
		if (size < 0 || size > 127)
		{
			printf("Invalid input, enter again: ");
			continue;
		}
		pfont->Font_SIZE = size & SIZEMASK;
		break;
	}
	clearinput();
}

void change_alignment(struct font * pfont)
{
	char ch;
	puts("Select alignment:");
	puts("l)left   c)center   r)right");
	while (ch = getchar())
	{
		if ((ch != 'l') && (ch != 'c') && (ch != 'r'))
		{
			printf("Invalid input, enter again: ");
			continue;
		}
		switch (ch)
		{
		case 'l': pfont->Alignment = LEFT;
			break;
		case 'c': pfont->Alignment = CENTER;
			break;
		case 'r': pfont->Alignment = RIGHT;
			break;
		}
		break;
	}
	clearinput();
}

void clearinput(void)
{
	while (getchar() != '\n')
		continue;
}