#pragma once
#include <vector>
#include "Caisse.h"
class Quincaillerie
{
	vector<Caisse> vCaisses;
public:
	Caisse Test;
	Quincaillerie(int NBCaisse);

	Caisse & SetCaisse(int index) { return vCaisses.at(index); }

	vector<Caisse> & GetVectorCaisse() { return vCaisses; }
    Caisse & GetCaisse(int index) { return vCaisses.at(index); }

	vector<Caisse>::iterator GetCaissePlusClients();
	vector<Caisse>::iterator GetCaissePlusArgent();
	vector<Caisse>::iterator GetCaissePlusAttente();
	Caisse* GetCaissePlusRapide(bool commercial);
	int ConvertirMinuteEnSeconde(string Min);
};

