#pragma once
#include "Client.h"

class ClientPrivil�gi� :
	public Client
{
	string courriel;
public:
	ClientPrivil�gi�(int NumClient, string CodePostale, string Email);
	virtual void Afficher(ostream& flux);
};