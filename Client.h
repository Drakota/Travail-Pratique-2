#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Client
{
protected:
	int numClient;
	string codePostal;
public:
	Client();
	Client(int NumClient, string CodePostal);
	virtual void Afficher(ostream& flux) = 0;
};