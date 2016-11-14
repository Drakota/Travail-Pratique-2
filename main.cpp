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


void DemanderFichier(bool i, SourceLecture& flecture, ofstream& fecriture);
void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient);
void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient);
void ExecuterOpérations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient);

void ÉcrireRapport()
{
	
}


void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient)
{
	if (vectorElems.at(1) == TYPEPARTICULIER) vecClient.push_back(new ClientParticulier(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2)));
	else if (vectorElems.at(1) == TYPEPRIVILEGIE) vecClient.push_back(new ClientPrivilégié(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2), vectorElems.at(3)));
	else if (vectorElems.at(1) == TYPECOMMERCIAL) vecClient.push_back(new ClientCommercial(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2), vectorElems.at(3), vectorElems.at(4), vectorElems.at(5), stoi(vectorElems.at(6))));
}

void ExecuterOpérations(vector<string> vectorElems, Quincaillerie& Magasin, vector<Client*> vecClient)
{
	Caisse* PlusRapide;
	if (vectorElems.at(0) == OUVRIRCAISSE) Magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).OuvrirCaisse();
	else if (vectorElems.at(0) == AJOUTERCLIENT)
	{
		//// Ajoute le temps d'attente dans le client
		vecClient.at(stoi(vectorElems.at(1)) - 1)->SetTempsClient(Magasin.ConvertirMinuteEnSeconde(vectorElems.at(2)));
		//// Modifie la caisse (ajoute un client / ajoute le temps d'attente / **faire quelque chose avec le montant**)
		if (vecClient.at(stoi(vectorElems.at(1)) - 1)->GetTypeClient() == TYPECOMMERCIAL)
			PlusRapide = Magasin.GetCaissePlusRapide(true);
		else
			PlusRapide = Magasin.GetCaissePlusRapide(false);

		PlusRapide->AjouterClientFile(vecClient.at(stoi(vectorElems.at(1)) - 1), stof(vectorElems.at(3)));
	}
	else if (vectorElems.at(0) == QUITTERCAISSE)
	{
		Magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).RetirerClientFile();
	}
	else if (vectorElems.at(0) == FERMERCAISSE) Magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).FermerCaisse();
	else cout << "Type d'opération inconnu..." << endl;
}

void DemanderFichier(bool i, SourceLecture& fichier, ofstream& fecriture)
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
	if (i == OPÉRATIONS) fecriture.open("Journal_" + nomFichier);
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
			else if (i == OPÉRATIONS) ExecuterOpérations(vecElems, magasin, vecClient);
		} while (fichier.PeutEncoreLire());
	}
	catch (const out_of_range& e) { cout << "Impossible de faire l'action" << endl; }
}

int main()
{
	locale::global(locale("")); // Permet les charactères français
	vector<Client*> vecClients;
	SourceLecture FichierClients;
	SourceLecture FichierOpérations;
	Quincaillerie magasin(NBCAISSES);
	ofstream FichierEcriture;

	DemanderFichier(CLIENT, FichierClients, FichierEcriture);
	LireFichier(CLIENT, FichierClients, magasin, vecClients);

	DemanderFichier(OPÉRATIONS, FichierOpérations, FichierEcriture);
	LireFichier(OPÉRATIONS, FichierOpérations, magasin, vecClients);

	/*TEST*/
	for (int i = 0; i < vecClients.size(); i++)
	{
		vecClients.at(i)->Afficher(cout);
	}
	cout << endl << endl;
	for (int i = 0; i < magasin.GetVectorCaisse().size(); i++)
	{
		cout << magasin.GetVectorCaisse().at(i).GetStatus() << endl;
	}
}