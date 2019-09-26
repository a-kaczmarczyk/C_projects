/* For K&R Chapter 1 exercise 15, takes a textfile as input and prints all lines longer than 80 characters
 * Adapted from Kernighan & Ritchie section 1.9
 * finds the longest line in a textfile
 * note that a line length of 0 characters indicates EOF, within a file even a blank line still contains a single newline character
*/

#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int getLine(char s[], int lim) // get line into s, return length
{
		int c, i;
		for (i = 0; i < (lim-1) && ((c = getchar()) != EOF) && (c != '\n'); ++i)
		{
			s[i] = c;
		}
		if (c == '\n')
		{
			s[i] = c;
			++i;
		}
		s[i] = '\0';
		return(i);
}

void copy(char s1[], char s2[]) // copies s1 to s2, assuming s2 is big enough
{
	int i;
	i = 0;
	while ((s2[i] = s1[i]) != '\0')
	{
		++i;
	}	
}

int main()
{
	int len; // current line length
	int max; // maximum line length seen so far
	char line[MAXLINE]; // current input line
	char save[MAXLINE]; // longest line, saved
	
	max = 0; // initializes max
	
	while ((len = getLine(line, MAXLINE)) > 0)
	{
		if (len >= 80)
		{
			printf("%s\n", line);
		}
		
		if (len > max)
		{
			max = len;
			copy(line,save);
		}
		
	}
	/*if (max > 0) // prints the longest saved line, provided the line isn't EOF
	{
		printf("%s", save);
	} */
	
}

