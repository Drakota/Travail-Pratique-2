#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

Caisse & Quincaillerie::GetCaissePlusRapide(bool commercial)
{
	vector<Caisse>::iterator indice;

	if (commercial == true) indice = GetVectorCaisse().begin();
	else indice = GetVectorCaisse().begin() + 1;

    auto iterCaisse = min_element(indice, GetVectorCaisse().end(), [](const Caisse& a, const Caisse& b) 
	{ 
		if (a.GetStatus() == OUVERT && b.GetStatus() == OUVERT)
			return a.GetTempsFile() < b.GetTempsFile();

	});
	return *iterCaisse;
}

int Quincaillerie::ConvertirMinuteEnSeconde(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}
