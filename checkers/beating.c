#include "beating.h"
#include "definitions.h"



int jumpOverOpponent(int tab[8][8], int COLOR, int x, int y, int i, int j)
{
	int opponent;
	if (COLOR == WHITE) opponent = BLACK;
	else opponent = WHITE;

	if (((y - j == 2 * DOWN) || (y - j == 2 * UP)) && ((x - i == 2 * RIGHT) || (x - i == 2 * LEFT))) 
	{
		// Check if opponent's man is jumped over
		if (x - i > 0 && y - j > 0) // RIGHT DOWN
		{
			if (tab[y - 1][x - 1] == opponent)
			{
				tab[y - 1][x - 1] = BLANKSPOT;
				tab[j][i] = BLANKSPOT;	// old possition
				tab[y][x] = COLOR; // new MAN possition


				return 1;
			}
		}
		else if (x - i < 0 && y - j > 0)// LEFT DOWN
		{
			if (tab[y - 1][x + 1] == opponent)
			{
				tab[y - 1][x + 1] = BLANKSPOT;
				tab[j][i] = BLANKSPOT;	// new MAN possition
				tab[y][x] = COLOR; // old possition

				return 1;
			}
		}
		else if (x - i > 0 && y - j < 0)// RIGHT UP
		{
			if (tab[y + 1][x - 1] == opponent)
			{
				tab[y + 1][x - 1] = BLANKSPOT;
				tab[j][i] = BLANKSPOT;	// new MAN possition
				tab[y][x] = COLOR; // old possition

				return 1;
			}
		}
		else							// LEFT UP
			if (tab[y + 1][x + 1] == opponent)
			{
				tab[y + 1][x + 1] = BLANKSPOT;
				tab[j][i] = BLANKSPOT;	// new MAN possition
				tab[y][x] = COLOR; // old possition

				return 1;
			}
	}
	return 0;
}
void haveToBeat(int tab[8][8], int x, int y, int player)	
{
	int horizontalMove[4] = { RIGHT, LEFT, RIGHT, LEFT };
	int verticalMove[4] = { DOWN, DOWN, UP, UP };
	int newX = x;
	int newY = y;
	for (int s = 0; s < 4; s++)
	{
		if (stillOnTheBoard(tab, x, y, 2 * horizontalMove[s], 2 * verticalMove[s]))
			if (opponentsMan(tab, x, y, horizontalMove[s], verticalMove[s], player))
				if (blankSpot(tab, x, y, 2 * horizontalMove[s], 2 * verticalMove[s]))
				{
					do {
						ArrowControl(tab, player, &newX, &newY, "Have to beat");
					} while (!((newX == x + 2 * horizontalMove[s]) && (newY = y + 2 * verticalMove[s])));
					tab[y][x] = BLANKSPOT;	// old possition
					tab[newY][newX] = player; // new MAN possition
					tab[y + verticalMove[s]][x + horizontalMove[s]] = BLANKSPOT;
					return;
				}
	}
	return;
}