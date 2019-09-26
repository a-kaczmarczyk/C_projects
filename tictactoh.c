/* Tic-tac-toh game for two human players
 * Testbed for board game related functions
 */

#include <stdio.h>
#define BOARDSIZE 4 // defines the length of the board's sides, in squares
int boardstatus[BOARDSIZE][BOARDSIZE]; // keeps track of 

void clearboard() // zeroes all elements of the board
{
	int i, j;
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			boardstatus[i][j] = 0;
		}
	}
}

void numboard() // assigns a unique number to elements of the board
{
	int i, j, k;
	k = 1;
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			boardstatus[i][j] = k;
			k++;
		}
	}
}

void drawboard() // draws the board in the terminal
{
	int i, j;
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			printf("%d\t", boardstatus[i][j]);
		}
		printf("\n");
	}
}

void drawboardttt() // draws the board in the terminal, substituting O for -1 and X for -2
{
	int i, j;
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			if (boardstatus[i][j] == -1)
			{
				printf("O\t");
			}
			
			else if (boardstatus[i][j] == -2)
			{
				printf("X\t");
			}
			else
			{
				printf("%d\t", boardstatus[i][j]);
			}
		}
		printf("\n");
	}
}

void placetile(int i, int j, int p) // on the board, places a value p at the tile i,j  
{
	boardstatus[i][j] = p;
}

int horizcontig(int i) // returns true if all values in the ith row are the same
{
	int j, iscontig;
	iscontig = 1; 
	for (j = 0; j < BOARDSIZE; j++)
	{
		iscontig = iscontig * (boardstatus[i][0] == boardstatus[i][j]);
	}
	return iscontig; 
}

int vertcontig(int j) // returns true if all values in the jth column are the same
{
	int i, iscontig;
	iscontig = 1; 
	for (i = 0; i < BOARDSIZE; i++)
	{
		iscontig = iscontig * (boardstatus[0][j] == boardstatus[i][j]);
	}
	return iscontig; 
}

int udiagcontig() // returns true if all values in the diagonal [0][0] to [BOARDSIZE - 1][BOARDSIZE - 1] are the same
{
	int i, j, iscontig;
	iscontig = 1; 
	for (i = 0, j = 0; i < BOARDSIZE; i++, j++)
	{
		iscontig = iscontig * (boardstatus[0][0] == boardstatus[i][j]);
	}
	return iscontig; 
}

int ldiagcontig() // returns true if all values in the diagonal [BOARDSIZE - 1][0] to [0][BOARDSIZE - 1] are the same
{
	int i, j, iscontig;
	iscontig = 1; 
	for (i = (BOARDSIZE - 1), j = 0; j < BOARDSIZE; i--, j++)
	{
		iscontig = iscontig * (boardstatus[BOARDSIZE - 1][0] == boardstatus[i][j]);
	}
	return iscontig; 
}

int victorycond() // returns true if an unbroken line of equal values crosses the whole length of the board in a horizontal, vertical or diagonal direction
{
	int i, j, vict;
	vict = 0;
	for (i = 0; i < BOARDSIZE; i++)
	{
		if (horizcontig(i))
			vict = 1; 
	}
	for (j = 0; j < BOARDSIZE; j++)
	{
		if (vertcontig(j))
			vict = 1;
	}
	if (udiagcontig() || ldiagcontig())
	{
		vict = 1;
	}
	return vict; 
}

int tilesearch(int n) // searches for n on the board, returning true if n is found
{
	int i, j, found;
	found = 0;
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			if(boardstatus[i][j] == n)
			{
				found = 1;
				return found;
			}
			
			/*else
			{
				found = 0;
			}*/
		}
	}
	return found;
}

int gettile(int n, int *r, int *c) // searches for n on the board, returning true if n is found and updating *r and *c to the values of the found tile's row and column
{ // this function is the first time I understood pointers!
	int i, j, found;
	found = 0;
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (j = 0; j < BOARDSIZE; j++)
		{
			if(boardstatus[i][j] == n)
			{
				found = 1;
				*r = i;
				*c = j;
				return found;
			}
			
			/*else
			{
				found = 0;
			}*/
		}
	}
	return found;
}

int main()
{
	int turnnumber = 1;
	int row, column, value, tilenum;
	clearboard();
	numboard();
	//placetile(1,1,3);
	drawboard();
	/*for (int i = 0; i < 5; i++)
	{
		int row, column, value;
		printf("Enter row number: ");
		scanf("%d", &row);
		printf("Enter column number: ");
		scanf("%d", &column);
		printf("Enter a number: ");
		scanf("%d", &value);
		placetile(row, column, value);
		drawboard();
	} */
	
	while(victorycond() == 0)
	{
		printf("\nTurn number %d\n\n", turnnumber);
		printf("Enter the tile number: ");
		scanf("%d", &tilenum);
		gettile(tilenum, &row, &column);
		value = -1 * (turnnumber%2) - 1;
		placetile(row, column, value);
		drawboardttt();
		turnnumber++;
	}
	
	return 0;
}
