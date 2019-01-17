/* Programming Exercise 4-2 */
#include <stdio.h>
#include <string.h>
int main(void)
{
	char first_name[20];
	int name_length;
	
	printf("Enter your first name:");
	scanf("%s", first_name);
	name_length = strlen(first_name);
	printf("a.\"%s\"\n", first_name);
	printf("b.\"%20s\"\n", first_name);
	printf("c.\"%-20s\"\n", first_name);
	printf("d.\"%*s\"\n", name_length + 3, first_name);

	return 0;
}