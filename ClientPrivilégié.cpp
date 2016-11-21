//--------------------------------------------------------
//
// ClientPrivilégié.h
//
// Définition de la classe ClientPrivilégié qui permet de 
// créer un ClientPrivilégié
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#include "ClientPrivilégié.h"

ClientPrivilégié::ClientPrivilégié(int NumClient, string type, string CodePostale, string Email) : Client(NumClient, CodePostale, type)
{
	courriel = Email;
}

void ClientPrivilégié::Afficher(ostream & flux)
{
	flux << "------------------" << endl;
	flux << "Client Privilégié" << endl;
	flux << "------------------" << endl;
	flux << numClient << endl;
	flux << clienType << endl;
	flux << codePostal << endl;
	flux << courriel << endl;
}
