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
	Caisse GetCaissePlusRapide();
};

