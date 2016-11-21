//--------------------------------------------------------
//
// Client.h
//
// Définition de la classe Client qui permet de 
// créer un client pour être ajouter dans une caisse
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#include "Client.h"

Client::Client(int NumClient, string CodePostal, string type)
{
	numClient = NumClient;
	codePostal = CodePostal;
	clienType = type;
}

