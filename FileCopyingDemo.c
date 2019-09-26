/* Example program from Kernighan and Ritchie Section 1.5 
 getchar/putchar demo for file copying, it echos input from the terminal until (-1) is intered
*/

#include <stdio.h> 
#define EOF (-1)

int main()
{
	int c;
	c = getchar();
	while(c != EOF)
	{
		putchar(c);
		c = getchar(); 
	}

}
