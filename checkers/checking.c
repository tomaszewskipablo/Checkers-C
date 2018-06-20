#include "checking.h"
#include "definitions.h"


int stillOnTheBoard(int tab[8][8], int x, int y, int horizontalMove, int verticalMove)
{
	if (y + verticalMove >= 0 && y + verticalMove < 8 && x + horizontalMove >= 0 && x + horizontalMove < 8)
		return 1;
	else
		return 0;
}
int blankSpot(int tab[8][8], int x, int y, int horizontalMove, int verticalMove)
{
	if (tab[y + verticalMove][x + horizontalMove] == BLANKSPOT)
		return 1;
	else
		return 0;
}
int opponentsMan(int tab[8][8], int x, int y, int horizontalMove, int verticalMove, int player)
{
	int opponent;
	if (player == WHITE) opponent = BLACK;
	else opponent = WHITE;

	if (tab[y + verticalMove][x + horizontalMove] == opponent)
		return 1;
	else
		return 0;
}
int possibleNormalMove(int tab[8][8], int x, int y, int player) {
	int verticalMove;
	if (player == WHITE)
		verticalMove = DOWN;
	else
		verticalMove = UP;

	if (stillOnTheBoard(tab, x, y, RIGHT, verticalMove))
		if (blankSpot(tab, x, y, RIGHT, verticalMove))
			return 1;
	if (stillOnTheBoard(tab, x, y, LEFT, verticalMove))
		if (blankSpot(tab, x, y, LEFT, verticalMove))
			return 1;

	return 0;
}
int possibleBeat(int tab[8][8], int x, int y, int player) {
	// BEAT/jump over
	int horizontalMove[4] = { RIGHT, LEFT, RIGHT, LEFT };
	int verticalMove[4] = { DOWN, DOWN, UP, UP };
	for (int s = 0; s < 4; s++)
	{
		if (stillOnTheBoard(tab, x, y, 2 * horizontalMove[s], 2 * verticalMove[s]))
			if (opponentsMan(tab, x, y, horizontalMove[s], verticalMove[s], player))
				if (blankSpot(tab, x, y, 2 * horizontalMove[s], 2 * verticalMove[s]))
					return 1;
	}
	return 0;
}
int PossibleToMoveManToSpot(int tab[8][8], int player, int newX, int newY, int oldX, int oldY)
{
	if (tab[newY][newX] == BLANKSPOT) // SPOT to move must be empty
	{
		// NORMAL MOVE
		if ((newX - oldX == RIGHT) || (newX - oldX == LEFT))
		{
			if (player == WHITE) { // White can move only down
				if (newY - oldY == DOWN)
					return 1;
			}
			else if (player == BLACK) // Black can move only up
			{
				if (newY - oldY == UP)
					return 1;
			}
		}
		// ------
		// BEATING
		if (jumpOverOpponent(tab, player, newX, newY, oldX, oldY))
		{
			return BEATEN;
		}
	}
	return 0;
}
int ManCanMoveAnywhere(int tab[8][8], int x, int y, int player)
{
	if (possibleNormalMove(tab, x, y, player))
		return 1;
	if (possibleBeat(tab, x, y, player))
		return 1;

	return 0;

}
int AnyMovePossible(int tab[8][8], int player) // check before someone turn if any move for him is possible, if not he lose
{
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++)
		{
			if (tab[y][x] == player)	// find a man
				if (ManCanMoveAnywhere(tab, y, x, player))	// color-1 for dj
					return 1;		// COLOR can move
		}
	}
	return 0;	// NO move possible for color
}
