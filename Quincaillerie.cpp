#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

void Quincaillerie::GetCaissePlusRapide(bool commercial, Caisse& cRapide)
{
	vector<Caisse>::iterator indice;
    cRapide.AjouterTempsFile(10000000);

	if (commercial == true) indice = GetVectorCaisse().begin();
	else indice = GetVectorCaisse().begin() + 1;

<<<<<<< HEAD
    auto iterCaisse = min_element(indice, GetVectorCaisse().end(), [](const Caisse& a, const Caisse& b) 
	{ 
		if (a.GetStatus() == OUVERT && b.GetStatus() == OUVERT)
			return a.GetTempsFile() < b.GetTempsFile();

	});
	return *iterCaisse;
=======
	for (int i = 0; i < GetVectorCaisse().size(); i++)
	{
		if (GetVectorCaisse().at(i).GetStatus() != FERMÉ)
		{
			if (GetVectorCaisse().at(i).GetTempsFile() < cRapide.GetTempsFile())
			{
				cRapide = GetVectorCaisse().at(i);
			}
		}
	}
>>>>>>> refs/remotes/origin/JO
}

int Quincaillerie::ConvertirMinuteEnSeconde(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}
