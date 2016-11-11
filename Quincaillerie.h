#pragma once
#include <vector>
#include "Caisse.h"
class Quincaillerie
{
	vector<Caisse> vCaisses;
public:
	Caisse Test;
	Quincaillerie(int NBCaisse);
    vector<Caisse> GetCaisses() const { return vCaisses; }
	Caisse & SetCaisse(int index)  { return vCaisses.at(index); }
	Caisse GetCaissePlusRapide(bool commercial);
};

