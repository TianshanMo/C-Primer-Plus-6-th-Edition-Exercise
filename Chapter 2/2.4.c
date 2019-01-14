/* Programming Exercise 2-4 */
#include<stdio.h>
void jolly(void);	// the first "void" in the prototype for the function indicates that the function doesn't have a return value.
					// the second "void" in the prototype for the function indicates that the function has no arguments.
void deny(void);
int main(void)		// "int" means that the kind of value "main()" can return is an interger.
{
	jolly();
	jolly();
	jolly();
	deny();

	return 0;
}

void jolly(void)
{
	printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
	printf("Which nobody can deny!\n");
}