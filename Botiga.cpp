#include "Botiga.h"
#include "Empresa.h"

bool Botiga::solicitaComanda(Comanda c, Magatzem& m)             //it: Lista de comandas   it2: Stock magatzem(todo lo que hay), busca si hay suficientes bicis del tipo que quieres
{                                                                //it3: Recorre el stock de la botiga para saber si hay un container del modelo, si no lo hay lo crea

	if (m_magatzem == nullptr)
		return false;

	bool suficients_trobats = true;
	vector<lineaComanda> llistaComanda = c.getLlistaComanda();
	for (auto it = llistaComanda.begin(); it != llistaComanda.end(); it++)
	{
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
		}



		map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> stockMagatzem = m_magatzem->getStock();
		auto it2 = stockMagatzem.begin();
		bool magatzemtrobat = false;
		int quantitatTrobada = 0;
		while ((it2 != stockMagatzem.end()) && (magatzemtrobat == false))
		{
			if (tipus_model == it2->first)
			{
				magatzemtrobat = true;
				if (it->m_quantitat <= it2->second.size())
					quantitatTrobada = it->m_quantitat;
				else
					quantitatTrobada = it2->second.size();
			}
			else
			{
				it2++;
			}
		}

		if (magatzemtrobat)
		{
			if (quantitatTrobada != it->m_quantitat)
				suficients_trobats = false;

			bool botigatrobada = false;
			auto it3 = m_stockBotiga.begin();

			while ((it3 != m_stockBotiga.end()) && (botigatrobada == false))
			{
				if (tipus_model == it3->first)
					botigatrobada = true;
				else
					it3++;
			}
			if (!botigatrobada)
			{
				it3 = m_stockBotiga.insert(it3, { tipus_model,priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>() });
			}
			for (int i = 0; i < quantitatTrobada; i++)
			{
				Bicicleta* bici = m.agafaBicicletaAntiga(tipus_model);
				it3->second.push(bici);
				Empresa::actualitzaEstat(bici->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
			}

		}
		else
		{
			suficients_trobats = false;
		}

	}

	return suficients_trobats;

}


bool Botiga::solicitaComanda(Comanda& c)
{
	if (m_magatzem == nullptr)
		return false;

	bool suficients_trobats = true;
	vector<lineaComanda> llistaComanda = c.getLlistaComanda();
	for (auto it = llistaComanda.begin(); it != llistaComanda.end(); it++)
	{
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
		}



		map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> stockMagatzem = m_magatzem->getStock();
		auto it2 = stockMagatzem.begin();
		bool magatzemtrobat = false;
		int quantitatTrobada  = 0;
		while ((it2 != stockMagatzem.end()) && (magatzemtrobat == false))
		{
			if (tipus_model == it2->first)
			{
				magatzemtrobat = true;
				if (it->m_quantitat <= it2->second.size())
					quantitatTrobada = it->m_quantitat;
				else
					quantitatTrobada = it2->second.size();
			}
			else
			{
				it2++;
			}
		}

		if (magatzemtrobat)
		{
			if (quantitatTrobada != it->m_quantitat)
				suficients_trobats = false;

			bool botigatrobada = false;
			auto it3 = m_stockBotiga.begin();

			while ((it3 != m_stockBotiga.end()) && (botigatrobada == false))
			{
				if (tipus_model == it3->first)
					botigatrobada = true;
				else
					it3++;
			}
			if (!botigatrobada)
			{
				it3 = m_stockBotiga.insert(it3, { tipus_model,priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>() });
			}
			for (int i = 0; i < quantitatTrobada; i++)
			{
				Bicicleta* bici = m_magatzem->agafaBicicletaAntiga(tipus_model);
				it3->second.push(bici);
				Empresa::actualitzaEstat(bici->getCodiRus(), EstatBicicleta::EN_BOTIGA, this);
			}

		}
		else
		{
			suficients_trobats = false;
		}

	}

	return suficients_trobats;

}


void Botiga::mostraCataleg(bool desaEnDisc)
{
	for (auto it = m_stockBotiga.begin(); it != m_stockBotiga.end(); it++)
	{
		cout << "Model: " << it->first << " Quantitat: " << it->second.size() << endl;
	}
}

int Botiga::calculaStockTotal()
{
	int stockTotal = 0;
	for (auto it = m_stockBotiga.begin(); it != m_stockBotiga.end(); it++)
	{
		stockTotal += it->second.size();
	}

	return stockTotal;
}

bool Botiga::solicitaBicicletaAMagatzem(const string& model, Bicicleta*& bicicleta)
{
	bicicleta = m_magatzem->agafaBicicletaAntiga(model);
	if (bicicleta == NULL)
	{
		bicicleta = nullptr;
		return false;
	}
	else
		return true;
}

bool Botiga::procesa_venda(const string& model, Bicicleta*& bicicleta)
{
	if (comprobaBicicletaEnStock(model, bicicleta))
		return true;
	if (ComprobaStockEnVeines(model, bicicleta))
		return true;
	if (solicitaBicicletaAMagatzem(model, bicicleta))
		return true;
	return false;
}

bool Botiga::comprobaBicicletaEnStock(const string& model, Bicicleta*& bicicleta)
{
	bool found = false;
	auto itStock = m_stockBotiga.begin();
	while ((itStock != m_stockBotiga.end()) && (found == false))
	{
		if (model == itStock->first)
			found = true;
		else
			itStock++;
	}
	if (found)
	{
		bicicleta = itStock->second.top();
		itStock->second.pop();
	}
	return found;
}

bool Botiga::ComprobaStockEnVeines(const string& model, Bicicleta*& bicicleta)
{
	bool seHaDeQuitarPrefijo = true;
	if (model.size() >= 4)
	{
		if (model.substr(0, 4) == "MTB_" || model.substr(0, 4) == "INF_" || model.substr(0, 4) == "CTR_")
		{
			seHaDeQuitarPrefijo = false;
		}
	}

	for (int i = 0; i < m_veines.size(); i++)
	{
		bool found = false;
		auto itStock = m_veines[i]->m_stockBotiga.begin();
		while ((itStock != m_veines[i]->m_stockBotiga.end()) && (found == false))
		{
			string tipus = itStock->first;
			
			if(seHaDeQuitarPrefijo)
				tipus = tipus.substr(4, tipus.size());
			
			if (model == tipus)
				found = true;
			else
				itStock++;
		}
		if (found)
		{
			bicicleta = itStock->second.top();
			itStock->second.pop();
			return true;
		}
		
	}
	return false;
}