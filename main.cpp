// Main.cpp
// Jonathan Bouchard & Pierre-Anthony Houle
// 04 novembre 2016
// Cr�er une file de clients

#include "Constantes.h"
#include "Quincaillerie.h"
#include "ClientParticulier.h"
#include "ClientPrivil�gi�.h"
#include "ClientCommercial.h"
#include "SourceLecture.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


void DemanderFichier(bool i, SourceLecture& fichier);
<<<<<<< HEAD
void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& Magasin, vector<Client*>& vecClient);
void CreerClient(vector<string> VectorElems, vector<Client*>& vecClient);
=======
void LireFichierClients(SourceLecture& fichier);
void LireFichierOp�rations(SourceLecture& Fichier, Quincaillerie& Magasin);
void CreerClient(vector<string> VectorElems);
>>>>>>> origin/master
void ExecuterOp�rations(vector<string> VectorElems, Quincaillerie& Magasin);


void CreerClient(vector<string> VectorElems, vector<Client*>& vecClient)
{
	if (VectorElems.at(1) == TYPEPARTICULIER) vecClient.push_back(new ClientParticulier(stoi(VectorElems.at(0)), VectorElems.at(2)));
	else if (VectorElems.at(1) == TYPEPRIVILEGIE) vecClient.push_back(new ClientPrivil�gi�(stoi(VectorElems.at(0)), VectorElems.at(2), VectorElems.at(3)));
	else if (VectorElems.at(1) == TYPECOMMERCIAL) vecClient.push_back(new ClientCommercial(stoi(VectorElems.at(0)), VectorElems.at(2), VectorElems.at(3), VectorElems.at(4), VectorElems.at(5), stoi(VectorElems.at(6))));
}

void ExecuterOp�rations(vector<string> VectorElems, Quincaillerie& Magasin)
{
	if (VectorElems[0] == OUVRIRCAISSE)
	{
		cout << "OUVRIR" << endl;
	}
	else if (VectorElems[0] == AJOUTERCLIENT)
	{
<<<<<<< HEAD
		cout << "AJOUTER" << endl;
=======
		
		Magasin.GetCaissePlusRapide().AjouterClientFile()
>>>>>>> origin/master
	}
	else if (VectorElems[0] == QUITTERCAISSE)
	{
		cout << "QUITTER" << endl;
	}
	else if (VectorElems[0] == FERMERCAISSE)
	{
		cout << "FERMER" << endl;
	}
	else cout << "Type d'op�ration inconnu..." << endl;
}

void DemanderFichier(bool i, SourceLecture& fichier)
{
	string nomFichier; // Variable qui retient le nom du fichier
	do
	{
		cout << "------------------------------------" << endl;
		if (i == CLIENT) cout << "Entrez un nom de fichier de clients: " << endl;
		else if (i == OP�RATIONS) cout << "Entrez un nom de fichier d'op�rations: " << endl;
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
			else if (i == OP�RATIONS) ExecuterOp�rations(vecElems, magasin);
		} while (fichier.EstCapableDeLire());
	}
	/**************************LOOP A LINFINI************************/
	catch (const out_of_range& e) { cout << "Impossible de cr�er un client" << endl; }
}

<<<<<<< HEAD
=======
void LireFichierOp�rations(SourceLecture& fichier, Quincaillerie& magasin)
{
	try
	{
		do
		{
			vector<string> VecElems;
			fichier.Lire(VecElems);
			ExecuterOp�rations(VecElems, magasin);
		} while (fichier.EstCapableDeLire());
	}
	/**************************LOOP A LINFINI************************/
	catch (const out_of_range& e) { cout << "Impossible de cr�er un client" << endl; }
}

>>>>>>> origin/master
int main()
{
	locale::global(locale("")); //Permet les charact�res fran�ais
	vector<Client*> vecClients;
	SourceLecture FichierClients;
	SourceLecture FichierOp�rations;
	Quincaillerie magasin(NBCAISSES);

<<<<<<< HEAD
	DemanderFichier(CLIENT, FichierClients);
	LireFichier(CLIENT, FichierClients, magasin, vecClients);
=======
	DemanderFichier(CLIENT, Fichier);
	LireFichierClients(Fichier);
	DemanderFichier(OP�RATIONS, Fichier);
	LireFichierOp�rations(Fichier, Magasin);
>>>>>>> origin/master

	DemanderFichier(OP�RATIONS, FichierOp�rations);
	LireFichier(OP�RATIONS, FichierOp�rations, magasin, vecClients);

	/*ifstream FichierOp�rations = DemanderFichierOp�rations();
	LireFichierOp�rations(FichierOp�rations);*/
	for (int i = 0; i < vecClients.size(); i++)
	{
		vecClients.at(i)->Afficher(cout);
	}
}