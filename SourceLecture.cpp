//--------------------------------------------------------
// SourceLecture.cpp
//
// D�finition de la classe SourceLecture 
// par Pierre Prud'homme, octobre 2005
//--------------------------------------------------------
#include "sourcelecture.h"

SourceLecture::~SourceLecture()
{
}

void SourceLecture::SetNomSourceLecture(string &sNom)
{
	fEntr�e.open(sNom.c_str(), ios::in);
	SetOuvertureReussie(!fEntr�e.fail());
}

bool SourceLecture::EstCapableDeLire()
{
	return ouvertureR�ussie;
}

int  SourceLecture::LireEntier()
{
	const char ARRET = ';';
	string chaine;
	int entier;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntr�e, chaine, ARRET);
	flux << chaine;   flux >> entier;   flux.clear(); // n�cessaire...
	return entier;
}

double  SourceLecture::LireDouble()
{
	const char ARRET = ';';
	string chaine;
	double valeur;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntr�e, chaine, ARRET);
	flux << chaine;   flux >> valeur;   flux.clear(); // n�cessaire...
	return valeur;
}

void SourceLecture::Lire(int & ligne, int & colonne)
{
	const char ARRET_COORDONN�E = ';';
	const char SEPARATEUR_COORDONN�E = ',';
	string coordonn�eLue;
	string chaineLigne;
	string chaineColonne;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntr�e, coordonn�eLue, ARRET_COORDONN�E);
	int positionVirgule = coordonn�eLue.find(SEPARATEUR_COORDONN�E);
	chaineLigne = coordonn�eLue.substr(0, positionVirgule);
	chaineColonne = coordonn�eLue.substr(positionVirgule + 1, string::npos);

	flux << chaineLigne;   flux >> ligne;   flux.clear(); // n�cessaire...
	flux << chaineColonne; flux >> colonne; flux.clear(); 
}

char SourceLecture::LireCaractere()
{
	const char ARRET = ';';
	string chaine;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntr�e, chaine, ARRET);
	chaine = Trim(chaine);
	return chaine[0];
}

string SourceLecture::LireChaine()
{
	const char ARRET = ';';
	string chaine;

	// lire jusqu'au ';' ou la fin de ligne
	getline(fEntr�e, chaine, ARRET);
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
	return !fEntr�e.eof();
}

void SourceLecture::SetOuvertureReussie(bool reussi)
{
	ouvertureR�ussie = reussi;
}
