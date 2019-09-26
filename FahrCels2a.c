/* Fahrenheit to Celsius converter from Kernighan and Ritchie exercise 1-5
Prints a table of Fahrenheit temperatures next to their Celsius equivalents
*/
#include <stdio.h>

int main()
{
	int fahr;
	
	printf("   F    C\n"); // identifies which column corresponds to which temperature
	for(fahr = 300; fahr >= 0; fahr = fahr - 20)
		printf("%4d %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0));	
}
