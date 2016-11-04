#include "ClientPrivilégié.h"

ClientPrivilégié::ClientPrivilégié(int NumClient, string CodePostale, string Email) : Client(NumClient, CodePostale)
{
	courriel = Email;
}

void ClientPrivilégié::Afficher(ostream & flux)
{
	flux << "------------------" << endl;
	flux << "Client Privilégié" << endl;
	flux << "------------------" << endl;
	flux << numClient << endl;
	flux << codePostal << endl;
	flux << courriel << endl;
}
