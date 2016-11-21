#include "Caisse.h"
#include "Constantes.h"

Caisse::Caisse() : tempsFile(0), status(FERMÉ), nbClientServis(0), eteOuvert(false), totalAchats(0), nbClientsNonServis(0), tempsFileTotal(0)
{
}

void Caisse::AjouterClientFile(Client* client, float montantAchatClient)
{
	file.push_back(client);
	tempsFile += client->GetTempsAttenteClient();
	SetTempsFileTotal(GetTempsFileTotal() + client->GetTempsAttenteClient());
	SetNbClientsNonServis(GetNbClientsNonServis() +	1);
	if (client->GetTypeClient() != TYPECOMMERCIAL) client->SetMontantAchat(montantAchatClient);
	else
	{
		montantAchatClient -= (montantAchatClient * (client->GetPourcentageRabais()/100));
		client->SetMontantAchat(montantAchatClient);
	}
}

void Caisse::AfficherCaisse(ofstream& flux)
{
	flux << "À été ouverte: ";
	if (GetEteOuvert()) flux << "VRAI" << endl; else flux << "FAUX" << endl;
	flux << "Nombre de clients servis: " << GetNbClientsServis() << endl;
	flux << "Total des achats encaissés: " << GetTotalAchats() << endl;
	flux << "Nombre de clients non servis: " << GetNbClientsNonServis() << endl;
	for (int i = 0; i < file.size(); i++)
	{
		file.at(i)->Afficher(flux);
	}
	flux << "Temps d'attente à la fin: " << GetTempsFile() << endl;
}

void Caisse::RetirerClientFile()
{
	tempsFile -= file.at(0)->GetTempsAttenteClient();
	SetTotalAchats(GetTotalAchats() + file.at(0)->GetMontantAchat());
	file.pop_front();
	SetNbClientsNonServis(GetNbClientsNonServis() - 1);
	SetNbClientsServis(GetNbClientsServis() + 1);
}



