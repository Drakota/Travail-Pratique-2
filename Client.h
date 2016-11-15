#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Client
{
protected:
	////////////////////////////////////////////////////
	// Attributs
	int numClient;				// Numéro du client
	int tempsAttenteClient;		// Temps que va prendre le client à la caisse
	string codePostal;			// Le code postal du client
	string clienType;			// Le type du client
	//
	////////////////////////////////////////////////////
public:

	////////////////////////////////////////////////////
	// Constructeur paramétrique
	Client(int NumClient, string CodePostal, string ClientType);
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Méthodes virtual
	// Afficher
	// Affiche les infos du client selon son type
	// Intrant: - Le flux de sortie
	// Extrant: - L'écriture des infos du client
	virtual void Afficher(ostream& flux) = 0;
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Mutateur
	// SetTempsClient
	// Ajoute le temps d'attente du client
	// Intrant: - Un nombre de secondes
	// Extrant: ------
	void SetTempsClient(int tempsEnseconde) { tempsAttenteClient = tempsEnseconde; }
	//
	////////////////////////////////////////////////////

	int GetNumClient() const { return numClient; }
	int GetTempsAttenteClient() const { return tempsAttenteClient; }
	string GetTypeClient() const { return clienType; }
};