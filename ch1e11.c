/* Chapter 1 Exercise 11 from K&R
 Based on word counter program from Kernighan and Ritchie, referenced in exercise 1-9
 Counts lines, words and chars from text file input with words defined somewhat loosely
 Note: though the specification said that a word should be counted iff it starts with a letter, in practice this program only checks if a given character string CONTAINS a letter
*/

#include <stdio.h>
#define YES 1
#define NO 0

int main()
{
	int c, nl, nw, nc, wordflag;

	wordflag = NO;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (isalpha(c) != 0)
		{
			wordflag = YES;
		}
		else if ((c  == ' ' || c == '\n' || c == '\t') && (wordflag == YES))
		{
			++nw;
			wordflag = NO;
		}
	}
	printf("number of lines = %d\nnumber of words = %d\nnumber of characters = %d\n", nl, nw, nc);
}
