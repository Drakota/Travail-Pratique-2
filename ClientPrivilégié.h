//--------------------------------------------------------
//
// ClientPrivil�gi�.h
//
// D�claration de la classe ClientPrivil�gi� qui permet de 
// cr�er un ClientPrivil�gi�
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#pragma once
#include "Client.h"

class ClientPrivil�gi� :
	public Client
{
	////////////////////////////////////////////////////
	// Attributs
	string courriel;		// Contient le couriel du client
	//
	////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////
	// Constructeur param�trique de ClientPrivil�gi�
	ClientPrivil�gi�(int NumClient, string type, string CodePostale, string Email);
	//
	////////////////////////////////////////////////////


	////////////////////////////////////////////////////
	// M�thode virtual
	// Afficher
	// Affiche les infos du client selon son type
	// Intrant: - Le flux de sortie
	// Extrant: - L'�criture des infos du client
	virtual void Afficher(ostream& flux);
	//
	////////////////////////////////////////////////////
};