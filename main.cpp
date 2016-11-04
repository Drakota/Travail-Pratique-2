// Main.cpp
// Jonathan Bouchard & Pierre-Anthony Houle
// 04 novembre 2016
// Cr�er une file de clients
#include "Constantes.h"
#include "Quincaillerie.h"
#include "ClientParticulier.h"
#include "ClientPrivil�gi�.h"
#include "ClientCommercial.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


ifstream DemanderFichierClients();
ifstream DemanderFichierOp�rations();
void LireFichierClients(ifstream& Fichier);
void LireFichierOp�rations(ifstream& Fichier, Quincaillerie& Magasin);
void CreerClient(vector<string> VectorElems);
void ExecuterOp�rations(vector<string> VectorElems, Quincaillerie& Magasin);


void CreerClient(vector<string> VectorElems)
{
	if (VectorElems[1] == TYPEPARTICULIER) new ClientParticulier(stoi(VectorElems[0]), VectorElems[2]);
	else if(VectorElems[1] == TYPEPRIVILEGIE) new ClientPrivil�gi�(stoi(VectorElems[0]), VectorElems[2], VectorElems[3]);
	else if(VectorElems[1] == TYPECOMMERCIAL) new ClientCommercial(stoi(VectorElems[0]), VectorElems[2], VectorElems[3], VectorElems[4], VectorElems[5], stoi(VectorElems[6]));
	else cout << "Type de client inconnu..." << endl;
}

void ExecuterOp�rations(vector<string> VectorElems, Quincaillerie& Magasin)
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
	else cout << "Type d'op�ration inconnu..." << endl; 
}

ifstream DemanderFichierClients()
{
	ifstream Fichier; // ifstream correspondant au fichier contenant les donn�es
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

ifstream DemanderFichierOp�rations()
{
	ifstream Fichier; // ifstream correspondant au fichier contenant les donn�es
	string nomFichier; // Variable qui retient le nom du fichier
	do
	{
		cout << "--------------------------------------" << endl;
		cout << "Entrez un nom de fichier d'op�rations: " << endl;
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

void LireFichierOp�rations(ifstream & Fichier, Quincaillerie& Magasin)
{
}

int main()
{
 	locale::global(locale("")); //Permet les charact�res fran�ais
	Quincaillerie Magasin(NBCAISSES);

	/****SA MARCHE PAS**/
	Magasin.GetCaisses()[0].AjouterTempsFile(100);
	cout << Magasin.GetCaisses()[0].GetTempsFile() << endl;
	/****SA MARCHE PAS**/

	/*cout << Magasin.GetCaissePlusRapide().GetTempsFile() << endl;
	ifstream FichierClients = DemanderFichierClients();
	LireFichierClients(FichierClients);*/


	/*ifstream FichierOp�rations = DemanderFichierOp�rations();
	LireFichierOp�rations(FichierOp�rations);*/
	/*Client::Test();*/
}