/* Fahrenheit to Celsius converter from Kernighan and Ritchie exercise 1-4
Prints a table of Fahrenheit temperatures next to their Celsius equivalents
*/
#include <stdio.h>

int main()
{
	int lower, upper, step;
	float fahr, celsius;
	
	lower = 0; // lower limit of the temperature table
	upper = 300; // upper limit
	step = 20; // step size
	
	fahr = lower;
	printf("    C    F\n"); // identifies which column corresponds to which temperature
	while(celsius <= upper) {
		fahr = ((9.0 / 5.0) * celsius) + 32;
		//celsius = (5.0 / 9.0) * (fahr - 32.0);
		//printf("%4.0f %6.1f\n", fahr, celsius);
		printf("%6.1f %4.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
	
	
}
