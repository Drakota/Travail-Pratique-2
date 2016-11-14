#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

Caisse* Quincaillerie::GetCaissePlusRapide(bool commercial)
{
	int indice;

	// Si commercial on prend premiere caisse
	// si non on prend la deuxieme
	if (commercial == true) indice = 0;
	else indice = 1;

	Caisse* cRapide = &GetCaisse(indice);

	for (int i = indice; i < GetVectorCaisse().size(); i++)
	{
		if (GetVectorCaisse().at(i).GetStatus() != FERM� && GetVectorCaisse().at(i).GetTempsFile() < cRapide->GetTempsFile())
			cRapide = &GetVectorCaisse().at(i);
	}
	return cRapide;
}

int Quincaillerie::ConvertirMinuteEnSeconde(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}