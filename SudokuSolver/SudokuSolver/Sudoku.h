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
//Lorsqu'un chiffre n'est pas trouv� ou pas bon
const int CHIFFREPASBON = 0;
//le code ascii -48 donne le int appropri�
const int CHARTOINTASCII = -48;


class Sudoku
{
public:
	// constructeur param�trique qui initialise le vecteur avec le contenu du doc.txt
	Sudoku(string nom);
	// rempli la matrice avec le contenu du doc.txt
	void RemplirMatrice(ifstream & doc);
	// trouve une position dans le vecteur qui n'a pas de valeur attribu� (0)
	bool TrouvePositionVide(int& colonne, int& ligne);
	// verifie si le nombre entr� en parametre peut aller a la position pass� en parametre
	bool VerifiePosition(int colonne, int ligne, int nombre);
	//essaie de resoudre le sudoku
	bool Resoudre();
	// verifie si la valeur entr� en parametre est dans la colonne donn�
	bool VerifierColonne(int colonne, int nombre);
	// verifie si la valeur entr� en parametre est dans la colonne donn�
	bool VerifierLigne(int ligne, int nombre);
	// verifie si la valeur entr� en parametre se trouve dans le cadran donn�
	bool VerifierCadran(int lignedepart, int colonnedepart, int nombre);
	// affiche le sudoku
	void AfficherSudoku();

private:
	Chrono horloge_;
	Matrice<int> monSudoku_;
};

#endif

