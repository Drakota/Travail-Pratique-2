#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"

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
	int ConvertirMinute(string Min);
	void OuvrirCaisse() { status = OUVERT; }
	void FermerCaisser() { status = FERMÉ; }
	void AjouterTempsFile(int t) { tempsFile += t; }
	void AjouterClientFile(string typeClient);
};