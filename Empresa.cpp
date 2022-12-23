#include "Empresa.h"

Empresa::Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p)
{
	m_name = name;
	m_magatzem = magatzemPrincipal;
	m_proveidor = p;
	for (int i = 0; i < numBotigues; i++)
		m_botigues.push_back(new Botiga());
}

Empresa::Empresa(string name, vector<Botiga*> botigues, vector<Aresta> conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p)
{
	m_proveidor = p;
	m_name = name;
	m_magatzem = magatzemPrincipal;
	m_botigues = botigues;

	Graf g = Graf(botigues, conexionsBotigues);

	for (int i = 0; i < botigues.size(); i++)
	{
		botigues[i]->setMatgatzem(magatzemPrincipal);
		botigues[i]->setveinesOrdenades(g.getBotiguesOrdenades(new Node(botigues[i])));
	}

}

bool Empresa::realitzaComanda(Comanda& c, Proveidor& p)
{
	return p.procesaComanda( c, (*m_magatzem));
}

bool Empresa::realitzaComanda(Comanda& c)
{
	return m_proveidor.procesaComanda(c, (*m_magatzem));
}

int Empresa::getSeguentCodiRus()
{
	return m_num;
}

string Empresa::generaCodiRus(const string& model)
{

	auto Num = std::to_string(m_num);
	string CodiRus = model + Num;
	m_num++;
	return CodiRus;

}

bool Empresa::afegeixSeguiment(Bicicleta* bicicleta)
{
	if (bicicleta == nullptr)
		return false;
	if (bicicleta->getCodiRus() == "")
		return false;
	pair<map<string, DadesSeguiment>::iterator, bool> res = m_taulaSeguiment.emplace(bicicleta->getCodiRus(), DadesSeguiment());
	if(res.second)
		m_taulaSeguiment[bicicleta->getCodiRus()].m_bicicleta = bicicleta;
	return res.second;
}

bool Empresa::actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat)
{
	if (novaEntitat == nullptr)
		return false;
	try {
		m_taulaSeguiment.at(codiRus).m_historic.push_back({ nouEstat, novaEntitat });
		return true;
	}
	catch (out_of_range)
	{
		return false;
	}
}

bool Empresa::comprobaEstatCodi(string codiRus, EstatBicicleta objectiu)
{
	if (m_taulaSeguiment.count(codiRus) > 0)
	{
		bool flag = false;
		vector<pair<EstatBicicleta, Entitat*>> historial = m_taulaSeguiment[codiRus].m_historic;
		vector<pair<EstatBicicleta, Entitat*>>::iterator it = historial.begin();
		while (!flag && it != historial.end())
		{
			flag = (*it).first == objectiu;
			++it;
		}
		return flag;
	}
	return false;

}