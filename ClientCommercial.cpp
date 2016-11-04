#include "ClientCommercial.h"

ClientCommercial::ClientCommercial(int NumClient, string CodePostale, string Courriel, string Nom, string Prenom, int Rabais) : Client(NumClient, CodePostale)
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
	flux << codePostal << endl;
	flux << courriel << endl;
	flux << nomClient << endl;
	flux << prenomClient << endl;
	flux << pourcentageRabais << endl;
}
