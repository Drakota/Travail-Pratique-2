#include "ClientParticulier.h"

ClientParticulier::ClientParticulier(int NumClient, string type, string CodePostal) : Client(NumClient, CodePostal, type)
{
}

void ClientParticulier::Afficher(ostream & flux)
{
	flux << "-------------------" << endl;
	flux << "Client Particulier" << endl;
	flux << "-------------------" << endl;
	flux << numClient << endl;
	flux << clientype_ << endl;
	flux << codePostal << endl;
}
