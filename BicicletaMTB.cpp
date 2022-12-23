#include "BicicletaMTB.h"

BicicletaMTB::BicicletaMTB(
	const string& model,
	const string descripcio,
	const int& temporada,
	const Talla& talla,
	const Quadre& quadre,
	const Roda& roda,
	const Fre& fre,
	TipusBicicleta tipus,
	const Categoria categoria,
	const Modalitat modalitat,
	const bool electrica)
{
	m_model = model;
	m_descripcioModel = descripcio;
	m_temporada = temporada;
	m_talla = talla;

	/*
	o Cuadro (aluminio, carbono)
	o Freno (DISC)
	o Rueda (26 '', 27'5 '', 29 '')
	*/

	if (quadre == Quadre::ALUMINI || quadre == Quadre::CARBONO)
		m_quadre = quadre;
	else
		m_quadre = Quadre::ALUMINI;

	if (roda == Roda::RODA_26 || roda == Roda::RODA_27 || roda == Roda::RODA_29)
		m_roda = roda;
	else
		m_roda = Roda::RODA_26;

	if (fre == Fre::DISC)
		m_fre = fre;
	else
		m_fre = Fre::DISC;

	m_tipus = TipusBicicleta::MTB;

	m_categoria = categoria;
	m_modalitat = modalitat;
	m_electrica = electrica;
	m_preu = static_cast<std::underlying_type<TipusBicicleta>::type>(TipusBicicleta::MTB);
}

BicicletaMTB::~BicicletaMTB()
{
	m_model = "";
	m_descripcioModel = "";
	m_temporada = 0;
	m_talla = Talla::L;
	m_quadre = Quadre::ALUMINI;
	m_roda = Roda::RODA_26;
	m_fre = Fre::DISC;
	m_tipus = TipusBicicleta::MTB;
	m_categoria = Categoria::RIGIDA;
	m_modalitat = Modalitat::DESCENS;
	m_electrica = false;
	m_preu = static_cast<std::underlying_type<TipusBicicleta>::type>(TipusBicicleta::MTB);
}

ostream& BicicletaMTB::format(ostream& os) const
{
	return os;
}