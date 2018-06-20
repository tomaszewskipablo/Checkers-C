#include "files.h"
#include "definitions.h"


#include <stdio.h>

void saveArrayToFile(int tab[8][8])
{
	FILE *saveFile; 
	if ((saveFile = fopen("saved_Game.txt", "w")) == NULL) {
		printf("Can't save file\n");
		exit(1);
	}
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++)
		{
			fprintf(saveFile, "%d", tab[j][i]); /* save array */
		}
	}
	fclose(saveFile); 
	return;
}
void readArrayFromFile(char * input, int tab[8][8])
{
	FILE *readFile;
	
	if ((readFile = fopen(input, "r")) == NULL) {
		printf("Can't find file\n");
		return 0;
	}
	for (int j = 0; j < 8; j++) {
		for (int i = 0; i < 8; i++)
		{
			tab[j][i] = getc(readFile)-48;
		}
	}
	fclose(readFile);
}