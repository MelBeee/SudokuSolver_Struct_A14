//////////////////////////////////////////////////////
//						Source.CPP								 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Cr�er le 30 novembre 2014							 //
//		Derni�re modification le 30 novembre 2014		 //
//																	 //
//		Application servant � resoudre des sudoku     //
//////////////////////////////////////////////////////
#include "Fonctions.h"

int main()
{
	//permet d'afficher les caract�res sp�ciaux
	setlocale(LC_ALL, "");
   string entete;

	//tant que l'on ne quitte pas..
   while (!SwitchMenu(entete))
   {
		ResoudreSudoku(entete);
   }
}