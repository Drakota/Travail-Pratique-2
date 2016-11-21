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
	float montantAchat;			// Le montant d'achat du client
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
	// Retourne le numéro du client
	// Intrant: -------
	// Extrant: - Le numéro du client
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