#pragma once
#include "Client.h"

class ClientPrivilégié :
	public Client
{
	string courriel;
public:
	ClientPrivilégié(int NumClient, string type, string CodePostale, string Email);
	virtual void Afficher(ostream& flux);
};