//--------------------------------------------------------
//
// SourceLecture.h
//
// Déclaration de la classe SourceLecture qui permet de 
// lire les données en provenance d'un fichier
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
	//---- Construction paramétrique uniquement et destruction
	SourceLecture() {};
	~SourceLecture();

	//----- Modificateurs
	void SetNomSourceLecture(string &sNom);

	//----- Méthode qui permet de savoir si l'objet est capable de lire
	//      Il ne le sera pas si le fichier ne s'est pas ouvert correctement
	bool EstCapableDeLire();

	//----- Méthode qui permet d'obtenir la prochaine valeur lue
	void Lire(vector<string> & vecElems);
	int  LireEntier();
	double LireDouble();
	string LireChaine(); 
	char LireCaractere();

	//----- Méthode qui permet de savoir s'il y a encore des valeurs à lire
	bool PeutEncoreLire();
	static string Trim(string chaine);

private:
	stringstream flux;
	ifstream     fEntrée;					// Nom logique du fichier d'entrée
	bool         ouvertureRéussie;			// Attribut qui indique si on a réussi à ouvrir le fichier correctement

	void SetOuvertureReussie(bool reussi);	// Manipulateur privé de l'attribut ouvertureRéussie

};