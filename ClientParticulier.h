#pragma once
#include "Client.h"

class ClientParticulier :
	public Client
{
public:

	////////////////////////////////////////////////////
	// Constructeur param�trique de ClientParticulier
	ClientParticulier(int NumClient, string type, string CodePostal);
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// M�thode virtual
	// Afficher
	// Affiche les infos du client selon son type
	// Intrant: - Le flux de sortie
	// Extrant: - L'�criture des infos du client
	virtual void Afficher(ostream& flux);
	//
	////////////////////////////////////////////////////
};