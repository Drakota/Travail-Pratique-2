#include "Client.h"
vector<Client*> Client::vecClients;

Client::Client(int NumClient, string CodePostal)
{
	vecClients.push_back(this);
	numClient = NumClient;
	codePostal = CodePostal;
}

void Client::Test()
{
	for (int i = 0; i < vecClients.size(); i++)
	{
		vecClients[i]->Afficher(cout);
	}
}
