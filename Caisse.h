#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Caisse
{
	// Attributs
	deque<Client*> file;
	bool status;
	int tempsFile;
	int tempsFileTotal;
	bool �t�Ouvert;
	float totalAchats;
	int nbClientServis;
	int nbClientsNonServis;

public:
	// Constructeur
	Caisse();
	
	//Modificateur
	void Set�t�Ouvert(bool e) { �t�Ouvert = e; }
	void SetTotalAchats(float e) { totalAchats = e; }
	void SetNbClientsServis(int e) { nbClientServis = e; }
	void SetNbClientsNonServis(int e) { nbClientsNonServis = e; }
	void SetTempsFileTotal(int e) { tempsFileTotal = e; }

	// Accesseurs
	bool GetStatus() const { return status; }
	int GetTempsFile() const { return tempsFile; }
	bool Get�t�Ouvert() const { return �t�Ouvert; };
	float GetTotalAchats() const { return totalAchats; }
	int GetNbClientsServis() const { return nbClientServis; }
	int GetNbClientsNonServis() const { return nbClientsNonServis; }
	int GetTempsFileTotal() const { return tempsFileTotal; }

	// Methodes
	void OuvrirCaisse() { status = OUVERT; }
	void FermerCaisse() { status = FERM�; }
	void AjouterTempsFile(int t) { tempsFile += t; }
	void AjouterClientFile(Client* client, float montantAchatClient);
	void AfficherCaisse(ofstream& flux);
	void RetirerClientFile();
};