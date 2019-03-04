#include <stdio.h>
#include "12.2a.h"

static int mode = -1;	// if the first input is invalid
static double distance;
static double fuel;

void set_mode(int choice)
{
	if (choice != METRIC && choice != US) // if the first input is invalid
	{
		char * s = NULL;
		if (mode == METRIC)
			s = "METRIC";
		else if (mode == US)
			s = "US";
		printf("Invalid mode specified. Mode %d(%s) used\n",
			 mode, s);
	}
	else
		mode = choice;
}

void get_info(void)
{
	if ((mode == METRIC) || (mode == US))
	{
		/* Input distance */
		if (mode == METRIC)
			printf("Enter distance traveled in kilometers: ");
		else
			printf("Enter distance traveled in miles: ");
		while (scanf("%lf", &distance) != 1)
		{
			while (getchar() != '\n')
				continue;
			printf("Invalid input. Please re-enter:");
		}
		while (getchar() != '\n')
			continue;

		/* Input fuel consumption */
		if (mode == METRIC)
			printf("Enter fuel consumed in liters: ");
		else
			printf("Enter fuel consumed in gallons: ");
		while (scanf("%lf", &fuel) != 1)
		{
			while (getchar() != '\n')
				continue;
			printf("Invalid input. Please re-enter:");
		}
		while (getchar() != '\n')
			continue;
	}
}

void show_info(void)
{
	double consumption;
	if (mode == METRIC || mode == US)
	{
		if (mode == METRIC)
		{
			consumption = 100.0 * fuel / distance;
			printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
		}
		else
		{
			consumption = distance / fuel;
			printf("Fuel consumption is %.1f miles per gallon.\n", consumption);
		}
	}
}