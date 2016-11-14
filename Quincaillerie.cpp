#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}

<<<<<<< HEAD

void Quincaillerie::GetCaissePlusRapide(bool commercial, vector<Caisse*>::iterator & cRapide)
{
	vector<Caisse>::iterator indice;

	/*if (commercial == true) indice = copie.begin();
	else indice = copie.begin() + 1;*/

	cRapide = min_element(GetVectorCaisse().begin(), GetVectorCaisse().end(), [](const Caisse& a,  const Caisse& b) {return a.GetTempsFile() < b.GetTempsFile();});
=======
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
		if (GetVectorCaisse().at(i).GetStatus() != FERMÉ && GetVectorCaisse().at(i).GetTempsFile() < cRapide->GetTempsFile())
			cRapide = &GetVectorCaisse().at(i);
	}
	return cRapide;
>>>>>>> refs/remotes/origin/P-A
}

int Quincaillerie::ConvertirMinuteEnSeconde(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}
