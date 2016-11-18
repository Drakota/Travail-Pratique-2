#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Caisse
{
	////////////////////////////////////////////////////
	// Attributs
	deque<Client*> file;	// Contien les clients en ligne
	bool status;			// Statue de la caisse (Fermer/Ouvert)
	int tempsFile;			// Temps d'attente de la ligne
	int tempsFileTotal;
	bool étéOuvert;
	float totalAchats;
	int nbClientServis;
	int nbClientsNonServis;
	//
	//////////////////////////////////////////////////////

public:
	// Constructeur par défaut
	Caisse();
	
	////////////////////////////////////////////////////
	// Mutateur

	void SetEteOuvert(bool e) { étéOuvert = e; }
	void SetTotalAchats(float e) { totalAchats = e; }
	void SetNbClientsServis(int e) { nbClientServis = e; }
	void SetNbClientsNonServis(int e) { nbClientsNonServis = e; }
	void SetTempsFileTotal(int e) { tempsFileTotal = e; }

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

	int GetNbClientsServis() const { return nbClientServis; }
	int GetNbClientsNonServis() const { return nbClientsNonServis; }
	int GetTempsFileTotal() const { return tempsFileTotal; }
	bool GetÉtéOuvert() const { return étéOuvert; };
	float GetTotalAchats() const { return totalAchats; }
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Methodes

	// OuvrirCaisse
	// Ouvre une caisse
	// Intrant: -------
	// Extrant: -------
	void OuvrirCaisse();

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
	void AfficherCaisse(ofstream& flux);
	void RetirerClientFile();
	//
	////////////////////////////////////////////////////
};