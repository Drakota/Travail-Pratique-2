#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Client
{
protected:
	int numClient;
	int tempsAttenteClient;
	string codePostal;
	string clienType;
	float montantAchat;
public:
	Client(int NumClient, string CodePostal, string ClientType);
	virtual void Afficher(ostream& flux) = 0;

	void SetTempsClient(int tempsEnseconde) { tempsAttenteClient = tempsEnseconde; }
	void SetMontantAchat(float montant) { montantAchat = montant; }

	virtual float GetPourcentageRabais() { return 1; }
	float GetMontantAchat() { return montantAchat; }
	int GetNumClient() const { return numClient; }
	int GetTempsAttenteClient() const { return tempsAttenteClient; }
	string GetTypeClient() const { return clienType; }
};