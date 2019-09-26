/* Chapter 1 Exercise 13 from K&R
 Copies input to output, replacing all capital letters with their lowercase equivalents
*/

#include <stdio.h>
#define YES 1
#define NO 0

int lower(int n)
	{
		if (n >= 'A' && n <= 'Z')
		{
			return(n + 32);
		}
		else
		{
			return(n);
		}
	}
	
int main()
{
	int c;

	while ((c = getchar()) != EOF)
	{
		putchar(lower(c));
	}
}

