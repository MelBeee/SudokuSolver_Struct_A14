#ifndef SUDOKU_H
#define SUDOKU_H
#include <iostream>
#include "Matrice.h"
#include "Chrono.h"
#include <fstream>
using namespace std; 

class Sudoku
{
public:
	Sudoku();
	void Solutionner();

private:
	Chrono horloge_;
	Matrice<int> monSudoku_;
};

#endif

