#pragma once
#include <string>
using namespace std;

// Énum
enum Status { FERMÉ , OUVERT};
enum DemanderFichier { CLIENT, OPÉRATIONS };

// Constantes générales
const int NBCAISSES = 6;

// Constantes pour les types de clients
const string TYPEPARTICULIER = "pa";
const string TYPEPRIVILEGIE = "pr";
const string TYPECOMMERCIAL = "c";

// Constantes pour les opérations
const string OUVRIRCAISSE = "O";
const string AJOUTERCLIENT = "A";
const string QUITTERCAISSE = "T";
const string FERMERCAISSE = "F";