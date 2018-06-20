#include "control.h"
#include "definitions.h"


void updateStatistic(int tab[8][8])
{
	amount_White = 0;
	amount_Black = 0;
	for (int p = 0; p < 8; p++) {
		for (int s = 0; s < 8; s++)
		{
			if (tab[p][s] == WHITE)
				amount_White++;
			else if (tab[p][s] == BLACK)
				amount_Black++;
		}
	}
}
void ArrowControl(int tab, int COLOR, int * x, int * y, char * str1)
{
	int arrow;
	int end;
	for (;;)
	{
		displayChessboard(tab, COLOR, *x, *y, str1);
		// printf statistics
		end = getch();
		if (end == ENTER) // PRESS to ENTER
		{
			return;
		}
		else if (end == EXIT)
		{
			quit(tab);
		}
		else if (end == SAVE) {
			printf("\nArray saved");
			saveArrayToFile(tab);
		}
			arrow = getch();

		if (arrow == UP_ARROW) {
			if (*y == UP_BORDER)
				*y = DOWN_BORDER;   // move to down border
			else
				*y = *y - 1;		// move up
		}
		if (arrow == LEFT_ARROW) {
			if (*x == LEFT_BORDER)
				*x = RIGHT_BORDER;   // move to right border
			else
				*x = *x - 1;		// move left
		}
		if (arrow == RIGHT_ARROW) {
			if (*x == RIGHT_BORDER)
				*x = LEFT_BORDER;   // move to left border
			else
				*x = *x + 1;		// move right
		}
		if (arrow == DOWN_ARROW) {
			if (*y == DOWN_BORDER)
				*y = UP_BORDER;   // move to up border
			else
				*y = *y + 1;		// move down
		}


	}
}
void odczytaj_argumenty(int argc, char ** argv, int tab[8][8])
{
	for (int i = 1; i < argc; i++)
	{
	
		if (argc > i) {
			if (strcmp(argv[i], "-i")==0)
			{
				readArrayFromFile(argv[i+1], tab);
			}
		}
		
		if (strcmp(argv[i], "-h") == 0)
		{
			displayHelp();
		}
	}
}
void quit(int tab[8][8])
{
	system("cls");
	int end, save;
	printf("\n\n\t\t QUITING");
	printf(" Are you sure ? \n\t\t        press q");
	end = getch();
	if (end == EXIT)
	{
		system("cls");
		printf("\n\n\t    Do you want to save before exit ?\n\t\t\tpress s");
		save = getch();
		if (save == 's')
		{
			saveArrayToFile(tab);
		}
		exit(0);
	}
}