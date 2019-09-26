/* Word counter program from Kernighan and Ritchie, referenced in exercise 1-9
 Counts lines, words and chars from text file input with words defined somewhat loosely
*/

#include <stdio.h>
#define YES 1
#define NO 0

int main()
{
	int c, inword;

	inword = NO;
	// putchar('\b'); // failed attempt to get rid of initial newline
	while ((c = getchar()) != EOF)
	{
		if (c  == ' ' || c == '\n' || c == '\t')
			inword = NO;
		else if (inword == NO)
		{
			inword = YES;
			putchar('\n');
			putchar(c);
		}
		else
			putchar(c);
	}
	putchar('\n'); // ensures the last word of the file gets its newline too
}
