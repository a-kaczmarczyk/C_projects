/* Fahrenheit to Celsius converter from Kernighan and Ritchie Section 1.4
Prints a table of Fahrenheit temperatures next to their Celsius equivalents
*/
#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
	int fahr;
	
	printf("   F    C\n"); // identifies which column corresponds to which temperature
	for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%4d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));	
}
