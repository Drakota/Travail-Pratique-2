// Main.cpp
// Jonathan Bouchard & Pierre-Anthony Houle
// 04 novembre 2016
// Créer une file de clients

#include "Constantes.h"
#include "Quincaillerie.h"
#include "ClientParticulier.h"
#include "ClientPrivilégié.h"
#include "ClientCommercial.h"
#include "SourceLecture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


void DemanderFichier(bool i, SourceLecture& fichier);
void LireFichierClients(SourceLecture& fichier);
void LireFichierOpérations(ifstream& Fichier, Quincaillerie& Magasin);
void CreerClient(vector<string> VectorElems);
void ExecuterOpérations(vector<string> VectorElems, Quincaillerie& Magasin);


void CreerClient(vector<string> VectorElems)
{
	if (VectorElems.at(1) == TYPEPARTICULIER) new ClientParticulier(stoi(VectorElems.at(0)), VectorElems.at(2));
	else if (VectorElems.at(1) == TYPEPRIVILEGIE) new ClientPrivilégié(stoi(VectorElems.at(0)), VectorElems.at(2), VectorElems.at(3));
	else if (VectorElems.at(1) == TYPECOMMERCIAL) new ClientCommercial(stoi(VectorElems.at(0)), VectorElems.at(2), VectorElems.at(3), VectorElems.at(4), VectorElems.at(5), stoi(VectorElems.at(6)));
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

void DemanderFichier(bool i, SourceLecture& fichier)
{
	string nomFichier; // Variable qui retient le nom du fichier
	do
	{
		cout << "------------------------------------" << endl;
		if (i == CLIENT) cout << "Entrez un nom de fichier de clients: " << endl;
		else if (i == OPÉRATIONS) cout << "Entrez un nom de fichier d'opérations: " << endl;
		cout << "------------------------------------" << endl;
		cin >> nomFichier;
		fichier.SetNomSourceLecture(nomFichier);
	} while (!fichier.EstCapableDeLire());
}

void LireFichierClients(SourceLecture& fichier)
{
	try
	{
		do
		{
			vector<string> VecElems;
			fichier.Lire(VecElems);
			CreerClient(VecElems);
		} while (fichier.EstCapableDeLire());
	}
	/**************************LOOP A LINFINI************************/
	catch (const out_of_range& e) { cout << "Impossible de créer un client" << endl; }
}

void LireFichierOpérations(ifstream & Fichier, Quincaillerie& Magasin)
{
}

int main()
{
	locale::global(locale("")); //Permet les charactères français
	SourceLecture Fichier;
	Quincaillerie Magasin(NBCAISSES);

	DemanderFichier(CLIENT, Fichier);
	LireFichierClients(Fichier);


	/*ifstream FichierOpérations = DemanderFichierOpérations();
	LireFichierOpérations(FichierOpérations);*/
	Client::Test();
}