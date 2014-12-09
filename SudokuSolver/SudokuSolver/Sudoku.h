//////////////////////////////////////////////////////
//					     Sudoku.h			  		   	    //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Cr�er le 30 novembre 2014							 //
//		Derni�re modification le 9 Decembre 2014		 //
//																	 //
//		Declaration des fonctions de la class sudoku  //
//    pour la r�solution et l'affichage d'une grille//
//    de jeu                                        //
//////////////////////////////////////////////////////
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
	///////////////////////////////////////////////////////////////////////////////////////
	//    constructeur param�trique qui initialise le vecteur avec le contenu du doc.txt //
	//    Intrants : ifstream du fichier .TXT                                            //    
	///////////////////////////////////////////////////////////////////////////////////////
   Sudoku(ifstream &sudokuMap);

	//////////////////////////////////////////////////////////////////////////
	//    rempli la matrice avec le contenu du doc.txt						      //
	//    Intrants : ifstream Document .txt                                 //
	//////////////////////////////////////////////////////////////////////////
	void RemplirMatrice(ifstream & doc);

	//////////////////////////////////////////////////////////////////////////////
	//    trouve une position dans le vecteur qui n'a pas de valeur attribu� (0)//
	//    Intrants : ligne & colonne															 //
	//    Extrant : bool si position trouver												 //
	//////////////////////////////////////////////////////////////////////////////
	bool TrouvePositionVide(int& colonne, int& ligne);

	///////////////////////////////////////////////////////////////////////////////////////////
	//    verifie si le nombre entr� en parametre peut aller a la position pass� en parametre//
	//    Intrants : colonne & ligne, nombre                                                 //
	//    Extrant : si nombre peut aller a la position							                    //
	///////////////////////////////////////////////////////////////////////////////////////////
	bool VerifiePosition(int colonne, int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////////
	//    essaie de resoudre le sudoku                                      //
	//    Extrant : si r�solution possible                                  //
	//////////////////////////////////////////////////////////////////////////
	bool Resoudre();

	//////////////////////////////////////////////////////////////////////////
	//    verifie si la valeur entr� en parametre est dans la colonne donn� //
	//    Intrants : le nombre, la colonne                                  //
	//    Extrant : si valeur est dans la colonne                           //
	//////////////////////////////////////////////////////////////////////////
	bool VerifierColonne(int colonne, int nombre);

	//////////////////////////////////////////////////////////////////////////
	//    verifie si la valeur entr� en parametre est dans la ligne donn�   //
	//    Intrants : le nombre, la ligne                                    //
	//    Extrant : si la valeur est dans la ligne                          //
	//////////////////////////////////////////////////////////////////////////
	bool VerifierLigne(int ligne, int nombre);

	///////////////////////////////////////////////////////////////////////////////
	//    verifie si la valeur entr� en parametre se trouve dans le cadran donn� //
	//    Intrants : ligne de d�part, colonne de d�part, un nombre               //
	//    Extrant : si le nombre est dans le cadran		                          //
	///////////////////////////////////////////////////////////////////////////////
	bool VerifierCadran(int lignedepart, int colonnedepart, int nombre);

	//////////////////////////////////////////////////////////////////////////
	//    affiche le sudoku																	//
	//    Intrants : flux de sortie (flux capacitor)								//
	//////////////////////////////////////////////////////////////////////////
   void AfficherSudoku(ostream & out);

private:
	Matrice<int> monSudoku_;
};

#endif

