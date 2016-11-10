#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Client
{
protected:
    static vector<Client*> vecClients;
	int numClient;
	string codePostal;
public:
	Client(int NumClient, string CodePostal);
	virtual void Afficher(ostream& flux) = 0;
	static void Test();
};