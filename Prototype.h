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
//			- Variable contenant le fichier de lecture en référence
//			- Variable contenant le fichier de sortie en référece
// Extrant: - Ouvre le fichier
void DemanderFichier(TypeFichier typeFichier, SourceLecture& flecture, ofstream& fecriture);
void LireFichier(TypeFichier i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient, ofstream& flux);
void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient);
void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient, ofstream& flux);
void StatusCaisse(Quincaillerie& magasin, ofstream& flux);
void EcrireStatsFinales(Quincaillerie& magasin, ofstream& flux);

// OuvrirCaisse
// Ouvre une caisse 
// Intrant: - Vecteur contenant les informations pour ouvrir une caisse
//			- Variable contenant la simulation de Quincaillerie
//			- Variable contenant le fichier de sortie en référence
// Extrant: ------
void OuvrirCaisse(vector<string> vectorElems, Quincaillerie& magasin, ofstream& flux);
// AjouterClient
// Permet d'ajouter un client à la caisse la plus rapide 
// Intrant: - Vecteur contenant les informations pour ajouter un client
//			- Variable contenant la simulation de Quincaillerie
//			- Vecteur contenant les clients à ajouter
//			- Variable contenant le fichier de sortie en référence
// Extrant: ------
void AjouterClient(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient, ofstream& flux);
// QuitterCaisse
// Permet de finaliser une transaction dans une caisse
// Intrant: - Vecteur contenant les informations pour finaliser une transaction
//			- Variable contenant la simulation de Quincaillerie
//			- Variable contenant le fichier de sortie en référence
// Extrant: ------
void QuitterCaisse(vector<string> vectorElems, Quincaillerie& magasin, ofstream& flux);
// FermerCaisse
// Ferme une caisse 
// Intrant: - Vecteur contenant les informations pour fermer une caisse
//			- Variable contenant la simulation de Quincaillerie
//			- Variable contenant le fichier de sortie en référence
// Extrant: ------
void FermerCaisse(vector<string> vectorElems, Quincaillerie& magasin, ofstream& flux);