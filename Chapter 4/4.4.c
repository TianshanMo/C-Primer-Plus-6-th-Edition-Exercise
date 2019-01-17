/* Programming Exercise 4-4 */
#include <stdio.h>
int main(void)
{
	float height;
	char name[40];
	printf("Enter the height in inches:");
	scanf("%f", &height);
	printf("Enter your name:");
	scanf("%s", name);
	printf("%s, you are %.3f feet tall.\n", name, height);

	return 0;
}