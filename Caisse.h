#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"
#include <iostream>

class Caisse
{
	// Attributs
	deque<Client*> file;
	bool status;
	int tempsFile;

public:
	// Constructeur
	Caisse();
	
	// Accesseurs
	bool GetStatus() const { return status; }
	int GetTempsFile() const { return tempsFile; }

	// Methodes
	void OuvrirCaisse() { status = OUVERT; }
	void FermerCaisse() { status = FERMÉ; }
	void AjouterTempsFile(int t) { tempsFile += t; }
	void AjouterClientFile(Client* client, float montantAchatClient);
	void RetirerClientFile();
};