//--------------------------------------------------------
//
// SourceLecture.h
//
// D�claration de la classe SourceLecture qui permet de 
// lire les donn�es en provenance d'un fichier
// par Pierre Prud'homme, octobre 2005
//--------------------------------------------------------
#include <fstream>
#include <string>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class SourceLecture
{
public:
	//---- Construction param�trique uniquement et destruction
	SourceLecture() {};
	~SourceLecture();

	//----- Modificateurs
	void SetNomSourceLecture(string &sNom);

	//----- M�thode qui permet de savoir si l'objet est capable de lire
	//      Il ne le sera pas si le fichier ne s'est pas ouvert correctement
	bool EstCapableDeLire();

	//----- M�thode qui permet d'obtenir la prochaine valeur lue
	void Lire(vector<string> & vecElems);
	int  LireEntier();
	double LireDouble();
	string LireChaine(); 
	char LireCaractere();

	//----- M�thode qui permet de savoir s'il y a encore des valeurs � lire
	bool PeutEncoreLire();
	static string Trim(string chaine);

private:
	stringstream flux;
	ifstream     fEntr�e;					// Nom logique du fichier d'entr�e
	bool         ouvertureR�ussie;			// Attribut qui indique si on a r�ussi � ouvrir le fichier correctement

	void SetOuvertureReussie(bool reussi);	// Manipulateur priv� de l'attribut ouvertureR�ussie

};