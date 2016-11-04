#include "ClientParticulier.h"

ClientParticulier::ClientParticulier(int NumClient, string CodePostal) : Client(NumClient, CodePostal)
{
}

void ClientParticulier::Afficher(ostream & flux)
{
	flux << "-------------------" << endl;
	flux << "Client Particulier" << endl;
	flux << "-------------------" << endl;
	flux << numClient << endl;
	flux << codePostal << endl;
}
