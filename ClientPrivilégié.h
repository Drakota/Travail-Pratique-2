//--------------------------------------------------------
//
// ClientPrivilégié.h
//
// Déclaration de la classe ClientPrivilégié qui permet de 
// créer un ClientPrivilégié
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#pragma once
#include "Client.h"

class ClientPrivilégié :
	public Client
{
	////////////////////////////////////////////////////
	// Attributs
	string courriel;		// Contient le couriel du client
	//
	////////////////////////////////////////////////////

public:

	////////////////////////////////////////////////////
	// Constructeur paramétrique de ClientPrivilégié
	ClientPrivilégié(int NumClient, string type, string CodePostale, string Email);
	//
	////////////////////////////////////////////////////


	////////////////////////////////////////////////////
	// Méthode virtual
	// Afficher
	// Affiche les infos du client selon son type
	// Intrant: - Le flux de sortie
	// Extrant: - L'écriture des infos du client
	virtual void Afficher(ostream& flux);
	//
	////////////////////////////////////////////////////
};