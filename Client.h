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
	string clientype_;
public:
<<<<<<< HEAD
	Client(int NumClient, string CodePostal);
=======
	Client();
	Client(int NumClient, string CodePostal, string ClientType);
>>>>>>> origin/master
	virtual void Afficher(ostream& flux) = 0;
};