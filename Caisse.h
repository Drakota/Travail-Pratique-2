#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"
#include <iostream>

class Caisse
{
	////////////////////////////////////////////////////
	// Attributs
	deque<Client*> file;	// Contien les clients en ligne
	bool status;			// Statue de la caisse (Fermer/Ouvert)
	int tempsFile;			// Temps d'attente de la ligne
	//////////////////////////////////////////////////////

public:
	// Constructeur par défaut
	Caisse();
	
	////////////////////////////////////////////////////
	// Accesseurs

	// GetStatus
	// Optient le statue de la caisse
	// Intrant: -------
	// Extrant: - Le statue de la caisse
	bool GetStatus() const { return status; }

	// GetTempsFile
	// Optient le temps d'attente de la caisse
	// Intrant: -------
	// Extrant: - Le temps d'attente de la caisse
	int GetTempsFile() const { return tempsFile; }
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Methodes

	// OuvrirCaisse
	// Ouvre une caisse
	// Intrant: -------
	// Extrant: -------
	void OuvrirCaisse() { status = OUVERT;
	cout << "Ouvrir" << endl;
	}

	// FermerCaisse
	// Ferme une caisse
	// Intrant: -------
	// Extrant: -------
	void FermerCaisse() { status = FERMÉ; 
	cout << "Fermeture" << endl;
	}

	// AjouterTempsFile
	// Ajoute du temps d'attente à la file
	// Intrant: - Un nombre de secondes
	// Extrant: -------
	void AjouterTempsFile(int t) { tempsFile += t; }

	// AjouterClientFile
	// Ajoute un client dans la file d'attente
	// Intrant: - Un pointeur sur un client
	//			- Le montant que le client doit payer
	// Extrant: -------
	void AjouterClientFile(Client* client, float montantAchatClient);

	// RetirerClientFile
	// Retire le premier client arriver dans la file
	// Intrant: -------
	// Extrant: -------
	void RetirerClientFile();
	//
	////////////////////////////////////////////////////
};