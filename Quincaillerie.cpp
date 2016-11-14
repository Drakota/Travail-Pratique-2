#include "Quincaillerie.h"
#include <iostream>
#include <algorithm>

Quincaillerie::Quincaillerie(int NBCaisse) : vCaisses(NBCaisse)
{
}


void Quincaillerie::GetCaissePlusRapide(bool commercial, vector<Caisse*>::iterator & cRapide)
{
	vector<Caisse>::iterator indice;

	/*if (commercial == true) indice = copie.begin();
	else indice = copie.begin() + 1;*/

	cRapide = min_element(GetVectorCaisse().begin(), GetVectorCaisse().end(), [](const Caisse& a,  const Caisse& b) {return a.GetTempsFile() < b.GetTempsFile();});
}

int Quincaillerie::ConvertirMinuteEnSeconde(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}
