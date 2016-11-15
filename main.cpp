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
void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient);

void ÉcrireRapport()
{
	
}


void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient)
{
	if (vectorElems.at(1) == TYPEPARTICULIER) vecClient.push_back(new ClientParticulier(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2)));
	else if (vectorElems.at(1) == TYPEPRIVILEGIE) vecClient.push_back(new ClientPrivilégié(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2), vectorElems.at(3)));
	else if (vectorElems.at(1) == TYPECOMMERCIAL) vecClient.push_back(new ClientCommercial(stoi(vectorElems.at(0)), vectorElems.at(1), vectorElems.at(2), vectorElems.at(3), vectorElems.at(4), vectorElems.at(5), stoi(vectorElems.at(6))));
}

void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient)
{
	Caisse* plusRapide;
	if (vectorElems.at(0) == OUVRIRCAISSE)
		if (magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).GetStatus() == FERMÉ)
			magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).OuvrirCaisse();
		else
			throw exception("La caisse était déjà ouverte!");
	else if (vectorElems.at(0) == AJOUTERCLIENT)
	{
		//// Ajoute le temps d'attente dans le client
		vecClient.at(stoi(vectorElems.at(1)) - 1)->SetTempsClient(magasin.ConvertirMinuteEnSeconde(vectorElems.at(2)));
		//// Modifie la caisse (ajoute un client / ajoute le temps d'attente / **faire quelque chose avec le montant**)
		if (vecClient.at(stoi(vectorElems.at(1)) - 1)->GetTypeClient() == TYPECOMMERCIAL)
			plusRapide = magasin.GetCaissePlusRapide(true);
		else
			plusRapide = magasin.GetCaissePlusRapide(false);
		plusRapide->AjouterClientFile(vecClient.at(stoi(vectorElems.at(1)) - 1), stof(vectorElems.at(3)));
	}
	else if (vectorElems.at(0) == QUITTERCAISSE)
	{
		magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).RetirerClientFile();
	}
	else if (vectorElems.at(0) == FERMERCAISSE) magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).FermerCaisse();
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
	do
	{
		try
		{
			vector<string> vecElems;
			fichier.Lire(vecElems);
			if (i == CLIENT) CreerClient(vecElems, vecClient);
			else if (i == OPÉRATIONS) ExecuterOperations(vecElems, magasin, vecClient);
		}
		catch (exception e) { cout << e.what() << endl; }

	} while (fichier.PeutEncoreLire());
}

int main()
{
	locale::global(locale("")); // Permet les charactères français
	vector<Client*> vecClients;
	SourceLecture fichierClients;
	SourceLecture fichierOpérations;
	Quincaillerie magasin(NBCAISSES);
	ofstream fichierEcriture;

	DemanderFichier(CLIENT, fichierClients, fichierEcriture);
	LireFichier(CLIENT, fichierClients, magasin, vecClients);

	DemanderFichier(OPÉRATIONS, fichierOpérations, fichierEcriture);
	LireFichier(OPÉRATIONS, fichierOpérations, magasin, vecClients);

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