//--------------------------------------------------------
//
// ClientCommercial.h
//
// D�finition de la classe ClientCommercial qui permet de 
// cr�er un ClientCommercial
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#include "ClientCommercial.h"

ClientCommercial::ClientCommercial(int NumClient, string type, string CodePostale, string Courriel, string Nom, string Prenom, float Rabais) : Client(NumClient, CodePostale, type)
{
	courriel = Courriel;
	nomClient = Nom;
	prenomClient = Prenom;
	pourcentageRabais = Rabais;
}

void ClientCommercial::Afficher(ostream & flux)
{
	flux << "-----------------" << endl;
	flux << "Client Commercial" << endl;
	flux << "-----------------" << endl;
	flux << numClient << endl;
	flux << clienType << endl;
	flux << codePostal << endl;
	flux << courriel << endl;
	flux << nomClient << endl;
	flux << prenomClient << endl;
	flux << pourcentageRabais << endl;
}
