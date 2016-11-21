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
#include "Prototype.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


/**Je vais peut etre bouger ste fonction la dans Quincaillerie**/
void EcrireRapport(Quincaillerie& magasin, ofstream& flux)
{
	int index;
	for (int i = 0; i < magasin.GetVectorCaisse().size(); i++)
	{
		flux << "**************************************************" << endl;
		flux << "******************** Caisse " << i + 1 << " ********************" << endl;
		magasin.GetCaisse(i).AfficherCaisse(flux);
		flux << endl;
	}
	flux << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	flux << "@@@@@@@@@@@@@@@@@@@@@ STATS @@@@@@@@@@@@@@@@@@@@@@" << endl;
	index = distance(magasin.GetVectorCaisse().begin(), magasin.GetCaissePlusClients()) + 1;
	flux << "Caisse qui a eu le plus grand nombre de clients: Caisse " << index << endl;
	index = distance(magasin.GetVectorCaisse().begin(), magasin.GetCaissePlusAttente()) + 1;
	flux << "Caisse où il y a eu le plus d’attente: Caisse " << index << endl;
	index = distance(magasin.GetVectorCaisse().begin(), magasin.GetCaissePlusArgent()) + 1;
	flux << "Caisse qui à encaissé le plus d’argent: Caisse " << index << endl;
	flux << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
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
	{
		if (stoi(vectorElems.at(1)) > 0 && stoi(vectorElems.at(1)) <= NBCAISSES)
		{
			magasin.GetCaisse((stoi(vectorElems.at(1)) - 1)).OuvrirCaisse();
			magasin.GetCaisse((stoi(vectorElems.at(1)) - 1)).SetEteOuvert(true);
		}
		else throw exception("Le numéro de la caisse est invalide!");
	}
	else if (vectorElems.at(0) == AJOUTERCLIENT)
	{
		// Ajoute le temps d'attente dans le client
		vecClient.at(stoi(vectorElems.at(1)) - 1)->SetTempsClient(magasin.ConvertirMinuteEnSeconde(vectorElems.at(2)));

		// Modifie la caisse (ajoute un client / ajoute le temps d'attente)
		if (vecClient.at(stoi(vectorElems.at(1)) - 1)->GetTypeClient() == TYPECOMMERCIAL) plusRapide = magasin.GetCaissePlusRapide(true);
		else plusRapide = magasin.GetCaissePlusRapide(false);

		plusRapide->AjouterClientFile(vecClient.at(stoi(vectorElems.at(1)) - 1), stof(vectorElems.at(3)));
	}
	else if (vectorElems.at(0) == QUITTERCAISSE)
	{
		magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).RetirerClientFile();
	}
	else if (vectorElems.at(0) == FERMERCAISSE)
	{
		if (stoi(vectorElems.at(1)) > 0 && stoi(vectorElems.at(1)) <= NBCAISSES)
		{
			magasin.GetCaisse((stoi(vectorElems.at(1)) - 1)).FermerCaisse();
		}
		else throw exception("Le numéro de la caisse est invalide!");
	}
	else throw exception("Type d'opération inconnu...");
}

void DemanderFichier(TypeFichier typeFichier, SourceLecture& fichier, ofstream& fecriture)
{
	string nomFichier;		// Variable qui retient le nom du fichier
	do
	{
		cout << "------------------------------------" << endl;
		if (typeFichier == CLIENT) cout << "Entrez un nom de fichier de clients: " << endl;
		else if (typeFichier == OPÉRATIONS) cout << "Entrez un nom de fichier d'opérations: " << endl;
		cout << "------------------------------------" << endl;
		cin >> nomFichier;
		fichier.SetNomSourceLecture(nomFichier);
	} while (!fichier.EstCapableDeLire());
	if (typeFichier == OPÉRATIONS) fecriture.open("Journal_" + nomFichier);
}

void LireFichier(TypeFichier typeFichier, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient)
{
	do
	{
		try
		{
			vector<string> vecElems;
			fichier.Lire(vecElems);
			if (typeFichier == CLIENT) CreerClient(vecElems, vecClient);
			else if (typeFichier == OPÉRATIONS) ExecuterOperations(vecElems, magasin, vecClient);
		}
		catch (exception e) { cout << e.what() << endl; }
	} while (fichier.PeutEncoreLire());
}

int main()
{
	locale::global(locale(""));			// Permet les charactères français
	vector<Client*> vecClients;			// Vecteur contenant les clients
	SourceLecture fichierClients;		// Le fichier des clients
	SourceLecture fichierOpérations;	// Le fichier des opérations
	Quincaillerie magasin(NBCAISSES);	// La quincaillerie
	ofstream fichierEcriture;			// Le fichier du rapport final

	// Traiter le fichier client
	DemanderFichier(CLIENT, fichierClients, fichierEcriture);
	LireFichier(CLIENT, fichierClients, magasin, vecClients);
	// Traiter le fichier opération
	DemanderFichier(OPÉRATIONS, fichierOpérations, fichierEcriture);
	LireFichier(OPÉRATIONS, fichierOpérations, magasin, vecClients);
	// Écrire le rapport final
	EcrireRapport(magasin, fichierEcriture);
}