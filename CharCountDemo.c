/* Character counter from section 1.5 of Kernighan and Ritchie
*/
#include <stdio.h>

int main()
{
	long nc; 
	nc = 0;
	while(getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
