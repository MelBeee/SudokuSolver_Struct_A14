#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "Sudoku.h"

const int NBCHOIXMAX = 5;
const int NBCHOIXMIN = 1;

void AfficherMenu();
bool SwitchMenu(string & entete);
int FaireChoix();
void AfficherLigneSeparation();
void AfficherEntete(string entete);
void Attendre();
bool GetInt(int & n);

#endif