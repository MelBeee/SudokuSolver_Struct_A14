//////////////////////////////////////////////////////
//					     Fonctions.h			  		   	 //
//		Fait par Melissa Boucher et Xavier Brosseau   //
//		Créer le 30 novembre 2014							 //
//		Dernière modification le 9 Decembre 2014		 //
//																	 //
//		Declaration des fonctions gerant le menu      //
//////////////////////////////////////////////////////
#ifndef FONCTIONS_H
#define FONCTIONS_H

#include "Sudoku.h"

//--- DES CONSTANTES QUI SONT UTILISÉ PARCE QU'ON VEUX SEULEMENT UN CHOIX DE 1 A 5 INCLU
const int NBCHOIXMAX = 5;
const int NBCHOIXMIN = 1;

//////////////////////////////////////////////////////////////////////////
//    Fonction qui affiche a la console les choix de l'utilisateur      //
//    Intrants : None                                                   //
//    Extrant : None                                                    //
//////////////////////////////////////////////////////////////////////////
void AfficherMenu();
////////////////////////////////////////////////////////////////////////////////////////////
//    Fonction qui fait en sorte d'executer ce que l'utilisateur a fait comme choix       //
//    Intrants : string de l'entete du choix                                              //
//    Extrant : boolean quitter (true = quitter/false = continuer)                        //
////////////////////////////////////////////////////////////////////////////////////////////
bool SwitchMenu(string & entete);
//////////////////////////////////////////////////////////////
//    Fonction qui demande le choix de l'utilisateur        //
//    Intrants : None                                       //
//    Extrant : le choix                                    //
//////////////////////////////////////////////////////////////
int FaireChoix();
////////////////////////////////////////////////////////
//    Fonction de paresseux qui affiche des lignes    //
//    Intrants : None                                 //
//    Extrant : le choix                              //
////////////////////////////////////////////////////////
void AfficherLigneSeparation();
//////////////////////////////////////////////////////////////////////////
//    Fonction qui affiche l'entete du choix fait par l'utilisateur     //
//    Intrants : None                                                   //
//    Extrant : le choix                                                //
//////////////////////////////////////////////////////////////////////////
void AfficherEntete(string entete);
////////////////////////////////////////////////////////////////////////////////////////////
//    Fonction qui bloque l'affichage tant que l'utilisateur ne presse pas une touche     //
//    Intrants : None                                                                     //
//    Extrant : None                                                                      //
////////////////////////////////////////////////////////////////////////////////////////////
void Attendre();
////////////////////////////////////////////////////////////////////////////////////////////////////////
//    Fonction qui prend l'entré au clavier de l'utilisateur lorsqu'on veux seulement des nombres     //
//    Intrants : le nombre a entrer en reference                                                      //
//    Extrant : true = le caractere n,est pas une lettre / false = le caractere est une lettre        //
////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GetInt(int & n);
//////////////////////////////////////////////////////////////////////
//    Fonction englobe tout les etapes du solutionnage du sudoku    //
//    Intrants : entete a afficher                                  //   
//    Extrant : None                                                //
//////////////////////////////////////////////////////////////////////
void ResoudreSudoku(string entete);

#endif