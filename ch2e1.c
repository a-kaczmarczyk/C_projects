/* For exercise 2-1 from Kernighan and Ritchie
 * Rewrite the following loop without using &&
 *	for (i = 0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) 
 * 		s[i] = c;
 *  Not a real program here
 * by Demorgan's rule, A&&B = !(!A||!B) so trivially
 *	for (i = 0; !(!(i<lim-1) || !((c=getchar()) != '\n') || !(c != EOF)); ++i) 
 * 		s[i] = c;
 * With some work this simplifies to: 
 *	for (i = 0; !(i>=lim-1 || (c=getchar()) == '\n' || c = EOF); ++i) 
 * 		s[i] = c;
*/
#include <stdio.h>

int main()
{
	
}
