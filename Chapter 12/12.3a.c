#include <stdio.h>
#include "12.3a.h"

void set_mode(int * mode, int * remode)
{
	if (*mode != METRIC && *mode != US) // if the first input is invalid
	{
		char * s = NULL;
		if (*remode == METRIC)
			s = "METRIC";
		else if (*remode == US)
			s = "US";
		printf("Invalid mode specified. Mode %d(%s) used\n",
			*remode, s);
	}
	else
		*remode = *mode;
}

void get_info(int * remode, double * distance, double * fuel)
{
	/* Input distance */
	if (*remode == METRIC)
		printf("Enter distance traveled in kilometers: ");
	else
		printf("Enter distance traveled in miles: ");
	while (scanf("%lf", distance) != 1)
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid input. Please re-enter:");
	}
	while (getchar() != '\n')
		continue;

	/* Input fuel consumption */
	if (*remode == METRIC)
		printf("Enter fuel consumed in liters: ");
	else
		printf("Enter fuel consumed in gallons: ");
	while (scanf("%lf", fuel) != 1)
	{
		while (getchar() != '\n')
			continue;
		printf("Invalid input. Please re-enter:");
	}
	while (getchar() != '\n')
		continue;
}

void show_info(int * remode, double * distance, double * fuel)
{
	double consumption;
	if (*remode == METRIC)
	{
		consumption = 100.0 * (*fuel) / (*distance);
		printf("Fuel consumption is %.2f liters per 100 km.\n", consumption);
	}
	else
	{
		consumption = (*distance) / (*fuel);
		printf("Fuel consumption is %.1f miles per gallon.\n", consumption);
	}
}