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
	ifstream sudokuMap("Sudoku_" + nom + ".txt");
	RemplirMatrice(sudokuMap);
}

void Sudoku::Solutionner()
{
	//0 1 2 3 4 5 6 7 8
	//1
	//2 
	//3 
	//4
	//5
	//6
	//7
	//8
	horloge_.Start();
	//-----------------
	int ligneD�butCellule = 2;
	int ColonneD�butCellule = 2;
	for (ligneD�butCellule;ligneD�butCellule < NBLIGNECOLONNE - 1;ligneD�butCellule += 3)
	{
		for (ColonneD�butCellule;ColonneD�butCellule < NBLIGNECOLONNE - 1;ColonneD�butCellule += 3)
		{

		}
	}

	//<8
	//-----------------
	horloge_.Stop();
	tempsSolution_ = horloge_.Read();
}

void Sudoku::Afficher(ostream & out)
{
	for (int i = 0; i < NBLIGNECOLONNE; i++)
	{
		for (int j = 0; j < NBLIGNECOLONNE; j++)
		{
			if (monSudoku_.at(i).at(j) != 0)
			{
				out << monSudoku_.at(i).at(j);
			}
			else
			{
				out << " ";
			}
		}
		cout << endl;
	}
	cout << "Temps pour la solution (Microseconde)-> " << GetTime() << endl;
}


void Sudoku::RemplirMatrice(ifstream & doc)
{
	char nombre;
	if (!doc.fail()) //si le fichier est ouvert
	{
		for (int i = 0; i < NBLIGNECOLONNE; i++)
		{
			for (int j = 0; j < NBLIGNECOLONNE; j++)
			{
				doc.get(nombre);
				if (nombre == '\n')//v�rifie si le caract�re n'est pas un endl
				{
					nombre = doc.get();
				}
				if (nombre == '*') //Transforme les * en int 0
				{
					nombre = '0';
				}
				monSudoku_.at(i).at(j) = nombre + CHARTOINTASCII;
			}
		}
	}
	else
	{
		throw exception("le nom du fichier est introuvable");
	}
}