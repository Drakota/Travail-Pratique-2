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
	int numClient;				// Num�ro du client
	int tempsAttenteClient;		// Temps que va prendre le client � la caisse
	string codePostal;			// Le code postal du client
	string clienType;			// Le type du client
	float montantAchat;			// Le montant d'achat du client
	//
	////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////
	// Constructeur param�trique
	Client(int NumClient, string CodePostal, string ClientType);
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// M�thodes virtual
	// Afficher
	// Affiche les infos du client selon son type
	// Intrant: - Le flux de sortie
	// Extrant: - L'�criture des infos du client
	virtual void Afficher(ostream& flux) = 0;
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Mutateur

	// SetTempsClient
	// Met le temps d'attente du client
	// Intrant: - Un nombre de secondes
	// Extrant: -------
	void SetTempsClient(int tempsEnseconde) { tempsAttenteClient = tempsEnseconde; }

	// SetMontantAchat
	// Met le montant qu'il doit payer
	// Intrant: - Le montant
	// Extrant: - Le montant du client
	void SetMontantAchat(float montant) { montantAchat = montant; }
	//
	////////////////////////////////////////////////////

	// GetPourcentageRabais
	// Retourne pourcentage du rabais du client
	// Intrant: -------
	// Extrant: -------
	virtual float GetPourcentageRabais() { return 1; }

	// GetMontantAchat
	// Retourne le montant d'achat du client
	// Intrant: -------
	// Extrant: - Le montant d'achat du client
	float GetMontantAchat() const { return montantAchat; }

	// GetNumClient
	// Retourne le num�ro du client
	// Intrant: -------
	// Extrant: - Le num�ro du client
	int GetNumClient() const { return numClient; }

	// GetTempsAttenteClient
	// Retourne le temps d'attente d'un client
	// Intrant: -------
	// Extrant: Le temps d'attente d'un client
	int GetTempsAttenteClient() const { return tempsAttenteClient; }

	// GetTypeClient
	// Retourne le type de client
	// Intrant: -------
	// Extrant: Le type de client
	string GetTypeClient() const { return clienType; }
	//
	////////////////////////////////////////////////////
}