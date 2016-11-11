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
<<<<<<< HEAD

	ClientCommercial(int NumClient, string CodePostale, string Courriel, string Nom, string Prenom, int Rabais);
=======
	ClientCommercial(int NumClient, string type, string CodePostale, string Courriel, string Nom, string Prenom, int Rabais);
>>>>>>> origin/master
	virtual void Afficher(ostream& flux);
};