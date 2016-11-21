#pragma once
#include "SourceLecture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

////////////////////////////////////////////////////
// Prototype

// DemanderFichier
// Demande le nom d'un fichier et l'ouvre
// Intrant: - Le type de fichier (CLIENT, OPERATION)
//			- Variable contenant le fichier de lecture en r�f�rence
//			- Variable contenant le fichier de sortie en r�f�rece
// Extrant: -------
void DemanderFichier(TypeFichier typeFichier, SourceLecture& flecture, ofstream& fecriture);

// LireFichier 
// Lit chaque ligne du fichier et �x�cute les op�rations
// Intrant: - Le type de fichier (CLIENT, OPERATION)
//			- Variable contenant le fichier de lecture en r�f�rence
//			- La quincaillerie
//			- Le vecteur de clients
//			- Le fichier de sortie
// Extrant: -------
void LireFichier(TypeFichier typeFichier, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient, ofstream& flux);

// CreerClient
// Cr�e les clients selon leur type
// Intrant: - Un vecteur contenant les �l�ments d'une ligne du fichier
//			- Le vecteur de clients
// Extrant: -------
void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient);

// ExecuterOperations
// Ex�cute les op�rations du fichier d'op�rations
// Intrant: - Un vecteur contenant les �l�ments d'une ligne du fichier
//			- La quincaillerie
//			- Le vecteur de clients
//			- Le fichier de sortie
// Extrant:	-------
void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient, ofstream& flux);

// EcrireStatsFinales
// �crit les statistiques finales de la quincaillerie
// Intrant: - Le quincaillerie
//			- Le fichier de sortie
// Extrant: -------
void EcrireStatsFinales(Quincaillerie& magasin, ofstream& flux);

//
////////////////////////////////////////////////////