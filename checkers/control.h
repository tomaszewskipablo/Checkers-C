#ifndef CONTROL_H
#define CONTROL_H

/* control functions */

/* --- ---- ---- ---- */

void updateStatistic(int tab[8][8]);
void ArrowControl(int tab, int COLOR, int * x, int * y, char * str1);
void odczytaj_argumenty(int ile, char ** argumenty, int tab[8][8]);
void quit(int tab[8][8]);

#endif
