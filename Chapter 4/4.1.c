/* Programming Exercise 4-1 */
#include <stdio.h>
int main(void)
{
	char first_name[40];
	char last_name[40];
	printf("Enter your first name:");
	scanf("%s", first_name);
	printf("Enter your last name:");
	scanf("%s", last_name);
	printf("%s %s\n", first_name, last_name);

	return 0;
}