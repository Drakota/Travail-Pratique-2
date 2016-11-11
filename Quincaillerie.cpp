#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

Caisse Quincaillerie::GetCaissePlusRapide(bool commercial)
{
	vector<Caisse> copie = GetCaisses();
	vector<Caisse>::iterator indice;

	if (commercial == true) indice = copie.begin();
	else indice = copie.begin() + 1;

	auto element = min_element(indice, copie.end(), [](const Caisse& a,  const Caisse& b) {return a.GetTempsFile() < b.GetTempsFile();});
	return *element;
}
