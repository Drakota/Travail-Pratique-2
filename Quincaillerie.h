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

	vector<Caisse> GetVectorCaisse() const { return vCaisses; }
    Caisse & GetCaisse(int index) { return vCaisses.at(index); }
	Caisse GetCaissePlusRapide(bool commercial);

	int ConvertirMinuteEnSeconde(string Min);
};

