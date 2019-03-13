/* Programming Exercise 15-7 */
#include <stdio.h>
#include <stdbool.h>

#define IDMASK         0xFF000000
#define IDSHIFT        24
#define SIZEMASK       0x00FE0000
#define SIZESHIFT      17
#define ALIGNMENTMASK  0x0000C000
#define ALIGNMENTSHIFT 14
#define BOLDMASK       0x00000004
#define BOLDSHIFT      2
#define ITALICMASK     0x00000002
#define ITALICSHIFT    1
#define UNDERLINEMASK  0x00000001
#define UNDERLINESHIFT 0
#define LEFT   0
#define CENTER 1
#define RIGHT  2

void showfont(const unsigned long font);
void showmenu(void);
void change_font(unsigned long * pfont);
void change_size(unsigned long * pfont);
void change_alignment(unsigned long * pfont);
void clearinput(void);

int main(void)
{
	unsigned long font;

	font = 0x1180000;

	char choice;
	showfont(font);
	showmenu();
	while ((choice = getchar()) != 'q')
	{
		clearinput();
		switch (choice)
		{
		case 'f': change_font(&font);
			break;
		case 's': change_size(&font);
			break;
		case 'a': change_alignment(&font);
			break;
		case 'b': font ^= BOLDMASK;
			break;
		case 'i': font ^= ITALICMASK;
			break;
		case 'u': font ^= UNDERLINEMASK;
			break;
		default: printf("Invalid input, enter again: ");
			choice = 'q';
			break;
		}
		if (choice == 'q')
			continue;
		
		showfont(font);
		showmenu();
	}

	return 0;
}

void showfont(const unsigned long font)
{
	unsigned int id = (font & IDMASK) >> IDSHIFT;
	unsigned int size = (font & SIZEMASK) >> SIZESHIFT;
	unsigned int alignment = (font & ALIGNMENTMASK) >> ALIGNMENTSHIFT;
	bool bold = (font & BOLDMASK) >> BOLDSHIFT;
	bool italic = (font & ITALICMASK) >> ITALICSHIFT;
	bool underline = (font & UNDERLINEMASK) >> UNDERLINESHIFT;
	
	printf("\n  ID SIZE ALIGNMENT   B   I   U\n");
	printf("%4u %4u ", id, size);
	if (alignment == 0)
		printf("  left    ");
	else if (alignment == 1)
		printf(" center   ");
	else
		printf(" right    ");
	printf("%s", (bold == 0) ? " off" : "  on");
	printf("%s", (italic == 0) ? " off" : "  on");
	printf("%s\n", (underline == 0) ? " off" : "  on");
}

void showmenu(void)
{
	puts("f)change fonts	s)change size 	 a)change alignment");
	puts("b)toggle bold 	i)toggle italic  u)toggle underline");
	puts("q)quit");
}

void change_font(unsigned long * pfont)
{
	unsigned long id;
	printf("Enter font id (0 - 255): ");
	while (scanf("%lu", &id) == 1)
	{
		if (id < 0 || id > 255)
		{
			printf("Invalid input, enter again: ");
			continue;
		}
		id <<= IDSHIFT;
		*pfont = (*pfont) & ~IDMASK;
		*pfont |= id;

		break;
	}
	clearinput();
}

void change_size(unsigned long * pfont)
{
	unsigned long size;
	printf("Enter font size (0 - 127): ");
	while (scanf("%lu", &size) == 1)
	{
		if (size < 0 || size > 127)
		{
			printf("Invalid input, enter again: ");
			continue;
		}
		size <<= SIZESHIFT;
		*pfont = (*pfont) & ~SIZEMASK;
		*pfont |= size;

		break;
	}
	clearinput();
}

void change_alignment(unsigned long * pfont)
{
	char ch;
	unsigned long alignment;
	puts("Select alignment:");
	puts("l)left   c)center   r)right");
	while (ch = getchar())
	{
		if ((ch != 'l') && (ch != 'c') && (ch != 'r'))
		{
			printf("Invalid input, enter again: ");
			continue;
		}
		*pfont = (*pfont) & ~ALIGNMENTMASK;
		switch (ch)
		{
		case 'l': alignment = LEFT;
			      alignment <<= ALIGNMENTSHIFT;
			      *pfont |= alignment;
			break;
		case 'c': alignment = CENTER;
			      alignment <<= ALIGNMENTSHIFT;
			      *pfont |= alignment;
			break;
		case 'r': alignment = RIGHT;
			      alignment <<= ALIGNMENTSHIFT;
			      *pfont |= alignment;
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