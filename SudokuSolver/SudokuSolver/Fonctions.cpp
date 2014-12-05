//////////////////////////////////////////////////////
//					     Fonctions.cpp			  	   	 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Cr�er le 30 novembre 2014							 //
//		Derni�re modification le 9 Decembre 2014		 //
//																	 //
//		Definition des fonctions utilis�s pour le menu//
//////////////////////////////////////////////////////
#include "Fonctions.h"

////////////////////////////////////////////////////////////////////
void AfficherMenu()
{
   cout << "1. R�soudre un sudoku facile " << endl;
   cout << "2. R�soudre un sudoku moyen  " << endl;
   cout << "3. R�soudre un sudoku difficile " << endl;
   cout << "4. R�soudre un sudoku diabolique " << endl;
   cout << "5. Quitter le programme " << endl;
}
////////////////////////////////////////////////////////////////////
bool SwitchMenu(string & entete)
{
   system("cls");
   AfficherMenu(); 
   bool quitter = false;
   switch (FaireChoix())
   {
   case 1:
      entete = "Facile";
      break;
   case 2:
      entete = "Moyen";
      break;
   case 3:
      entete = "Difficile";
      break;
   case 4:
      entete = "Diabolique";
      break;
   case 5:
      quitter = true;
      break;
   }
   return quitter;
}
////////////////////////////////////////////////////////////////////
int FaireChoix()
{
   int choix;
   do
   {
      cout << "Faites un choix : ";
   } while (!GetInt(choix) && (choix < NBCHOIXMIN || choix > NBCHOIXMAX));

   return choix; 
}
////////////////////////////////////////////////////////////////////
bool GetInt(int & n)
{
   string str;
   getline(cin, str);
   bool caractere = true;

   stringstream buffer(str);
   buffer >> n;

   if (!buffer)
      caractere = false;

   return caractere;
}
////////////////////////////////////////////////////////////////////
void Attendre()
{
   cout << endl << "Appuyer sur une touche pour continuer" << endl;
   cin.ignore(cin.rdbuf()->in_avail() + 1);
   system("cls");
}
////////////////////////////////////////////////////////////////////
void AfficherLigneSeparation()
{
   for (int i = 0; i < 50; i++)
   {
      cout << "="; // cout de paresseux :)
   }
   cout << endl;
}
////////////////////////////////////////////////////////////////////
void AfficherEntete(string entete)
{
   system("cls");
   AfficherLigneSeparation();
   cout << "\t\t Sudoku " << entete << endl; // Affiche le nom du sudoku
   AfficherLigneSeparation();
}
////////////////////////////////////////////////////////////////////
void ResoudreSudoku(string entete)
{
	AfficherEntete(entete);

	Sudoku sudokuASolutionner(entete);
	Chrono horloge;
	

	horloge.Start();
	if (sudokuASolutionner.Resoudre())
	{
		horloge.Stop();
		sudokuASolutionner.AfficherSudoku();
		cout << endl << "Temps : " << horloge.Read() << endl; 
	}
	else
	{
		cout << " Aucune solution possible " << endl;
	}
	Attendre();
}