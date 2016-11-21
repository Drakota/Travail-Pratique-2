#pragma once
#include <string>
using namespace std;

// Énum
<<<<<<< HEAD
enum Status { FERMÉ , OUVERT};				// Le status de la caisse
enum TypeFichier { CLIENT, OPÉRATIONS };	// Le type de fichier à traiter
=======
enum Status { FERMÉ , OUVERT };
enum DemanderFichier { CLIENT, OPÉRATIONS };
>>>>>>> refs/remotes/origin/JO

// Constantes générales
const int NBCAISSES = 6;					// Le nombre de caisse dans la quincaillerie

// Constantes pour les types de clients
const string TYPEPARTICULIER = "pa";		// L'abréviation du type de client particulier
const string TYPEPRIVILEGIE = "pr";			// L'abréviation du type de client privilégier
const string TYPECOMMERCIAL = "c";			// L'abréviation du type de client commercial

// Constantes pour les opérations
const string OUVRIRCAISSE = "O";			// L'opération d'ouvrir une caisse
const string AJOUTERCLIENT = "A";			// L'opération d'ajouter un client à une caisse
const string QUITTERCAISSE = "T";			// L'opération de terminer avec un client
const string FERMERCAISSE = "F";			// L'opération de fermer une caisse