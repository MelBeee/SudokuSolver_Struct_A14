#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include <ostream>
#include "Matrice.h"
#include "Chrono.h"
#include <fstream>
#include <sstream>
using namespace std; 
	const int NBLIGNECOLONNE = 9;
class Sudoku
{
public:
	Sudoku(string nom);
	void Solutionner();
	void Afficher(ostream & out);

private:

	Chrono horloge_;
	Matrice<int> monSudoku_;
};

#endif

