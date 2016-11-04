// Main.cpp
// Jonathan Bouchard & Pierre-Anthony Houle
// 04 novembre 2016
// Créer une file de clients
#include "Constantes.h"
#include "Quincaillerie.h"
#include "ClientParticulier.h"
#include "ClientPrivilégié.h"
#include "ClientCommercial.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


ifstream DemanderFichierClients();
ifstream DemanderFichierOpérations();
void LireFichierClients(ifstream& Fichier);
void LireFichierOpérations(ifstream& Fichier, Quincaillerie& Magasin);
void CreerClient(vector<string> VectorElems);
void ExecuterOpérations(vector<string> VectorElems, Quincaillerie& Magasin);


void CreerClient(vector<string> VectorElems)
{
	if (VectorElems[1] == TYPEPARTICULIER) new ClientParticulier(stoi(VectorElems[0]), VectorElems[2]);
	else if(VectorElems[1] == TYPEPRIVILEGIE) new ClientPrivilégié(stoi(VectorElems[0]), VectorElems[2], VectorElems[3]);
	else if(VectorElems[1] == TYPECOMMERCIAL) new ClientCommercial(stoi(VectorElems[0]), VectorElems[2], VectorElems[3], VectorElems[4], VectorElems[5], stoi(VectorElems[6]));
	else cout << "Type de client inconnu..." << endl;
}

void ExecuterOpérations(vector<string> VectorElems, Quincaillerie& Magasin)
{
	if (VectorElems[0] == OUVRIRCAISSE)
	{
		Magasin.GetCaisses().at(stoi(VectorElems[1]) - 1).OuvrirCaisse();
	}
	else if (VectorElems[0] == AJOUTERCLIENT)
	{
		
	}
	else if (VectorElems[0] == QUITTERCAISSE)
	{

	}
	else if (VectorElems[0] == FERMERCAISSE)
	{
		Magasin.GetCaisses().at(stoi(VectorElems[1]) - 1).FermerCaisser();
	}
	else cout << "Type d'opération inconnu..." << endl; 
}

ifstream DemanderFichierClients()
{
	ifstream Fichier; // ifstream correspondant au fichier contenant les données
	string nomFichier; // Variable qui retient le nom du fichier
	do
	{
		cout << "------------------------------------" << endl;
		cout << "Entrez un nom de fichier de clients: " << endl;
		cout << "------------------------------------" << endl;
		cin >> nomFichier;
		Fichier.open(nomFichier);
	} while (Fichier.fail());
	return Fichier;
}

ifstream DemanderFichierOpérations()
{
	ifstream Fichier; // ifstream correspondant au fichier contenant les données
	string nomFichier; // Variable qui retient le nom du fichier
	do
	{
		cout << "--------------------------------------" << endl;
		cout << "Entrez un nom de fichier d'opérations: " << endl;
		cout << "--------------------------------------" << endl;
		cin >> nomFichier;
		Fichier.open(nomFichier);
	} while (Fichier.fail());
	return Fichier;
}

void LireFichierClients(ifstream& fichier)
{
	string ligne;
	string elem;
	/********************TROUVER UN FIX POUR PERMETTRE DES ESPACES AVANT LES MOTS*********************/
	while(getline(fichier, ligne, endline))
	{
		vector<string> VectorElems;
		stringstream ss(ligne);
		while (ss.good())
		{
			getline(ss, elem, delim);
			VectorElems.push_back(elem);
		}
		CreerClient(VectorElems);
	}
}

void LireFichierOpérations(ifstream & Fichier, Quincaillerie& Magasin)
{
}

int main()
{
 	locale::global(locale("")); //Permet les charactères français
	Quincaillerie Magasin(NBCAISSES);

	/****SA MARCHE PAS**/
	Magasin.GetCaisses()[0].AjouterTempsFile(100);
	cout << Magasin.GetCaisses()[0].GetTempsFile() << endl;
	/****SA MARCHE PAS**/

	/*cout << Magasin.GetCaissePlusRapide().GetTempsFile() << endl;
	ifstream FichierClients = DemanderFichierClients();
	LireFichierClients(FichierClients);*/


	/*ifstream FichierOpérations = DemanderFichierOpérations();
	LireFichierOpérations(FichierOpérations);*/
	/*Client::Test();*/
}