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
	int tempsFileTotal;		// Temps total d'attente à la caisse
	bool eteOuvert;			// Si la caisse a été ouverte ou non
	float totalAchats;		// Montant total 
	int nbClientServis;		// Nombre de clients servis
	int nbClientsNonServis;	// Nombre de clients non servis
	//
	//////////////////////////////////////////////////////

public:
	// Constructeur par défaut
	Caisse();
	
	////////////////////////////////////////////////////
	// Mutateur

	// SetEteOuvert
	// Modifit la caisse a été ouverte
	// Intrant: - True
	// Extrant: -------
	void SetEteOuvert(bool e) { eteOuvert = e; }

	// SetTotalAchats
	// Modifie le montant total des achats
	// Intrant: - Un montant
	// Extrant: -------
	void SetTotalAchats(float e) { totalAchats = e; }

	// SetNbClientsServis
	// Modifie le nombre de clients servis
	// Intrant: - Un nombre de clients servie
	// Extrant: -------
	void SetNbClientsServis(int e) { nbClientServis = e; }
	// SetNbClientsNonServis
	// Modifie le nombre de clients non servie
	// Intrant: - Un nombre de client non servis
	// Extrant: -------
	void SetNbClientsNonServis(int e) { nbClientsNonServis = e; }
	// SetTempsFileTotal
	// Modifie le temps d'attente total de la caisse
	// Intrant: - Un temps en second d'attente
	// Extrant: -------
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

	// GetFile
	// Retourne la file
	// Intrant: -------
	// Extrant: - Le deque de pointeur de client
	deque<Client*> GetFile() const { return file; }

	// GetNbClientsServis
	// Retourne le nombre de clients servis
	// Intrant: -------
	// Extrant: - Le nombre de clients servis
	int GetNbClientsServis() const { return nbClientServis; }

	// GetNbClientsNonServis
	// Retourne le nombre de clients non servis
	// Intrant: -------
	// Extrant: - Le nombre de clients non servis
	int GetNbClientsNonServis() const { return nbClientsNonServis; }

	// GetTempsFileTotal
	// Retourne le temps d'attente total de la caisse
	// Intrant: -------
	// Extrant: - Le temps d'attente total de la caisse
	int GetTempsFileTotal() const { return tempsFileTotal; }

	// GetÉtéOuvert
	// Retourne si la caisse a été ouverte ou non
	// Intrant: -------
	// Extrant: - Si la caisse a été ouverte ou non
	bool GetEteOuvert() const { return eteOuvert; };

	// GetTotalAchats
	// Retourne le montant total des achats
	// Intrant: -------
	// Extrant: - Le montant total des achats
	float GetTotalAchats() const { return totalAchats; }
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Methodes

	// OuvrirCaisse
	// Ouvre une caisse
	// Intrant: -------
	// Extrant: -------
	void OuvrirCaisse() { status = OUVERT; };

	// FermerCaisse
	// Ferme une caisse
	// Intrant: -------
	// Extrant: -------
	void FermerCaisse() { status = FERMÉ; }

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

	// RetirerClientFile
	// Retir le premier client arriver en file
	// Intrant: -------
	// Extrant: -------
	void RetirerClientFile();
	//
	////////////////////////////////////////////////////
};