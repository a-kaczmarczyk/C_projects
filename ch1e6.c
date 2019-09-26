/* For exercise 1-6 
 Reads a textfile and separately counts the number of blanks, tabs and newlines
 
 Character counter from section 1.5 of Kernighan and Ritchie
*/
#include <stdio.h>

int main()
{
	int c, blankCount, tabCount, lineCount;
	blankCount = 0; 
	tabCount = 0;
	lineCount = 0;
	
	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			++blankCount;
		if(c == '\t')
			++tabCount;
		if(c == '\n')
			++lineCount;
	}

	printf("number of blanks = %d\n", blankCount);
	printf("number of tabs = %d\n", tabCount);
	printf("number of newlines = %d\n", lineCount);
}
