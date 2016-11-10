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
void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& Magasin, vector<Client*>& vecClient);
void CreerClient(vector<string> VectorElems, vector<Client*>& vecClient);
void ExecuterOpérations(vector<string> VectorElems, Quincaillerie& Magasin);


void CreerClient(vector<string> VectorElems, vector<Client*>& vecClient)
{
	if (VectorElems.at(1) == TYPEPARTICULIER) vecClient.push_back(new ClientParticulier(stoi(VectorElems.at(0)), VectorElems.at(1), VectorElems.at(2)));
	else if (VectorElems.at(1) == TYPEPRIVILEGIE) vecClient.push_back(new ClientPrivilégié(stoi(VectorElems.at(0)), VectorElems.at(1), VectorElems.at(2), VectorElems.at(3)));
	else if (VectorElems.at(1) == TYPECOMMERCIAL) vecClient.push_back(new ClientCommercial(stoi(VectorElems.at(0)), VectorElems.at(1), VectorElems.at(2), VectorElems.at(3), VectorElems.at(4), VectorElems.at(5), stoi(VectorElems.at(6))));
}

void ExecuterOpérations(vector<string> VectorElems, Quincaillerie& Magasin)
{
	if (VectorElems.at(0) == OUVRIRCAISSE) Magasin.SetCaisse((stoi(VectorElems.at(1)) - 1)).OuvrirCaisse();
	else if (VectorElems.at(0) == AJOUTERCLIENT)
	{
		cout << "AJOUTER" << endl;
		/*Magasin.GetCaissePlusRapide().AjouterClientFile();*/
	}
	else if (VectorElems.at(0) == QUITTERCAISSE)
	{
		cout << "QUITTER" << endl;
	}
	else if (VectorElems.at(0) == FERMERCAISSE) Magasin.SetCaisse((stoi(VectorElems.at(1)) - 1)).FermerCaisse();
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

void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient)
{
	try
	{
		do
		{
			vector<string> vecElems;
			fichier.Lire(vecElems);
			if (i == CLIENT) CreerClient(vecElems, vecClient);
			else if (i == OPÉRATIONS) ExecuterOpérations(vecElems, magasin);
		} while (fichier.PeutEncoreLire());
	}
	catch (const out_of_range& e) { cout << "Impossible de faire l'action" << endl; }
}

int main()
{
	locale::global(locale("")); //Permet les charactères français
	vector<Client*> vecClients;
	SourceLecture FichierClients;
	SourceLecture FichierOpérations;
	Quincaillerie magasin(NBCAISSES);

	DemanderFichier(CLIENT, FichierClients);
	LireFichier(CLIENT, FichierClients, magasin, vecClients);

	DemanderFichier(OPÉRATIONS, FichierOpérations);
	LireFichier(OPÉRATIONS, FichierOpérations, magasin, vecClients);

	/*TEST*/
	for (int i = 0; i < vecClients.size(); i++)
	{
		vecClients.at(i)->Afficher(cout);
	}
	cout << endl << endl;
	for (int i = 0; i < magasin.GetCaisses().size(); i++)
	{
		cout << magasin.GetCaisses().at(i).GetStatus() << endl;
	}
}