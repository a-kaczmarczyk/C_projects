/* test power function adapted from Kernighan and Ritchie section 1.7
 * 
 */

#include <stdio.h>

int main()
{
	int i;
	int power(int x, int n) // raises x to the nth power, n >0	
	{
		int i, p;
		p = 1;
		for (i = 0; i <= n; ++i)
		{
			p = p * x;
		}
		return(p);
	}
	
	
	for (i = 0; i < 10; ++i)
	{
		printf("%d %d %d\n", i, power(2,i), power(-3,i));
	}
	
	
}
