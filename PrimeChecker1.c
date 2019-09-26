/* Checks if an input integer is prime or not
 * Adrian Kaczmarczyk April 8th 2017
 */

#include <stdio.h>
int max = 1000;
int innum = 0;
int primeflag = 1;
int main()
{
	printf("Input to check for primacy: ");
	scanf("%d", &innum);
	int i;
	for (i = 2; i < innum; i++)
	{
		primeflag = primeflag*(innum%i);
		if (primeflag != 0) // resets primeflag to 1 to prevent overflow errors
		{
			primeflag = 1;
		}
		
	}
	
	if (primeflag != 0)
	{
		printf("The number is prime!\n");
	}
	else
	{
		printf("The number is not prime.\n");
	}
	
}
