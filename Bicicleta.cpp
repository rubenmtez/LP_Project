#include "Bicicleta.h"

Bicicleta::Bicicleta(const string& model, const string descripcio, const int& temporada, const Talla talla,
	const Quadre quadre, const Roda roda, const Fre fre, TipusBicicleta tipus)
{
	m_model = model;
	m_descripcioModel = descripcio;
	m_temporada = temporada;
	m_talla = talla;
	m_quadre = quadre;
	m_roda = roda;
	m_fre = fre;
	m_tipus = tipus;
}

bool Bicicleta::operator<(const Bicicleta& b1) const
{
	if (m_dataEntradaMagatzem < b1.m_dataEntradaMagatzem)
		return true;
	else
		return false;
}