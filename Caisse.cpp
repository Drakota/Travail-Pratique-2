#include "Caisse.h"
#include "Constantes.h"

Caisse::Caisse() : tempsFile(0), status(FERM�)
{
}

void Caisse::AjouterClientFile(Client* client, int tempsClient, float montantAchatClient)
{
	file.push_back(client);
	tempsFile += tempsClient;
}



