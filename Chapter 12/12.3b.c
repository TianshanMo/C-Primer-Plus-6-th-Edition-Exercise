/* Programming Exercise 12-3 */
// compile with 12.2a.c
#include <stdio.h>
#include "12.3a.h"
int main(void)
{
	int mode;
	int remode = -1;	// record recent mode
	double distance;
	double fuel;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0)
	{
		set_mode(&mode, &remode);
		if (remode != METRIC && remode != US)	// // if the first input is invalid
		{
			printf("Enter 0 for metric mode, 1 for US mode");
			printf(" (-1 to quit): ");
			scanf("%d", &mode);
			continue;
		}
		get_info(&remode, &distance, &fuel);
		show_info(&remode, &distance, &fuel);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}