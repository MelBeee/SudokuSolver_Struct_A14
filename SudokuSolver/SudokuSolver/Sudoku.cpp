//////////////////////////////////////////////////////
//						Sudoku.CPP								 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Cr�er le 30 novembre 2014							 //
//		Derni�re modification le 30 novembre 2014		 //
//																	 //
//		D�finitions des m�thodes de la class Sudoku   //
//////////////////////////////////////////////////////
#include "Sudoku.h"

Sudoku::Sudoku(string nom)
{
	monSudoku_.SetNbLignes(NBLIGNECOLONNE);
	monSudoku_.SetNbColonnes(NBLIGNECOLONNE);

	ifstream sudokuMap("Sudoku_"+nom+".txt");
	char nombre;
	if (!sudokuMap.fail()) //si le fichier est ouvert
	{
		for (int i = 0; i < NBLIGNECOLONNE; i++)
		{
			for (int j = 0; j < NBLIGNECOLONNE; j++)
			{
				sudokuMap.get(nombre);
				if (nombre == '\n')		//v�rifie si le caract�re n'est pas un endl
				{
					sudokuMap.get(nombre);
				}
				if (nombre == '*') //Transforme les * en 0
				{
					nombre = '0';
				}
				cout << nombre;//*******************
				monSudoku_.at(i).at(j) =  nombre-48;
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
			out << monSudoku_.at(i).at(j);
		}
		cout << endl;
	}
}
