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
	string clienType;
public:
	Client(int NumClient, string CodePostal, string ClientType);
	virtual void Afficher(ostream& flux) = 0;

	int GetNumClient() const { return numClient; }
	string GetTypeClient() const { return clienType; }
};