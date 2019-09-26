/* Chapter 1 Exercise 12 from K&R
 Based on word counter program I wrote for Kernighan and Ritchie exercise 1-11 (ch1e11.c)
 Creates a histogram of word lengths in the input
*/

#include <stdio.h>
#define YES 1
#define NO 0
#define HISTLEN 20

int main()
{
	int c, i, wordflag, lcount;
	int hist[HISTLEN]; // each array entry hist[n] is the number of words of n+1 characters, with the last entry reserved for overflow
	
	wordflag = NO;
	i = lcount = 0;
	
	for (i = 0; i < HISTLEN; i++) // initializes hist's values to 0
		hist[i] = 0; 
	
	while ((c = getchar()) != EOF)
	{
		if (isalpha(c) != 0)
		{
			wordflag = YES;
			++lcount;
		}
		else if ((c  == ' ' || c == '\n' || c == '\t') && (wordflag == YES))
		{
			if (lcount < HISTLEN)
			{
				hist[lcount - 1]++;
			}
			else if (lcount >= HISTLEN)
			{
				hist[HISTLEN - 1]++;
			}
			lcount = 0; // resets letter count
			wordflag = NO;
		}
	}
	printf("Word Length | Number of Occurences\n");
	for (i = 0; i < HISTLEN; i++)
	{
		printf("%d             %d\n", i + 1, hist[i]);
	}
	
}
