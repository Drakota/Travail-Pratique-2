#pragma once
#include <string>
using namespace std;

enum Status { OUVERT, FERM� };
enum DemanderFichier { CLIENT, OP�RATIONS };
const char delim = ';';
const char endline = '\n';
const string TYPEPARTICULIER = "pa";
const string TYPEPRIVILEGIE = "pr";
const string TYPECOMMERCIAL = "c";
const string OUVRIRCAISSE = "O";
const string AJOUTERCLIENT = "A";
const string QUITTERCAISSE = "T";
const string FERMERCAISSE = "F";
const int NBCAISSES = 6;