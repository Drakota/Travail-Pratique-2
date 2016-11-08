//--------------------------------------------------------
// SourceLecture.cpp
//
// Définition de la classe SourceLecture 
// par Pierre Prud'homme, octobre 2005
//--------------------------------------------------------
#include "sourcelecture.h"
#include <vector>
#include <iostream>

SourceLecture::~SourceLecture()
{
}

void SourceLecture::SetNomSourceLecture(string &sNom)
{
	fEntrée.open(sNom);
	SetOuvertureReussie(!fEntrée.fail());
}

bool SourceLecture::EstCapableDeLire()
{
	return ouvertureRéussie;
}

int  SourceLecture::LireEntier()
{
	const char ARRET = ';';
	string chaine;
	int entier;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntrée, chaine, ARRET);
	flux << chaine;   flux >> entier;   flux.clear(); // nécessaire...
	return entier;
}

double  SourceLecture::LireDouble()
{
	const char ARRET = ';';
	string chaine;
	double valeur;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntrée, chaine, ARRET);
	flux << chaine;   flux >> valeur;   flux.clear(); // nécessaire...
	return valeur;
}

void SourceLecture::Lire(vector<string> & vecElems)
{
	const char ENDLINE = '\n';
	const char ARRET = ';';
	string ligne;
	string elem;

	getline(fEntrée, ligne, ENDLINE);
	stringstream ss(ligne);
	do
	{
		getline(ss, elem, ARRET);
		elem = Trim(elem); 
		vecElems.push_back(elem);
	} while (ss.good());
	//IL Y A UN ENDLINE DE TROP LE SS.GOOD FAIT UNE LOOP DE TROP//
}

char SourceLecture::LireCaractere()
{
	const char ARRET = ';';
	string chaine;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntrée, chaine, ARRET);
	chaine = Trim(chaine);
	return chaine[0];
}

string SourceLecture::LireChaine()
{
	const char ARRET = ';';
	string chaine;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntrée, chaine, ARRET);
	chaine = Trim(chaine);
	return chaine;
}

string SourceLecture::Trim(string chaine)
{
	if (chaine != "")
	{
		const char LF = char(10);
		string resultat = "";
		int positionFin = chaine.size() - 1;
		int positionDebut = 0;

		while (chaine[positionDebut] == ' ' || chaine[positionDebut] == LF) positionDebut++;
		while (chaine[positionFin] == ' ' || chaine[positionFin] == LF) positionFin--;

		return chaine.substr(positionDebut, positionFin - positionDebut + 1);
	}
	/*****************************TEMP FIX******************************/
	else
	{
		return "";
	}
	/*****************************TEMP FIX******************************/
}


bool SourceLecture::PeutEncoreLire()
{
	return !fEntrée.eof();
}

void SourceLecture::SetOuvertureReussie(bool reussi)
{
	ouvertureRéussie = reussi;
}
