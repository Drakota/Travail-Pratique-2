//--------------------------------------------------------
// SourceLecture.cpp
//
// Définition de la classe SourceLecture 
// par Pierre Prud'homme, octobre 2005
//--------------------------------------------------------
#include "sourcelecture.h"

SourceLecture::~SourceLecture()
{
}

void SourceLecture::SetNomSourceLecture(string &sNom)
{
	fEntrée.open(sNom.c_str(), ios::in);
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

void SourceLecture::Lire(int & ligne, int & colonne)
{
	const char ARRET_COORDONNÉE = ';';
	const char SEPARATEUR_COORDONNÉE = ',';
	string coordonnéeLue;
	string chaineLigne;
	string chaineColonne;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntrée, coordonnéeLue, ARRET_COORDONNÉE);
	int positionVirgule = coordonnéeLue.find(SEPARATEUR_COORDONNÉE);
	chaineLigne = coordonnéeLue.substr(0, positionVirgule);
	chaineColonne = coordonnéeLue.substr(positionVirgule + 1, string::npos);

	flux << chaineLigne;   flux >> ligne;   flux.clear(); // nécessaire...
	flux << chaineColonne; flux >> colonne; flux.clear(); 
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
