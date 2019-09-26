/* Word counter program from Kernighan and Ritchie, referenced in exercise 1-9
 Counts lines, words and chars from text file input with words defined somewhat loosely
*/

#include <stdio.h>
#define YES 1
#define NO 0

int main()
{
	int c, nl, nw, nc, inword;

	inword = NO;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c  == ' ' || c == '\n' || c == '\t')
			inword = NO;
		else if (inword == NO)
		{
			inword = YES;
			++nw;
		}
		
	}
	printf("number of lines = %d\nnumber of words = %d\nnumber of characters = %d\n", nl, nw, nc);
}
