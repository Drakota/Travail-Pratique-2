#include "ClientPrivil�gi�.h"

ClientPrivil�gi�::ClientPrivil�gi�(int NumClient, string CodePostale, string Email) : Client(NumClient, CodePostale)
{
	courriel = Email;
}

void ClientPrivil�gi�::Afficher(ostream & flux)
{
	flux << "------------------" << endl;
	flux << "Client Privil�gi�" << endl;
	flux << "------------------" << endl;
	flux << numClient << endl;
	flux << codePostal << endl;
	flux << courriel << endl;
}
