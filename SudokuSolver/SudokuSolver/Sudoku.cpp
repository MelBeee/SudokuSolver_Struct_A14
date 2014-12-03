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
	int ligneDébutCellule;
	int ColonneDébutCellule;
	for (ligneDébutCellule = 0; ligneDébutCellule < NBLIGNECOLONNE; ligneDébutCellule += 3)
	{
		for (ColonneDébutCellule = 0; ColonneDébutCellule < NBLIGNECOLONNE; ColonneDébutCellule += 3)
		{
			//------------------------------------------------------------
			for (int i = ligneDébutCellule; i < ligneDébutCellule + 3; i++)
			{
				for (int j = ColonneDébutCellule; j < ColonneDébutCellule + 3; j++)
				{
					cout << monSudoku_.at(i).at(j);
				}
				cout << endl;
			}
			cout << endl;
			//------------------------------------------------------------
		}
	}
	//-----------------
	horloge_.Stop();
	tempsSolution_ = horloge_.Read();
}

int Sudoku::SudokuHelper(int ligne, int colonne)
{
	int nextNum = 1;
	/*
	* Iterate through the possible numbers for this empty cell
	* and recurse for every valid one, to test if it's part
	* of the valid solution.
	*/
	for (; nextNum < 10; nextNum++) {
		if (EstValide(nextNum, ligne, colonne)) {
			monSudoku_.at(ligne).at(colonne) = nextNum;
			if (colonne == 8) {
				if (SudokuHelper(ligne + 1, 0)) return 1;
			}
			else {
				if (SudokuHelper(ligne, colonne + 1)) return 1;
			}
			// We failed to find a valid value for this 
			monSudoku_.at(ligne).at(colonne) = 0;
		}
	}
}

bool EstValide(int nextNum, int ligne, int colonne)
{

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
				if (nombre == '\n')//vérifie si le caractère n'est pas un endl
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