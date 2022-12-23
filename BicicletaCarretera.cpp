#include "BicicletaCarretera.h"

BicicletaCarretera::BicicletaCarretera(
	const string& model,
	const string descripcio,
	const int& temporada,
	const Talla& talla,
	const Quadre& quadre,
	const Roda& roda,
	const Fre& fre,
	TipusBicicleta tipus,
	const ModalitatC modalitat,
	const bool electrica)
{
	m_model = model;
	m_descripcioModel = descripcio;
	m_temporada = temporada;
	m_talla = talla;

	/*
	o Cuadro (aluminio, carbono)
	o Freno (DISCO, RIM)
	o Rueda (700)
	*/

	if (quadre == Quadre::ALUMINI || quadre == Quadre::CARBONO)
		m_quadre = quadre;
	else
		m_quadre = Quadre::ALUMINI;

	if (roda == Roda::RODA_700)
		m_roda = roda;
	else
		m_roda = Roda::RODA_700;

	if (fre == Fre::RIM || fre == Fre::DISC)
		m_fre = fre;
	else
		m_fre = Fre::RIM;

	m_tipus = TipusBicicleta::CARRETERA;

	m_modalitatC = modalitat;
	m_electricaC = electrica;
	m_preu = static_cast<std::underlying_type<TipusBicicleta>::type>(TipusBicicleta::CARRETERA);
}

BicicletaCarretera::~BicicletaCarretera()
{
	m_model = "";
	m_descripcioModel = "";
	m_temporada = 0;
	m_talla = Talla::L;
	m_quadre = Quadre::ALUMINI;
	m_roda = Roda::RODA_700;
	m_fre = Fre::RIM;
	m_tipus = TipusBicicleta::CARRETERA;
	m_modalitatC = ModalitatC::AERO;
	m_electricaC = false;
	m_preu = static_cast<std::underlying_type<TipusBicicleta>::type>(TipusBicicleta::CARRETERA);
}

ostream& BicicletaCarretera::format(ostream& os) const
{
	return os;
}