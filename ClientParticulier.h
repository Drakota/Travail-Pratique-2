#pragma once
#include "Client.h"

class ClientParticulier :
	public Client
{
public:
	ClientParticulier(int NumClient, string type, string CodePostal);
	virtual void Afficher(ostream& flux);
};