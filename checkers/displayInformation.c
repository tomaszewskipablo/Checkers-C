#include "displayInformation.h"
#include "rlutil.h"
#include "definitions.h"

#include <Windows.h>

void displayChessboard(int tab[8][8], int player, int x, int y, char * info)
{
	system("cls");
	printf("\n  ");
	for (int p = 0; p < 8; p++) {
		printf("%c    ", 65 + p);		// letters on the top
	}
	printf("\n");

	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++) {	// TOP of every horizontal line
			printf("%c", 195);	printf("%c", 196); printf("%c", 196); printf("%c", 196); printf("%c", 195);
		}
		printf("\n");
		for (int i = 0; i < 8; i++) { // middle
			printf("%c", 124);			// left barrier

			if (tab[j][i] == WHITE)			// PLAYER 1
			{
				setColor(LIGHTBLUE);	// RED color
				if (j == y && i == x)
					setColor(YELLOW);	// BLUE if(current) 
				printf(" %c", 79);
				setColor(15);	// WHITE color
			}
			else if (tab[j][i] == BLACK)	// PLAYER 2
			{
				setColor(GREEN);
				if (j == y && i == x)
					setColor(15);	// BLUE if(current) 
				printf(" %c", 88);
				setColor(15);
			}
			else if (tab[j][i] == 3) {// POSSIBLE SPOTS			1->2, 2->3
				setColor(3);
				if (j == y && i == x)
					setColor(15);	// BLUE if(current) 
				printf(" %c", 176);
				setColor(15);		// WHITE color
			}
			else if (tab[j][i] == 10)	// CURRENT MAN to move 
				printf(" %c", 219);
			else
			{
				if (j == y && i == x)
				{
					setColor(15);	// BLUE if(current)
					printf(" %c", 176);
				}
				else
					printf("  ");			// IMPOSSIBLE SPOTS === 0
			}
			printf(" %c", 124);
		}
		printf(" %d", j + 1);	// number on the right
		// INFO
		if (j == 0) {
			if (player == 1)	printf("\t\t\t| White turn |");
			else printf("\t\t\t| Black turn |");
		}
		if (j == 1) {
			printf("\t\t | %s |", info);
		}
		// MENU
		if (j == 4) {
			printf("\t\t\t| save game = s |");
		}
		/*if (j == 5) {
			printf("\t\t\t| exit game |");
		}*/
		//printf("\t\t\tPASdknJANDOAN\n");
		 printf("\n");
	}
	
	// BOTTOM of chessboard
	for (int i = 0; i < 8; i++) {
		printf("%c", 195); printf("%c", 196);	printf("%c", 196); printf("%c", 196);	 printf("%c", 195);
	}

	printf("\n\n amount of white's man: %d", amount_White);
	printf("\n\n amount of  black's man: %d", amount_Black);
}
void displayHelp()
{
	int end;
	printf("\n\t\tCHECKERS INSTRUCTION\n");
	printf("\To win a game of checkers, you have to move your pieces towards your opponent's side of the board.\nYou can move faster by jumping your opponent's pieces and removing them from the board.\n");
	printf("\nRULES:\n - pieces can move only forward\n - you can beat your oponent piece and remove it from board by jumping over it. \n - pieces can beat forward and backward. ");
	printf("\n - first beat is not obligatory, but next in a row is. ");

	printf("\n\npress enter to play");
	do {
		end = getch();
	} while (end != ENTER);
}