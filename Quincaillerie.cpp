#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

Caisse Quincaillerie::GetCaissePlusRapide()
{
	vector<Caisse> copie = GetCaisses();
	auto element = min_element(copie.begin(), copie.end(), [](const Caisse& a,  const Caisse& b) {return a.GetTempsFile() < b.GetTempsFile();});
	return *element;
}
