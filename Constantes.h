#pragma once
#include <string>
using namespace std;

// �num
<<<<<<< HEAD
enum Status { FERM� , OUVERT};				// Le status de la caisse
enum TypeFichier { CLIENT, OP�RATIONS };	// Le type de fichier � traiter
=======
enum Status { FERM� , OUVERT };
enum DemanderFichier { CLIENT, OP�RATIONS };
>>>>>>> refs/remotes/origin/JO

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