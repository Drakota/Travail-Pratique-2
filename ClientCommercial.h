#pragma once
#include "Client.h"

class ClientCommercial :
	public Client
{
	string courriel;
	string nomClient;
	string prenomClient;
	int pourcentageRabais;
public:
	ClientCommercial(int NumClient, string type, string CodePostale, string Courriel, string Nom, string Prenom, int Rabais);
	virtual void Afficher(ostream& flux);
};