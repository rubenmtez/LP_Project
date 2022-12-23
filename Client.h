#pragma once
#include <vector>
#include <algorithm>


#include "Bicicleta.h"
#include "Botiga.h"
#include "Entitat.h"


class Client : public Entitat
{
public:
	Client() = default;
	Client(string nom, string dni) : Entitat(nom, dni) {};
	bool comprarBicicleta(string model, Botiga &b);
	vector<Bicicleta*>& getBicicletes() { return m_bicicletes; };
	void setBicicletes(vector<Bicicleta*> bicis) { m_bicicletes = bicis; };

private:
	vector<Bicicleta*> m_bicicletes;
    
};

