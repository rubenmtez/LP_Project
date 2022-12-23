#include "Client.h"
#include "Empresa.h"

bool Client::comprarBicicleta(string model, Botiga& b)
{
	Bicicleta* bi;
	bool t = b.procesa_venda(model, bi);

	if (t)
	{
		Empresa::actualitzaEstat(bi->getCodiRus(), EstatBicicleta::VENUDA, this);
		m_bicicletes.push_back(bi);
	}
	return t;
}