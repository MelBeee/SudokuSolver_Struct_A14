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
	setlocale(LC_ALL, "");

	Sudoku sudokuASolutionner("Facile");
	sudokuASolutionner.Afficher(cout);
	sudokuASolutionner.Solutionner();

}