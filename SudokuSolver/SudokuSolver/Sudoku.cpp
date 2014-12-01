//////////////////////////////////////////////////////
//						Sudoku.CPP								 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Créer le 30 novembre 2014							 //
//		Dernière modification le 30 novembre 2014		 //
//																	 //
//		Définitions des méthodes de la class Sudoku   //
//////////////////////////////////////////////////////
#include "Sudoku.h"

Sudoku::Sudoku(string nom)
{
	ifstream sudokuMap("Sudoku_"+nom+".txt");
	char nombre;
	if (!sudokuMap.fail()) //si le fichier est ouvert
	{
		for (int i = 1; i <= NBLIGNECOLONNE; i++)
		{
			for (int j = 1; j <= NBLIGNECOLONNE; j++)
			{
				sudokuMap.get(nombre);
				if (nombre == '\n')
				{
					sudokuMap.get(nombre);
				}
				cout << nombre;
			}
			cout << endl;
		}
	}
	else
	{
		throw exception("le nom du fichier est introuvable");
	}
}

void Sudoku::Solutionner()
{

}

void Sudoku::Afficher(ostream & out)
{
	for (int i = 0; i < NBLIGNECOLONNE; i++)
	{
		for (int j = 0; j < NBLIGNECOLONNE; j++)
		{
			out << monSudoku_.at(1).at(j) + " ";
		}
		cout << endl;
	}
}
