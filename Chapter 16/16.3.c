/* Programming Exercise 16-3 */
#include <stdio.h>
#include <math.h>
#define PI 3.141592

struct polar {
	double length;
	double angle;
};

struct rectangular {
	double x;
	double y;
};

struct rectangular ptor(struct polar input);

int main(void)
{
	struct polar input;
	struct rectangular output;

	printf("Enter length and angle in degrees: ");
	while (scanf("%lf %lf", &input.length, &input.angle) == 2)
	{
		output = ptor(input);
		printf("rectangular: x: %f, y: %f\n", output.x, output.y);
		printf("Enter length and angle in degrees (q to quit): ");
	}
}

struct rectangular ptor(struct polar input)
{
	struct rectangular temp;
	double ang = PI / 180 * input.angle;
	temp.x = input.length * sin(ang);
	temp.y = input.length * cos(ang);

	return temp;
}