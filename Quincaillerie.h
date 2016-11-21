//--------------------------------------------------------
//
// Quincaillerie.h
//
// Déclaration de la classe Quincaillerie qui permet de 
// créer une instance de quincaillerie qui permet
// d'ajouter ou enlever des clients à des caisses
// par Jonathan Boucard & Pierre-Anthony Houle, 2016
//--------------------------------------------------------
#pragma once
#include <vector>
#include "Caisse.h"
class Quincaillerie
{
	////////////////////////////////////////////////////
	// Attributs
	vector<Caisse> vCaisses;		// Un vecteur contenant les caisses de la quincaillerie
	//
	////////////////////////////////////////////////////
public:

	////////////////////////////////////////////////////
	// Constructeur paramétrique
	Quincaillerie(int NBCaisse);
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Accesseur

	// GetCaisse 
	// Retourne la caisse voulu
	// Intrant: - L'index de la caisse
	// Extrant: - La caisse
	Caisse & GetCaisse(int index) { return vCaisses.at(index); }
	
	// GetVectorCaisse
	// Retourne le vecteur contenant les caisses de la quincaillerie
	// Intrant: -------
	// Extrant: - Le vecteur de caisse
	vector<Caisse> & GetVectorCaisse() { return vCaisses; }

	// GetCaissePlusRapide
	// Retourne la caisse aillant le moins de temps d'attente
	// Intrant: - Si c'est pour un client commercial ou non
	// Extrant: - Un pointeur sur la caisse la plus rapide
	Caisse* GetCaissePlusRapide(bool commercial);

	// GetCaissePlusClients
	// Retourne l'emplacement de la caisse qui
	// a eu le plus de client
	// Intrant: -------
	// Extrant: - Un iterateur du vecteur de caisse
	vector<Caisse>::iterator GetCaissePlusClients();

	// GetCaissePlusArgent
	// Retourne l'emplacement de la caisse qui
	// a fait le plus d'argent
	// Intrant: -------
	// Extrant: - Un iterateur du vecteur de caisse
	vector<Caisse>::iterator GetCaissePlusArgent();

	// GetCaissePlusAttente
	// Retourne l'emplacement de la caisse qui
	// a eu le plus de temps d'attente
	// Intrant: -------
	// Extrant: - Un iterateur du vecteur de caisse
	vector<Caisse>::iterator GetCaissePlusAttente();
	//
	////////////////////////////////////////////////////

	////////////////////////////////////////////////////
	// Méthode

	// ConvertirMinuteEnSeconde
	// Converti un nombre de minutes en nombre de secondes
	// Intrant: - Le string contenant le nombre de minutes
	// Extrant: - Le nombre secondes
	int ConvertirMinuteEnSeconde(string Min);
	//
	////////////////////////////////////////////////////
};

