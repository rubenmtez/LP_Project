#include <string>

#include "Botiga.h"
#include "Comanda.h"
#include "Magatzem.h"
#include "Proveidor.h"
#include "Entitat.h"
#include "Graf.h"

/**
 *
* La clase empresa aglutina la inforamcion para gestionar la comunicacion del almacen con el proveedor, asi como las tiendas.
* La empresa se define por un conjunto de tiendas, un almacen y un proveedor.
* La empresa realizar� pedidos al provedor y recibira una notificacion indicando si el pedido ha llegado correctamente a almacen.
*
**/

enum class EstatBicicleta {
	EN_MAGATZEM,
	EN_BOTIGA,
	VENUDA,
	RETORNADA
};

struct DadesSeguiment {
	Bicicleta* m_bicicleta;
	vector<pair<EstatBicicleta, Entitat*>> m_historic;
	DadesSeguiment() {
		m_bicicleta = nullptr;
		m_historic = vector<pair<EstatBicicleta, Entitat*>>();
	}
};

static int m_num = 0;
static map<string, DadesSeguiment> m_taulaSeguiment = map<string, DadesSeguiment>();

class Empresa
{
public:
	/*
	Empresa(string name, int numBotigues, Magatzem& magatzemPrincipal, Proveidor& p);
	string getName() const;
	Magatzem& getMagatzem();
	vector<Botiga*>& getBotigues();
	void setProveidor(Proveidor& proveidor);
	Proveidor& getProveidor();
	void afegeixBotiga(Botiga* b);

	bool realitzaComanda(Comanda& c, Proveidor& p);
	*/

	Empresa() {}
	Empresa(string name, int numBotigues, Magatzem* magatzemPrincipal, Proveidor& p);
	Empresa(string name, vector<Botiga*> botigues, vector<Aresta> conexionsBotigues, Magatzem* magatzemPrincipal, Proveidor& p);
	string getName() const { return m_name; }
	Magatzem* getMagatzem() { return m_magatzem; }
	vector<Botiga*>& getBotigues() { return m_botigues; }
	void setProveidor(Proveidor& proveidor) { this->m_proveidor = proveidor; }
	Proveidor& getProveidor() { return m_proveidor; }
	void afegeixBotiga(Botiga* b) { this->m_botigues.emplace_back(b); }
	static int getSeguentCodiRus();

	bool realitzaComanda(Comanda& c, Proveidor& p);
	string static generaCodiRus(const string& model);

	bool realitzaComanda(Comanda& c);
	static bool afegeixSeguiment(Bicicleta* bicicleta);
	static bool actualitzaEstat(const string& codiRus, EstatBicicleta nouEstat, Entitat* novaEntitat);
	static bool comprobaEstatCodi(string codiRus, EstatBicicleta objectiu);

private:
	string m_name;
	Magatzem* m_magatzem;
	vector<Botiga*> m_botigues;
	Proveidor m_proveidor;
};