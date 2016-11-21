//--------------------------------------------------------
//
// ClientParticulier.h
//
// Déclaration de la classe ClientParticulier qui permet de 
// créer un ClientParticulier
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#pragma once
#include "Client.h"

class ClientParticulier :
	public Client
{
public:

	////////////////////////////////////////////////////
	// Constructeur paramétrique de ClientParticulier
	ClientParticulier(int NumClient, string type, string CodePostal);
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