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
