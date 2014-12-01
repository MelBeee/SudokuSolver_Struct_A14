#include "Fonctions.h"

void AfficherMenu()
{
   cout << "  " << endl;
}

bool SwitchMenu()
{

}

int FaireChoix()
{

}

void Attendre()
{
   cout << endl << "Appuyer sur une touche pour continuer" << endl;
   cin.ignore(cin.rdbuf()->in_avail() + 1);
   system("cls");
}
////////////////////////////////////////////////////////////////////////////////
void AfficherLigneSeparation()
{
   for (int i = 0; i < 50; i++)
   {
      cout << "="; // cout de paresseux :)
   }
   cout << endl;
}
////////////////////////////////////////////////////////////////////////////////
void AfficherEntete(string entete)
{
   system("cls");
   AfficherLigneSeparation();
   cout << entete << endl;
   AfficherLigneSeparation();
}