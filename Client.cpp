#include "Client.h"

Client::Client()
{
}

Client::Client(int NumClient, string CodePostal, string type)
{
	numClient = NumClient;
	codePostal = CodePostal;
	clientype_ = type;
}

