#pragma once
#include <vector>
#include "Caisse.h"
class Quincaillerie
{
	vector<Caisse> vCaisses;
public:
	Quincaillerie(int NBCaisse);
	vector<Caisse> GetCaisses() const { return vCaisses; }
};