#pragma once
#include <string>
using namespace std;

// �num
enum Status { OUVERT, FERM� };
enum DemanderFichier { CLIENT, OP�RATIONS };

// Constantes g�n�rales
const char delim = ';';
const char endline = '\n';
const int NBCAISSES = 6;

// Constantes pour les types de clients
const string TYPEPARTICULIER = "pa";
const string TYPEPRIVILEGIE = "pr";
const string TYPECOMMERCIAL = "c";

// Constantes pour les op�rations
const string OUVRIRCAISSE = "O";
const string AJOUTERCLIENT = "A";
const string QUITTERCAISSE = "T";
const string FERMERCAISSE = "F";