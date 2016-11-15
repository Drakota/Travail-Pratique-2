#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

Caisse* Quincaillerie::GetCaissePlusRapide(bool commercial)
{
	int indiceDepart;
	bool caisseOuverte = false;
	// Si commercial on prend premiere caisse
	// si non on prend la deuxieme
	if (commercial == true) indiceDepart = 0;
	else indiceDepart = 1;

	Caisse* cRapide = &GetCaisse(indiceDepart);

	for (int i = indiceDepart; i < GetVectorCaisse().size(); i++)
	{
		if (GetVectorCaisse().at(i).GetStatus() != FERMÉ)
		{
			caisseOuverte = true;
			if (GetVectorCaisse().at(i).GetTempsFile() < cRapide->GetTempsFile())
				cRapide = &GetVectorCaisse().at(i);
		}
	}

	if (caisseOuverte == false && GetCaisse(0).GetStatus() == OUVERT)
		caisseOuverte = true;

	if (!caisseOuverte)
		throw exception("Il n'y a aucune caisse d'ouverte!");
	return cRapide;
}

int Quincaillerie::ConvertirMinuteEnSeconde(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}