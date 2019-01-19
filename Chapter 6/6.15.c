/* Programming Exercise 6-15 */
#include <stdio.h>
int main(void)
{
	char array[255];
	int count = 0;
	printf("Enter a string: \n");
	while ((scanf("%c", &array[count])) && (array[count] != '\n'))
		count++;

	while (count >= 0)
	{
		printf("%c", array[count]);
		count--;
	}
	printf("\n");

	return 0;
}