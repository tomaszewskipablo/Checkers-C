#include "administration.h"
#include "definitions.h"


void whichManToMove(int tab[8][8], int player, char * str1)
{
	// Staring possition------------
	int x = 3;
	int y = 0;
	if (player == BLACK)
		y = 7;
	//------------------------------

	do {
		ArrowControl(tab, player, &x, &y, str1);
	} while (!(tab[y][x] == player && ManCanMoveAnywhere(tab, x, y, player)));	// no MAN on the chosen spot or choosen MAN can not move -> choose another one
	tab[y][x] = CHOOSENMANTOMOVE;												// MAN to be moveed == 10;
}
void whereToMove(int tab[8][8], int player, char * str1)
{
	// find CHOOSENMANTOMOVE position----------------------
	int oldX, oldY, newX, newY;
	for (int p = 0; p < 8; p++) {
		for (int s = 0; s < 8; s++)
			if (tab[p][s] == CHOOSENMANTOMOVE)
			{
				oldX = newX = s;
				oldY = newY = p;
			}
	}
	//-----------------------------------------------------
	int beaten;

	do {
		ArrowControl(tab, player, &newX, &newY, str1);
	} while ((beaten = PossibleToMoveManToSpot(tab, player, newX, newY, oldX, oldY)) == 0);
	tab[oldY][oldX] = BLANKSPOT; // old possition
	tab[newY][newX] = player;	// new MAN possition
	if ((possibleBeat(tab, newX, newY, player) == 1 && beaten == BEATEN))
	{
		tab[newY][newX] = CHOOSENMANTOMOVE;
		haveToBeat(tab, newX, newY, player);
	}


}
void YourMove(int tab[8][8], int player)
{

	updateStatistic(tab);
	char * str1 = "Choose man you want to move";
	whichManToMove(tab, player, str1);

	char * str2 = "Where you want to move?";
	whereToMove(tab, player, str2);

}