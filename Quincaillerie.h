#pragma once
#include <vector>
#include "Caisse.h"
class Quincaillerie
{
public:
	vector<Caisse> vCaisses;
	Caisse Test;
	Quincaillerie(int NBCaisse);
    vector<Caisse> & GetCaisses() { return vCaisses; }
	Caisse GetCaissePlusRapide();
};

