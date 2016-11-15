#pragma once
#include "Client.h"

class ClientCommercial :
	public Client
{
	string courriel;
	string nomClient;
	string prenomClient;
	float pourcentageRabais;
public:
	ClientCommercial(int NumClient, string type, string CodePostale, string Courriel, string Nom, string Prenom, float Rabais);
	virtual void Afficher(ostream& flux);
	virtual float GetPourcentageRabais() { return pourcentageRabais; }
};