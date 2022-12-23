#include "Proveidor.h"
#include "utils.h"
#include "Data.h"
#include "BicicletaInfantil.h"

Proveidor::Proveidor() : m_codiProveidor(0) {}

Data Proveidor::generaDataEnviament(Data dataprevista, int diesmaxim)
{
	int difDies = 1 + (rand() % (diesmaxim - 1));
	bool signe = randomBool();
	if (!signe)
		return (dataprevista + difDies);
	else
		return dataprevista - difDies;
}

bool Proveidor::procesaComanda(Comanda c, Magatzem& m)
{
	vector<Bicicleta*> paquet;
	vector<lineaComanda> llistaComanda = c.getLlistaComanda();
	for (auto it = llistaComanda.begin(); it != llistaComanda.end(); it++)
	{
		for (int i = 0; i < it->m_quantitat; i++)
		{
			if(it->tipus == TipusBicicleta::CARRETERA)
				paquet.push_back(new BicicletaCarretera(it->m_model, it->m_model, rand(), randomTalla(), randomQuadre(), randomRoda(), randomFre(), TipusBicicleta::CARRETERA, randomModalitatC(), randomBool()));
			else if (it->tipus == TipusBicicleta::INFANTIL)
				paquet.push_back(new BicicletaInfantil(it->m_model, it->m_model, rand(), randomTalla(), randomQuadre(), randomRoda(), randomFre(), TipusBicicleta::INFANTIL, randomBool()));
			else
				paquet.push_back(new BicicletaMTB(it->m_model, it->m_model, rand(), randomTalla(), randomQuadre(), randomRoda(), randomFre(), TipusBicicleta::MTB, randomCategoria(), randomModalitat(), randomBool()));
		}
	}
	return m.rebreComanda(c, paquet, generaDataEnviament(c.getDataEntregaPrevista(), 4));
	
}