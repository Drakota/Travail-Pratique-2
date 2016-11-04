#pragma once
#include "Client.h"
#include <deque>
#include "Constantes.h"

class Caisse
{
	deque<Client*> file;
	bool status;
public:
	Caisse();
	int ConvertirMinute(string Min);
	void OuvrirCaisse() { status = OUVERT; }
	void FermerCaisser() { status = FERMÉ; }
	bool GetStatus() const { return status; }
};