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

	void GetCaissePlusRapide(bool commercial, vector<Caisse*>::iterator & cRapide);

	int ConvertirMinuteEnSeconde(string Min);
};

