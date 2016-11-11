#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

Caisse Quincaillerie::GetCaissePlusRapide(bool commercial)
{
	vector<Caisse> copie = GetCaisses();
	int debut;
	if (commercial == true)
		debut = copie.begin();
	else
		debut = copie.begin() + 1;
	auto element = min_element(copie.begin(), copie.end(), [](const Caisse& a,  const Caisse& b) {return a.GetTempsFile() < b.GetTempsFile();});
	return *element;
}
