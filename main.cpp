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


<<<<<<< HEAD
=======
void DemanderFichier(bool i, SourceLecture& flecture, ofstream& fecriture);
void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient, ofstream& flux);
void CreerClient(vector<string> vectorElems, vector<Client*>& vecClient);
void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient, ofstream& flux);
void ÉcrireRapport(Quincaillerie& magasin, ofstream& flux);
Client* GetClientByNum(vector<Client*> vecClients, int Num);


>>>>>>> refs/remotes/origin/JO
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

void ExecuterOperations(vector<string> vectorElems, Quincaillerie& magasin, vector<Client*> vecClient, ofstream& flux)
{
	Caisse* plusRapide;
	try
	{
		if (vectorElems.at(0) == OUVRIRCAISSE)
		{
<<<<<<< HEAD
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
=======
			if (stoi(vectorElems.at(1)) - 1 >= 0 && stoi(vectorElems.at(1)) - 1 < NBCAISSES)
			{
				if (magasin.GetCaisse((stoi(vectorElems.at(1)) - 1)).GetStatus() != OUVERT)
				{
					magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).OuvrirCaisse();
					magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).SetEteOuvert(true);
					flux << "--OUVERTURE DE LA CAISSE #" << vectorElems.at(1) << endl;
				}
				else flux << "CAISSE #" << vectorElems.at(1) << " DÉJÀ OUVERTE" << endl;
			}
			else throw exception("Le numéro de la caisse est invalide!");
		}
		else if (vectorElems.at(0) == AJOUTERCLIENT)
		{
			if (stoi(vectorElems.at(1)) - 1 >= 0 && stoi(vectorElems.at(1)) - 1 < vecClient.size())
			{
				Client* client = GetClientByNum(vecClient, stoi(vectorElems.at(1)));
				//// Ajoute le temps d'attente dans le client
				client->SetTempsClient(magasin.ConvertirMinuteEnSeconde(vectorElems.at(2)));

				//// Modifie la caisse (ajoute un client / ajoute le temps d'attente / **faire quelque chose avec le montant**)
				if (client->GetTypeClient() == TYPECOMMERCIAL) plusRapide = magasin.GetCaissePlusRapide(true);
				else plusRapide = magasin.GetCaissePlusRapide(false);

				plusRapide->AjouterClientFile(client, stof(vectorElems.at(3)));
				flux << "--AJOUT CLIENT #" << vectorElems.at(1) << endl;
			}
			else throw exception("Client Invalide!");
		}
		else if (vectorElems.at(0) == QUITTERCAISSE)
		{
			if (stoi(vectorElems.at(1)) - 1 >= 0 && stoi(vectorElems.at(1)) - 1 < NBCAISSES)
			{
				if (magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).GetFile().size() != 0)
				{
					magasin.GetCaisse(stoi(vectorElems.at(1)) - 1).RetirerClientFile();
					flux << "--TERMINER CAISSE #" << vectorElems.at(1) << endl;
				}
				else throw exception("Caisse Vide!");
			}
			else throw exception("Le numéro de la caisse est invalide!");
		}
		else if (vectorElems.at(0) == FERMERCAISSE)
		{
				if (stoi(vectorElems.at(1)) - 1 >= 0 && stoi(vectorElems.at(1)) - 1 < NBCAISSES)
				{
					if (magasin.GetCaisse((stoi(vectorElems.at(1)) - 1)).GetStatus() != FERMÉ)
					{
						magasin.SetCaisse((stoi(vectorElems.at(1)) - 1)).FermerCaisse();
						flux << "--FERMETURE DE LA CAISSE #" << vectorElems.at(1) << endl;
					}
					else flux << "CAISSE #" << vectorElems.at(1) << " DÉJÀ FERMÉ" << endl;
				}
				else throw exception("Le numéro de la caisse est invalide!");
>>>>>>> refs/remotes/origin/JO
		}
		else throw exception("Type d'opération inconnu...");
	}
	catch (exception e) { flux << e.what() << endl; }
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

<<<<<<< HEAD
void LireFichier(TypeFichier typeFichier, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient)
=======
void LireFichier(bool i, SourceLecture& fichier, Quincaillerie& magasin, vector<Client*>& vecClient, ofstream& flux)
>>>>>>> refs/remotes/origin/JO
{
	do
	{
		vector<string> vecElems;
		fichier.Lire(vecElems);
		if (i == CLIENT) CreerClient(vecElems, vecClient);
		else if (i == OPÉRATIONS) ExecuterOperations(vecElems, magasin, vecClient, flux);
	} while (fichier.PeutEncoreLire());
}

Client* GetClientByNum(vector<Client*> vecClients, int Num)
{
	Client* client;
	for (int i = 0; i < vecClients.size(); i++)
	{
		if (vecClients.at(i)->GetNumClient() == Num)
		{
<<<<<<< HEAD
			vector<string> vecElems;
			fichier.Lire(vecElems);
			if (typeFichier == CLIENT) CreerClient(vecElems, vecClient);
			else if (typeFichier == OPÉRATIONS) ExecuterOperations(vecElems, magasin, vecClient);
		}
		catch (exception e) { cout << e.what() << endl; }
	} while (fichier.PeutEncoreLire());
=======
			client = vecClients.at(i);
		}
	}
	return client;
>>>>>>> refs/remotes/origin/JO
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
<<<<<<< HEAD
	LireFichier(CLIENT, fichierClients, magasin, vecClients);
	// Traiter le fichier opération
	DemanderFichier(OPÉRATIONS, fichierOpérations, fichierEcriture);
	LireFichier(OPÉRATIONS, fichierOpérations, magasin, vecClients);
	// Écrire le rapport final
	EcrireRapport(magasin, fichierEcriture);
=======
	LireFichier(CLIENT, fichierClients, magasin, vecClients, fichierEcriture);

	DemanderFichier(OPÉRATIONS, fichierOpérations, fichierEcriture);
	LireFichier(OPÉRATIONS, fichierOpérations, magasin, vecClients, fichierEcriture);

	ÉcrireRapport(magasin, fichierEcriture);
>>>>>>> refs/remotes/origin/JO
}