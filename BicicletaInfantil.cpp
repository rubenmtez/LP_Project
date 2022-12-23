#include "BicicletaInfantil.h"

BicicletaInfantil::BicicletaInfantil(
	const string& model,
	const string descripcio,
	const int& temporada,
	const Talla& talla,
	const Quadre& quadre,
	const Roda& roda,
	const Fre& fre,
	TipusBicicleta tipus,
	const bool& plegable)
{
	m_model = model;
	m_descripcioModel = descripcio;
	m_temporada = temporada;
	m_talla = talla;

	/*
	o Cuadro (aluminio)
	o Freno (RIM)
	o Rueda (14 '', 20 '')
	*/

	if (quadre == Quadre::ALUMINI)
		m_quadre = quadre;
	else
		m_quadre = Quadre::ALUMINI;

	if (roda == Roda::RODA_14 || roda == Roda::RODA_20)
		m_roda = roda;
	else
		m_roda = Roda::RODA_14;

	if (fre == Fre::RIM)
		m_fre = fre;
	else
		m_fre = Fre::RIM;

	m_tipus = TipusBicicleta::INFANTIL;

	m_plegable = plegable;
	m_preu = static_cast<std::underlying_type<TipusBicicleta>::type>(TipusBicicleta::INFANTIL);
}

BicicletaInfantil::~BicicletaInfantil()
{
	m_model = "";
	m_descripcioModel = "";
	m_temporada = 0;
	m_talla = Talla::L;
	m_quadre = Quadre::ALUMINI;
	m_roda = Roda::RODA_14;
	m_fre = Fre::RIM;
	m_tipus = TipusBicicleta::INFANTIL;
	m_plegable = false;
	m_preu = static_cast<std::underlying_type<TipusBicicleta>::type>(TipusBicicleta::INFANTIL);
}

ostream& BicicletaInfantil::format(ostream& os) const
{
	return os;
}