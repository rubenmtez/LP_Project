#include "Comanda.h"

Comanda::Comanda(const Data& entregaPrevista, vector<lineaComanda>& comanda)
{
	m_entregaPrevista = entregaPrevista;
	m_llista_comanda = vector<lineaComanda>();
	m_costTotal = 0;
	m_totalBicicletes = 0;
	for (auto it = comanda.begin(); it != comanda.end(); it++)
	{
		if (it->m_model != "" && it->m_quantitat > 0)
		{
			m_llista_comanda.push_back(*it);
			m_costTotal += (static_cast<std::underlying_type<TipusBicicleta>::type>(it->tipus) * it->m_quantitat);
			m_totalBicicletes += it->m_quantitat;
		}
	}
}