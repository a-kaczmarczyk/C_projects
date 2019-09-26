/* For exercise 1-8 of Kernighan and Ritchie
 Reads a textfile and copies input textfile to output, replacing tabs and backspaces with visible characters
*/
#include <stdio.h>

int main()
{
	int c;
	
	while((c = getchar()) != EOF)
	{		
		if(c == '\t')
		{
			printf("-\b>");
		}
		else if(c == '\b')
		{
			printf("-\b<");
		}	
		else
			putchar(c);
	}

}
