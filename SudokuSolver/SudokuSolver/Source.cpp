//////////////////////////////////////////////////////
//						Source.CPP								 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Créer le 30 novembre 2014							 //
//		Dernière modification le 30 novembre 2014		 //
//																	 //
//		Application servant à resoudre des sudoku     //
//////////////////////////////////////////////////////
#include "Fonctions.h"

int main()
{
	//permet d'afficher les caractères spéciaux
	setlocale(LC_ALL, "");
   string entete;

	//tant que l'on ne quitte pas..
   while (!SwitchMenu(entete))
   {
		ResoudreSudoku(entete);
   }
}