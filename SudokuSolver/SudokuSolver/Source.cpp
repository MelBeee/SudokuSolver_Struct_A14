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
	setlocale(LC_ALL, "");

	Sudoku sudokuASolutionner("Facile");
	sudokuASolutionner.Afficher(cout);
	sudokuASolutionner.Solutionner();

}