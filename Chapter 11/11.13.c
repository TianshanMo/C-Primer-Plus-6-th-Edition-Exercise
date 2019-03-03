/* Programming Exercise 11-13 */
#include <stdio.h>
int main(int argc, char *argv[])
{
	int i;
	if (argc < 2)
		printf("Command-line arguments not accpeted.");
	else
		for (i = argc; i > 0; i--)
			printf("%s ", argv[i]);

	return 0;
}