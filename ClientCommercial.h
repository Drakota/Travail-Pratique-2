//--------------------------------------------------------
//
// ClientCommercial.h
//
// Déclaration de la classe ClientCommercial qui permet de 
// créer un ClientCommercial
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#pragma once
#include "Client.h"

class ClientCommercial :
	public Client
{
	////////////////////////////////////////////////////
	// Attributs
	string courriel;			// Contient le couriel du client
	string nomClient;			// Contient le nom de famille du client
	string prenomClient;		// Contient le prenm du client
	float pourcentageRabais;	// Contient le rabais du client en %
	//
	////////////////////////////////////////////////////
public:

	////////////////////////////////////////////////////
	// Constructeur paramétrique de ClientCommercial
	ClientCommercial(int NumClient, string type, string CodePostale, string Courriel, string Nom, string Prenom, float Rabais);
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

	////////////////////////////////////////////////////
	// Accesseur

	// GetPourcentageRabais
	// Retourne le pourcentage du rabais du client
	// Intrant: -------
	// Extrant: - Le pourcentage du rabais du client
	virtual float GetPourcentageRabais() { return pourcentageRabais; }
	//
	////////////////////////////////////////////////////
};