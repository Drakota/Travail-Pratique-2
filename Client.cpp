//--------------------------------------------------------
//
// Client.h
//
// D�finition de la classe Client qui permet de 
// cr�er un client pour �tre ajouter dans une caisse
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#include "Client.h"

Client::Client(int NumClient, string CodePostal, string type)
{
	numClient = NumClient;
	codePostal = CodePostal;
	clienType = type;
}

