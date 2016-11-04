#include "Caisse.h"
#include "Constantes.h"

Caisse::Caisse()
{
	status = FERMÉ;
}

int Caisse::ConvertirMinute(string Min)
{
	int NBSecondes;
	return NBSecondes = stoi(Min.substr(0, Min.find(":"))) * 60 + stoi(Min.substr(Min.find(":") + 1, Min.size()));
}

