#include "Quincaillerie.h"
#include <algorithm>
#include <iostream>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

vector<Caisse>::iterator Quincaillerie::GetCaissePlusClients()
{
	return max_element(GetVectorCaisse().begin(), GetVectorCaisse().end(), [] (const Caisse& a, const Caisse& b) 
	{return a.GetNbClientsNonServis() + a.GetNbClientsServis() < b.GetNbClientsNonServis() + b.GetNbClientsServis(); });
}

vector<Caisse>::iterator Quincaillerie::GetCaissePlusArgent()
{
	return max_element(GetVectorCaisse().begin(), GetVectorCaisse().end(), [](const Caisse& a, const Caisse& b)
	{ return a.GetTotalAchats() < b.GetTotalAchats(); });
}

vector<Caisse>::iterator Quincaillerie::GetCaissePlusAttente()
{
	return max_element(GetVectorCaisse().begin(), GetVectorCaisse().end(), [](const Caisse& a, const Caisse& b)
	{ return a.GetTempsFileTotal() < b.GetTempsFileTotal(); });
}


Caisse* Quincaillerie::GetCaissePlusRapide(bool commercial)
{
	int indiceDepart;								// L'indice de la première caisse selon le type de client
	if (commercial == true) indiceDepart = 0;
	else indiceDepart = 1;

	bool caisseOuverte = false;						// True si une caisse est ouverte dans la recherche si non false
	Caisse* cRapide = &GetCaisse(indiceDepart);		// Un pointeur sur la caisse aillant le moins de temps d'attente

	for (int i = indiceDepart; i < GetVectorCaisse().size(); i++)
	{
		if (GetVectorCaisse().at(i).GetStatus() != FERMÉ)
		{
			caisseOuverte = true;
			if (GetVectorCaisse().at(i).GetTempsFile() < cRapide->GetTempsFile())
				cRapide = &GetVectorCaisse().at(i);
		}
	}
	if (caisseOuverte == false && GetCaisse(indiceDepart).GetStatus() == OUVERT)
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