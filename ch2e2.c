/* For exercise 2-2 from Kernighan and Ritchie
 * This program includes the function hoti(s) which converts a string of hexadecimal digits to its equivalent integer value. 
 * doesn't work!
*/
#include <stdio.h>

int lower(int c) // ASCII only, from K&R pg 40
{
	if(c >= 'A' && c <= 'Z')
		return(c + 'a' - 'A');
	else
		return(c);
}

int htoisingle(int c) // converts singular hexadecimal digit to decimal equivalent
{
	if(c >= 'A' && c <= 'Z') // lowercase the capitals
	{
		c = lower(c);
		return(htoisingle(c));
	}
	else if(c >= 'a' && c <= 'z')
	{
		c = (c - 'a');
		return(c);
	} 
	else
		return(c);
}

int test(int c)
{
	return(c - 'a');
}

int ctoi(char c)
{
	return(c);
}

char itoc(int c)
{
	return(c);
}

int main()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", itoc(a));
}
