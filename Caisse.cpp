#include "Caisse.h"
#include "Constantes.h"

Caisse::Caisse() : tempsFile(0), status(FERMÉ)
{
}

void Caisse::AjouterClientFile(Client* client, float montantAchatClient)
{
	file.push_back(client);
	tempsFile += client->GetTempsAttenteClient();
}

void Caisse::RetirerClientFile()
{
	tempsFile -= file.at(0)->GetTempsAttenteClient();
	file.pop_front();
}



