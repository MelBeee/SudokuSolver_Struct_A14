#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <ostream>
#include "Matrice.h"
#include "Chrono.h"
#include <fstream>
#include <sstream>
using namespace std; 
	
class Sudoku
{
public:
	Sudoku(string nom);
	void Solutionner();
	void Afficher(ostream & out);
	void RemplirMatrice(ifstream & doc);

private:
	//Ligne:9 Colonne:9
	const int NBLIGNECOLONNE = 9;
	//le code ascii -48 donne le int approprié
	const int CHARTOINTASCII = -48;
	Chrono horloge_;
	Matrice<int> monSudoku_;
};

#endif

