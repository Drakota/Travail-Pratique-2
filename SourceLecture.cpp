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
		getline(ss, elem, ARRET); // Permet de retourner chaque paramètre de la ligne
		if (elem != "")
		{
			elem = Trim(elem);
			vecElems.push_back(elem);
		}
	} while (ss.good());
}

string SourceLecture::Trim(string chaine)
{
	const char LF = char(10);
	string resultat = "";
	int positionFin = chaine.size() - 1;
	int positionDebut = 0;

	while (chaine[positionDebut] == ' ' || chaine[positionDebut] == LF) positionDebut++;
	while (chaine[positionFin] == ' ' || chaine[positionFin] == LF) positionFin--;

	return chaine.substr(positionDebut, positionFin - positionDebut + 1);
}

bool SourceLecture::PeutEncoreLire()
{
	return !fEntrée.eof();
}

void SourceLecture::SetOuvertureReussie(bool reussi)
{
	ouvertureRéussie = reussi;
}
