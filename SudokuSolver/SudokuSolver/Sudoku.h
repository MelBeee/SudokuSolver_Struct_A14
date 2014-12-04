#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <ostream>
#include "Matrice.h"
#include "Chrono.h"
#include <fstream>
#include <sstream>
using namespace std; 

//Ligne:9 Colonne:9
const int NBLIGNECOLONNE = 9;
//NombreCadran
const int NBRECADRAN = 3;
//Lorsqu'un chiffre n'est pas trouvé ou pas bon
const int CHIFFREPASBON = 0;
//le code ascii -48 donne le int approprié
const int CHARTOINTASCII = -48;


class Sudoku
{
public:
	// constructeur paramétrique qui initialise le vecteur avec le contenu du doc.txt
	Sudoku(string nom);
	// rempli la matrice avec le contenu du doc.txt
	void RemplirMatrice(ifstream & doc);
	// trouve une position dans le vecteur qui n'a pas de valeur attribué (0)
	bool TrouvePositionVide(int& colonne, int& ligne);
	// verifie si le nombre entré en parametre peut aller a la position passé en parametre
	bool VerifiePosition(int colonne, int ligne, int nombre);
	//essaie de resoudre le sudoku
	bool Resoudre();
	// verifie si la valeur entré en parametre est dans la colonne donné
	bool VerifierColonne(int colonne, int nombre);
	// verifie si la valeur entré en parametre est dans la colonne donné
	bool VerifierLigne(int ligne, int nombre);
	// verifie si la valeur entré en parametre se trouve dans le cadran donné
	bool VerifierCadran(int lignedepart, int colonnedepart, int nombre);
	// affiche le sudoku
	void AfficherSudoku();

private:
	Chrono horloge_;
	Matrice<int> monSudoku_;
};

#endif

