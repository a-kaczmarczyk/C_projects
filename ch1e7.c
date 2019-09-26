/* For exercise 1-7 of Kernighan and Ritchie
 Reads a textfile and copies input textfile to output, removing redundant blank spaces
*/
#include <stdio.h>

int main()
{
	int c, flag;
	flag = 0; // flag for identifying last nonblank character before a blank
	
	while((c = getchar()) != EOF)
	{		
		if(c != ' ')
		{
			putchar(c);
			flag = 1;
		}
		else if(c == ' ' && flag == 1)
		{
			putchar(c);
			flag = 0;
		}	
		else
			flag = 0;
	}

}
