//--------------------------------------------------------
//
// ClientPrivil�gi�.h
//
// D�finition de la classe ClientPrivil�gi� qui permet de 
// cr�er un ClientPrivil�gi�
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#include "ClientPrivil�gi�.h"

ClientPrivil�gi�::ClientPrivil�gi�(int NumClient, string type, string CodePostale, string Email) : Client(NumClient, CodePostale, type)
{
	courriel = Email;
}

void ClientPrivil�gi�::Afficher(ostream & flux)
{
	flux << "------------------" << endl;
	flux << "Client Privil�gi�" << endl;
	flux << "------------------" << endl;
	flux << numClient << endl;
	flux << clienType << endl;
	flux << codePostal << endl;
	flux << courriel << endl;
}
