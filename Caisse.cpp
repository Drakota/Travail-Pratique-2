#include "Caisse.h"
#include "Constantes.h"

Caisse::Caisse() : tempsFile(0), status(FERMÉ)
{
}

int Caisse::ConvertirMinute(string Min)
{
	int NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
	return NBSecondes;
}

void Caisse::AjouterClientFile(string typeClient)
{
}



