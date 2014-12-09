//////////////////////////////////////////////////////
//						Sudoku.CPP								 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Cr�er le 30 novembre 2014							 //
//		Derni�re modification le 30 novembre 2014		 //
//																	 //
//		D�finitions des m�thodes de la class Sudoku   //
//////////////////////////////////////////////////////
#include "Sudoku.h"


//construit la matrice avec un fichier txt apropri�e
Sudoku::Sudoku(ifstream &sudokuMap)
{
	monSudoku_.SetNbLignes(NBLIGNECOLONNE);
	monSudoku_.SetNbColonnes(NBLIGNECOLONNE);
	RemplirMatrice(sudokuMap);
}

//remplit la matrice a partir du fichier IFSTREAM pass� en param�tre 
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
					doc.get(nombre);//Prend le caract�re suivent plutot que le '\n'
				}
				if (nombre == '*') //Transforme les * en int 0
				{
					nombre = '0';
				}
				monSudoku_.at(i).at(j) = nombre + CHARTOINTASCII;//entre dans la matrice le code ascii - 48
																				 //pour le transformer un int
			}
		}
	}
	else
	{
		throw exception("Le nom du fichier est introuvable");
	}
}

//Affiche le Sudoku a partir de la matrice 
void Sudoku::AfficherSudoku(ostream & out)
{
	for (int i = 0; i < NBLIGNECOLONNE; i++)
	{
		for (int j = 0; j < NBLIGNECOLONNE; j++)
		{
			cout << monSudoku_[i][j];
         if (j == NBRECADRAN - 1 || j == 6 - 1)
			{
				cout << " ";
			}
		}

		cout << endl;
      if (1%3==2)
		{
			cout << endl;
		}
	}
}

// trouve une position dans le vecteur qui n'a pas de valeur attribu� (0)
bool Sudoku::TrouvePositionVide(int& ligne, int& colonne)
{
	for (ligne = 0; ligne < NBLIGNECOLONNE; ligne++)
	{
		for (colonne = 0; colonne < NBLIGNECOLONNE; colonne++)
		{
			if (monSudoku_.at(ligne).at(colonne) == CHIFFREPASBON)
				return true;
		}
	}
	return false;
}

// verifie si le nombre entr� en parametre peut aller a la position pass� en parametre
bool Sudoku::VerifiePosition(int ligne, int colonne, int nombre)
{
	return	!VerifierLigne(ligne, nombre) &&
				!VerifierColonne(colonne, nombre) &&
				!VerifierCadran(ligne - ligne % 3, colonne - colonne % 3, nombre);
}

//essaie de resoudre le sudoku
bool Sudoku::Resoudre()
{
	int colonne, ligne;

	if (!TrouvePositionVide(ligne, colonne))
		return true;

	for (int num = 1; num <= NBLIGNECOLONNE; num++)
	{
		if (VerifiePosition(ligne, colonne, num))
		{
			monSudoku_.at(ligne).at(colonne) = num;

			if (Resoudre())
				return true;

			monSudoku_.at(ligne).at(colonne) = CHIFFREPASBON;
		}
	}
	return false;
}

// verifie si la valeur entr� en parametre est dans la colonne donn�
bool Sudoku::VerifierColonne(int colonne, int nombre)
{
	for (int ligne = 0; ligne < NBLIGNECOLONNE; ligne++)
	{
		if (monSudoku_.at(ligne).at(colonne) == nombre)
			return true;
	}
	return false;
}

// verifie si la valeur entr� en parametre est dans la colonne donn�
bool Sudoku::VerifierLigne(int ligne, int nombre)
{
	for (int colonne = 0; colonne < NBLIGNECOLONNE; colonne++)
	{
		if (monSudoku_.at(ligne).at(colonne) == nombre)
			return true;
	}
	return false;
}

// verifie si la valeur entr� en parametre se trouve dans le cadran donn�
bool Sudoku::VerifierCadran(int lignedepart, int colonnedepart, int nombre)
{
	for (int ligne = 0; ligne < NBRECADRAN; ligne++)
	{
		for (int colonne = 0; colonne < NBRECADRAN; colonne++)
		{
			if (monSudoku_.at(ligne + lignedepart).at(colonne + colonnedepart) == nombre)
				return true;
		}
	}
	return false;
}