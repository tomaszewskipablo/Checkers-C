#ifndef CHECKING_H
#define CHECKING_H

/* checking move possibility functions */

/* --- ---- ---- ---- */

int stillOnTheBoard(int tab[8][8], int x, int y, int horizontalMove, int verticalMove);
int blankSpot(int tab[8][8], int x, int y, int horizontalMove, int verticalMove);
int opponentsMan(int tab[8][8], int x, int y, int horizontalMove, int verticalMove, int player);
int possibleNormalMove(int tab[8][8], int x, int y, int player);
int possibleBeat(int tab[8][8], int x, int y, int color);
int PossibleToMoveManToSpot(int tab[8][8], int player, int newX, int newY, int oldX, int oldY);
int ManCanMoveAnywhere(int tab[8][8], int x, int y, int player);
int AnyMovePossible(int tab[8][8], int player);

#endif
