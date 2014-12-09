//////////////////////////////////////////////////////
//					     Sudoku.h			  		   	    //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Créer le 30 novembre 2014							 //
//		Dernière modification le 9 Decembre 2014		 //
//																	 //
//		Declaration des fonctions de la class sudoku  //
//    pour la résolution et l'affichage d'une grille//
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
//Lorsqu'un chiffre n'est pas trouvé ou pas bon
const int CHIFFREPASBON = 0;
//le code ascii -48 donne le int approprié
const int CHARTOINTASCII = -48;


class Sudoku
{
public:
	///////////////////////////////////////////////////////////////////////////////////////
	//    constructeur paramétrique qui initialise le vecteur avec le contenu du doc.txt //
	//    Intrants : ifstream du fichier .TXT                                            //    
	///////////////////////////////////////////////////////////////////////////////////////
   Sudoku(ifstream &sudokuMap);

	//////////////////////////////////////////////////////////////////////////
	//    rempli la matrice avec le contenu du doc.txt						      //
	//    Intrants : ifstream Document .txt                                 //
	//////////////////////////////////////////////////////////////////////////
	void RemplirMatrice(ifstream & doc);

	//////////////////////////////////////////////////////////////////////////////
	//    trouve une position dans le vecteur qui n'a pas de valeur attribué (0)//
	//    Intrants : ligne & colonne															 //
	//    Extrant : bool si position trouver												 //
	//////////////////////////////////////////////////////////////////////////////
	bool TrouvePositionVide(int& colonne, int& ligne);

	///////////////////////////////////////////////////////////////////////////////////////////
	//    verifie si le nombre entré en parametre peut aller a la position passé en parametre//
	//    Intrants : colonne & ligne, nombre                                                 //
	//    Extrant : si nombre peut aller a la position							                    //
	///////////////////////////////////////////////////////////////////////////////////////////
	bool VerifiePosition(int colonne, int ligne, int nombre);

	//////////////////////////////////////////////////////////////////////////
	//    essaie de resoudre le sudoku                                      //
	//    Extrant : si résolution possible                                  //
	//////////////////////////////////////////////////////////////////////////
	bool Resoudre();

	//////////////////////////////////////////////////////////////////////////
	//    verifie si la valeur entré en parametre est dans la colonne donné //
	//    Intrants : le nombre, la colonne                                  //
	//    Extrant : si valeur est dans la colonne                           //
	//////////////////////////////////////////////////////////////////////////
	bool VerifierColonne(int colonne, int nombre);

	//////////////////////////////////////////////////////////////////////////
	//    verifie si la valeur entré en parametre est dans la ligne donné   //
	//    Intrants : le nombre, la ligne                                    //
	//    Extrant : si la valeur est dans la ligne                          //
	//////////////////////////////////////////////////////////////////////////
	bool VerifierLigne(int ligne, int nombre);

	///////////////////////////////////////////////////////////////////////////////
	//    verifie si la valeur entré en parametre se trouve dans le cadran donné //
	//    Intrants : ligne de départ, colonne de départ, un nombre               //
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

