#include "Magatzem.h"
#include "Empresa.h"
#include <fstream>
using namespace std;

void Magatzem::enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada)
{

	for (auto itPaquet = paquet.begin(); itPaquet != paquet.end(); itPaquet++)
	{
		(*itPaquet)->setDataEntrada(dataEntrada);
		string tipus;
		string tipus_model = (*itPaquet)->getModel();
		if ((*itPaquet)->getModel().size() >= 4)
		{
			if ((*itPaquet)->getModel().substr(0, 4) != "MTB_" && (*itPaquet)->getModel().substr(0, 4) != "INF_" && (*itPaquet)->getModel().substr(0, 4) != "CTR_")
			{

				switch ((*itPaquet)->getTipus()) {
				case TipusBicicleta::CARRETERA:
					tipus = "CTR_";
					break;
				case TipusBicicleta::INFANTIL:
					tipus = "INF_";
					break;
				case TipusBicicleta::MTB:
					tipus = "MTB_";
					break;
				}
				tipus_model = tipus + (*itPaquet)->getModel();
			}
		}
		else
		{
			switch ((*itPaquet)->getTipus()) {
			case TipusBicicleta::CARRETERA:
				tipus = "CTR_";
				break;
			case TipusBicicleta::INFANTIL:
				tipus = "INF_";
				break;
			case TipusBicicleta::MTB:
				tipus = "MTB_";
				break;
			}
			tipus_model = tipus + (*itPaquet)->getModel();
		}

		//(*itPaquet)->getTipus()
		(*itPaquet)->setCodiRus(Empresa::generaCodiRus((*itPaquet)->getModel()));
		Empresa::afegeixSeguiment((*itPaquet));
		Empresa::actualitzaEstat((*itPaquet)->getCodiRus(), EstatBicicleta::EN_MAGATZEM, this);

		bool found = false;
		auto itStock = m_stock.begin();
		while ((itStock != m_stock.end()) && (found == false))
		{
			if ((tipus_model) == itStock->first)
				found = true;
			else
				itStock++;
		}
		if (found == true)
		{
			//s'insereix la bicicleta a la secció de l'stock corresponent
			itStock->second.push((*itPaquet));
		}
		else
		{
			//s'afegeix una secció al stock i s'hi afegeix la bicicleta
			itStock = m_stock.insert(itStock, { tipus_model,priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>() });
			itStock->second.push((*itPaquet));
		}
	}
}

float Magatzem::procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual)
{
	if ((c.getTotalBicicletes() == paquet.size()) && (dataActual <= c.getDataEntregaPrevista()))
		return c.getCostTotal();
	else
		return c.getCostTotal() * m_taxaEndarreriment;
}

bool Magatzem::rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual)
{
	
	float costCorretgit = procesQA(c, paquet, dataActual);
	bool paquetComplet = costCorretgit == c.getCostTotal();
	enmagatzemarComanda(paquet, dataActual);
	generaFactura(paquetComplet, costCorretgit, c);
	return paquetComplet;
}

void Magatzem::generaFactura(bool paquetComplet, float costCorregit, Comanda& c)
{

	ofstream fitxer;
	fitxer.open("factura.txt", std::ofstream::out | std::ofstream::trunc);

	if (fitxer.is_open())
	{
		fitxer << "Resum comanda." << endl;
		fitxer << "Dades Entitat responsable:" << endl;
		fitxer << "Nom: " << m_nom << endl;
		fitxer << "Codi identificatiu: " << m_codi << endl;
		fitxer << "Articles." << endl;
		if (paquetComplet)
		{
			vector<lineaComanda> llistaComanda = c.getLlistaComanda();
			for (auto it = llistaComanda.begin(); it != llistaComanda.end(); it++)
			{
				/*
				string tipus;
				string tipus_model = it->m_model;
				if (it->m_model.size() >= 4)
				{
					if (it->m_model.substr(0, 4) != "MTB_" && it->m_model.substr(0, 4) != "INF_" && it->m_model.substr(0, 4) != "CTR_")
					{
							
						switch (it->tipus) {
						case TipusBicicleta::CARRETERA:
							tipus = "CTR_";
							break;
						case TipusBicicleta::INFANTIL:
							tipus = "INF_";
							break;
						case TipusBicicleta::MTB:
							tipus = "MTB_";
							break;
						}
						tipus_model = tipus + it->m_model;
					}
				}
				else
				{
					switch (it->tipus) {
					case TipusBicicleta::CARRETERA:
						tipus = "CTR_";
						break;
					case TipusBicicleta::INFANTIL:
						tipus = "INF_";
						break;
					case TipusBicicleta::MTB:
						tipus = "MTB_";
						break;
					}
					tipus_model = tipus + it->m_model;
				}*/
				fitxer << it->m_model << " * " << it->m_quantitat << endl << endl;
			}
		}
		else
		{
			fitxer << "El paquet no pasa els test de qualitat." << endl;
			fitxer << "Es redueix el cost del paquet en un 1.1" << endl;
		}
		fitxer << "Preu final: " << costCorregit << endl;
		fitxer.close();
	}
}

void Magatzem::mostraCataleg()
{
	for (auto it = m_stock.begin(); it != m_stock.end(); it++)
	{
		cout << "Model: " << it->first << " Quantitat: " << it->second.size() << endl;
	}
}

Bicicleta* Magatzem::agafaBicicletaAntiga(const string& cs)
{
	bool found = false;
	auto itStock = m_stock.begin();
	while ((itStock != m_stock.end()) && (found == false))
	{
		if (cs == itStock->first)
			found = true;
		else
			itStock++;
	}
	if (found)
	{
		if (itStock->second.size() == 0)
			return NULL;
		Bicicleta* bici = itStock->second.top();
		itStock->second.pop();
		return bici;
	}
	else
		return NULL;
}