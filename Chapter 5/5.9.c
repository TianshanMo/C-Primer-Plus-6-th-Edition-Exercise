/* Programming Exercise 5-9 */
#include <stdio.h>

void Temperatures(double degrees_Fahrenheit);			// prototype declaration of Temperatures

int main(void)
{
	
	double degrees_Fahrenheit;
	printf("Enter a degree Fahrenheit(q to quit): ");
	
	/* continue executing loop if user enters valid number */
	while (scanf("%lf", &degrees_Fahrenheit) == 1)
	{
		/* convert degree Fahrenheit to degree celsius and degree kelvin */
		Temperatures(degrees_Fahrenheit);
	}
	printf("Done\n");

	return 0;
}

void Temperatures(double degrees_Fahrenheit)
{
	const double C2M = 273.16;
	const double F2C_SCALE = 5.0 / 9.0;
	const double F2C_OFFSET = -32;
	double degrees_Celsius;
	double degrees_Kelvins;
	degrees_Celsius = F2C_SCALE * (degrees_Fahrenheit + F2C_OFFSET);
	degrees_Kelvins = degrees_Celsius + C2M;
	printf("%.2f degree Fahrenheit = %.2f degree Celsius = %.2f degree Kelvins.\n",
		degrees_Fahrenheit, degrees_Celsius, degrees_Kelvins);
	/* prompt for new input */
	printf("Enter a degree Fahrenheit(q to quit): ");
}