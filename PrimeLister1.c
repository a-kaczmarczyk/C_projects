/* Generates a list of primes
 * Adrian Kaczmarczyk April 8th 2017
 */

#include <stdio.h>
int max = 100;
int innum = 0;
int count = 0;
int main()
{
	printf("Number of primes to generate: ");
	scanf("%d", &max);
	for (innum = 2; count < max; innum++)
	{
		//printf("%d ", innum);
		int primeflag = 1;
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
			printf("%d, ", innum);
			count++;
		}
	}
	printf("\b\b \n");
}
