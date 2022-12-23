#pragma once
#include <string>

using namespace std;

class Entitat
{
public:

	string getNom() const { return m_nom; };
	string getCodi() const { return m_codi; };
	void setNom(string nom) { m_nom = nom; };
	void setCodi(string codi) { m_codi = codi; };
protected:
	Entitat() : m_nom(""), m_codi("") {};
	Entitat(string nom, string codiIdentificatiu) { m_nom = nom; m_codi = codiIdentificatiu; };
	string m_nom;
	string m_codi;

};

