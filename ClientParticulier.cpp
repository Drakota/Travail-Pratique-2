//--------------------------------------------------------
//
// ClientParticulier.h
//
// Définition de la classe ClientParticulier qui permet de 
// créer un ClientParticulier
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
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
	flux << clienType << endl;
	flux << codePostal << endl;
}
