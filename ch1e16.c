/* For K&R Chapter 1 exercise 16, takes a textfile as input and removes all trailing blanks and tabs, as well as entirely blank lines
 * Adapted from Kernighan & Ritchie section 1.9
 * finds the longest line in a textfile
 * note that a line length of 0 characters indicates EOF, within a file even a blank line still contains a single newline character
*/
#define MAXLINE 1000 // maximum input line size
#include <stdio.h>
int endflag = 0; // flag to signal line end
int blankchar = 0; // number of trailing blank characters

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

void modcopy(char s1[], char s2[]) // copies s1 to s2, stripping s2 of its trailing blanks and tabs
{
	int i;
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
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
	if (max > 0) // prints the longest saved line, provided the line isn't EOF
	{
		printf("%s", save);
	}
	
}

