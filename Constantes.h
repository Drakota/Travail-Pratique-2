//--------------------------------------------------------
//
// Constantes.h
//
// D�claration de la classe Constantes qui permet d'utiliser
// certaines constantes � travers le programme
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#pragma once
#include <string>
using namespace std;

// �num
enum Status { FERM� , OUVERT};				// Le status de la caisse
enum TypeFichier { CLIENT, OPERATIONS };	// Le type de fichier � traiter

// Constantes g�n�rales
const int NBCAISSES = 6;					// Le nombre de caisse dans la quincaillerie

// Constantes pour les types de clients
const string TYPEPARTICULIER = "pa";		// L'abr�viation du type de client particulier
const string TYPEPRIVILEGIE = "pr";			// L'abr�viation du type de client privil�gier
const string TYPECOMMERCIAL = "c";			// L'abr�viation du type de client commercial

// Constantes pour les op�rations
const string OUVRIRCAISSE = "O";			// L'op�ration d'ouvrir une caisse
const string AJOUTERCLIENT = "A";			// L'op�ration d'ajouter un client � une caisse
const string QUITTERCAISSE = "T";			// L'op�ration de terminer avec un client
const string FERMERCAISSE = "F";			// L'op�ration de fermer une caisse