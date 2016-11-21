//--------------------------------------------------------
//
// Prototype.h
//
// D�claration de la classe Prototype qui conserve les prototypes
// du main
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
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


// OuvrirCaisse
// Ouvre une caisse 
// Intrant: - Vecteur contenant les informations pour ouvrir une caisse
//			- Variable contenant la simulation de Quincaillerie
//			- Variable contenant le fichier de sortie en r�f�rence
// Extrant: ------
void OuvrirCaisse(vector<string> vectorElems, Quincaillerie& magasin, ofstream& flux);

// AjouterClient
// Permet d'ajouter un client � la caisse la plus rapide 
// Intrant: - Vecteur contenant les informations pour ajouter un client
//			- Variable contenant la simulation de Quincaillerie
//			- Vecteur contenant les clients � ajouter
//			- Variable contenant le fichier de sortie en r�f�rence
// Extrant: ------
void AjouterClient(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient, ofstream& flux);

// QuitterCaisse
// Permet de finaliser une transaction dans une caisse
// Intrant: - Vecteur contenant les informations pour finaliser une transaction
//			- Variable contenant la simulation de Quincaillerie
//			- Variable contenant le fichier de sortie en r�f�rence
// Extrant: ------
void QuitterCaisse(vector<string> vectorElems, Quincaillerie& magasin, ofstream& flux);

// FermerCaisse
// Ferme une caisse 
// Intrant: - Vecteur contenant les informations pour fermer une caisse
//			- Variable contenant la simulation de Quincaillerie
//			- Variable contenant le fichier de sortie en r�f�rence
// Extrant: ------
void FermerCaisse(vector<string> vectorElems, Quincaillerie& magasin, ofstream& flux);