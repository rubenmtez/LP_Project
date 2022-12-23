#include <iostream>


#include "BicicletaCarretera.h"
#include "BicicletaInfantil.h"
#include "BicicletaMTB.h"
#include "Empresa.h"
#include "utils.h"
#include <cmath>

#include "Client.h"

using namespace std;

float test_graf_2()
{
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ======================== Tests Graf =========================" << endl;
	cout << "Comment :=>> =============================================================" << endl;

	float grade = 0.f;

	vector<Botiga*> bs = {
		new Botiga("b0", "0"),
		new Botiga("b1", "1"),
		new Botiga("b2", "2"),
		new Botiga("b3", "3"),
		new Botiga("b4", "4"),
	};
	vector<Aresta> aLinea = {
		Aresta{0,1,3},
		Aresta{1,2,1},
		Aresta{2,3,2},
		Aresta{3,4,4},

	};
	Graf lineaG = Graf(bs, aLinea);

	vector< vector<int> > outAresta = {
		{-1, 3, -1, -1, -1},
		{3, -1, 1, -1, -1},
		{-1, 1, -1, 2, -1},
		{-1, -1, 2, -1, 4},
		{-1, -1, -1, 4, -1}
	};

	if (outAresta == lineaG.getArestes())
	{
		grade++;
	}
	else
	{
		cout << "Comment :=>> Error al comparar matrices de adyacencia. La generada y la real no corresponden." << endl;
	}


	vector<Botiga*> orden0 = lineaG.getBotiguesOrdenades(lineaG.getVertexs()[0]);
	vector<Botiga*> sol0 = { bs[1], bs[2], bs[3], bs[4] };
	bool ok0 = orden0 == sol0;
	vector<Botiga*> orden1 = lineaG.getBotiguesOrdenades(lineaG.getVertexs()[1]);
	vector<Botiga*> sol1 = { bs[2], bs[0], bs[3], bs[4] };
	bool ok1 = orden1 == sol1;
	vector<Botiga*> orden2 = lineaG.getBotiguesOrdenades(lineaG.getVertexs()[2]);
	vector<Botiga*> sol2 = { bs[1], bs[3], bs[0], bs[4] };
	bool ok2 = orden2 == sol2;
	vector<Botiga*> orden3 = lineaG.getBotiguesOrdenades(lineaG.getVertexs()[3]);
	vector<Botiga*> sol3 = { bs[2], bs[1], bs[4], bs[0] };
	bool ok3 = orden3 == sol3;
	vector<Botiga*> orden4 = lineaG.getBotiguesOrdenades(lineaG.getVertexs()[4]);
	vector<Botiga*> sol4 = { bs[3], bs[2], bs[1], bs[0] };
	bool ok4 = orden4 == sol4;

	if (ok0 && ok1 && ok2 && ok3 && ok4) {
		grade++;
	}
	else {
		cout << "Comment :=>> Error al calcular el orden de las tiendas vecinas. Se debe ordenar en funcion de la distancia minima calculada con dijkstra" << endl;
	}

	vector<Aresta> aPajarita = {
	Aresta{0,2,2},
	Aresta{1,0,1},
	Aresta{1,2,1},
	Aresta{1,3,1},
	Aresta{1,4,2},
	Aresta{3,4,1}

	};
	Graf pajarita = Graf(bs, aPajarita);
	orden0 = pajarita.getBotiguesOrdenades(pajarita.getVertexs()[0]);
	sol0 = { bs[1], bs[2], bs[3], bs[4] };
	bool ok0P = orden0 == sol0;
	orden1 = pajarita.getBotiguesOrdenades(pajarita.getVertexs()[1]);
	sol1 = { bs[0], bs[2], bs[3], bs[4] };
	bool ok1P = orden1 == sol1;
	orden2 = pajarita.getBotiguesOrdenades(pajarita.getVertexs()[2]);
	sol2 = { bs[1], bs[0], bs[3], bs[4] };
	bool ok2P = orden2 == sol2;
	orden3 = pajarita.getBotiguesOrdenades(pajarita.getVertexs()[3]);
	sol3 = { bs[1], bs[4], bs[0], bs[2] };
	bool ok3P = orden3 == sol3;
	orden4 = pajarita.getBotiguesOrdenades(pajarita.getVertexs()[4]);
	sol4 = { bs[3], bs[1], bs[0], bs[2] };
	bool ok4P = orden4 == sol4;

	if (ok0P && ok1P && ok2P && ok3P && ok4P) {
		grade++;
	}
	else {
		cout << "Comment :=>> Error al calcular el orden de las tiendas vecinas. Se debe ordenar en funcion de la distancia minima calculada con dijkstra" << endl;
	}


	return grade;
}

float test_entitat_2() {
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ====================== Tests Entidad ========================" << endl;
	cout << "Comment :=>> =============================================================" << endl;
	string nom = "nom";
	string codi = "codi";
	string errors = "";
	Entitat* m = nullptr;
	Entitat* b = nullptr;
	Entitat* c = nullptr;
	try
	{
		m = new Magatzem(nom, codi);
	}
	catch (const std::exception&)
	{
		errors = errors + "|Magatzem|";
	}
	try
	{
		b = new Botiga(nom, codi);
	}
	catch (const std::exception&)
	{
		errors = errors + "|Botiga|";
	}
	try
	{
		c = new Client(nom, codi);
	}
	catch (const std::exception&)
	{
		errors = errors + "|Client|";

	}
	if (errors.empty()) {
		if (m->getNom() == nom && b->getNom() == nom && c->getNom() == nom &&
			m->getCodi() == codi && b->getCodi() == codi && c->getCodi() == codi)
		{
			return 1.0f;
		}
	}
	else {
		cout << "Comment :=>> Las clases: " << errors << " no son Entidades." << endl;
	}
	return 0;
}

float test_magatzem_2() {
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ====================== Tests Almacen ========================" << endl;
	cout << "Comment :=>> =============================================================" << endl;
	Magatzem m = Magatzem("uwu", "uwuwu");
	vector<Bicicleta*> bicis;
	for (int i = 0; i < 10; i++) {
		bicis.push_back(new BicicletaInfantil("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, false));
		bicis.push_back(new BicicletaMTB("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, Categoria::DOBLE, Modalitat::DESCENS, false));
		bicis.push_back(new BicicletaCarretera("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, ModalitatC::AERO, false));

	}
	m.enmagatzemarComanda(bicis, Data(10, 10, 15));
	bool error = false;

	for (pair<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> p : m.getStock()) {
		//for(pair<string, priority_queue<Bicicleta*>> p : m.getStock()) {
		while (!p.second.empty()) {
			if (!Empresa::comprobaEstatCodi(p.second.top()->getCodiRus(), EstatBicicleta::EN_MAGATZEM)) {
				error = true;
			}
			p.second.pop();
		}
	}
	if (error) {
		cout << "Comment :=>> Bicicletas no han actualizado el estado correctamente a EN_MAGATZEM." << endl;
	}
	else {
		return 1.0f;
	}
	return 0;
}

float test_client_2() {
	float grade = 0.f;
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ====================== Tests Cliente ========================" << endl;
	cout << "Comment :=>> =============================================================" << endl;

	Client c = Client("GSA", "1234");
	bool defaultOk = c.getBicicletes().empty() && c.getNom() == "GSA" && c.getCodi() == "1234";
	if (defaultOk) {
		grade++;
	}
	else {
		cout << "Comment :=>> Errores en el constructor de Client. Parametros inicializados incorrectamente" << endl;
	}

	Botiga b = Botiga("B0", "0");
	Botiga* b2 = new Botiga("B2", "2");
	Magatzem* m = new Magatzem();
	b.setMatgatzem(m);
	b2->setMatgatzem(m);
	Bicicleta* bici = new BicicletaInfantil("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, false);
	bici->setCodiRus("test_client");
	Empresa::afegeixSeguiment(bici);
	Empresa::actualitzaEstat("test_client", EstatBicicleta::EN_MAGATZEM, &b);

	vector<Bicicleta*> bicisCompra;
	for (int i = 0; i < 10; i++) {
		bicisCompra.push_back(new BicicletaInfantil("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, false));
		bicisCompra.push_back(new BicicletaMTB("MTB_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, Categoria::DOBLE, Modalitat::DESCENS, false));
		bicisCompra.push_back(new BicicletaCarretera("CTR_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, ModalitatC::AERO, false));

	}
	m->enmagatzemarComanda(bicisCompra, Data(10, 10, 15));
	vector<lineaComanda> l1 = { {TipusBicicleta::INFANTIL, 10, "INF_A"} };
	Comanda c1 = Comanda(Data(10, 10, 10), l1);
	b.solicitaComanda(c1);
	vector<lineaComanda> l2 = { {TipusBicicleta::CARRETERA, 10, "CTR_A"} };
	Comanda c2 = Comanda(Data(10, 10, 10), l2);
	b2->solicitaComanda(c2);
	vector<Botiga*> veines = { b2 };
	b.setveinesOrdenades(veines);


	bool noExiste = c.comprarBicicleta("codiInventat", b);
	if (noExiste)
	{
		cout << "Comment :=>> Error al comprar una bicicleta de un modelo inexistente" << endl;
	}
	bool soloAlmacen = c.comprarBicicleta("MTB_A", b);
	if (!soloAlmacen)
	{
		cout << "Comment :=>> Error al comprar una bicicleta con stock solo en almacen" << endl;
	}
	bool tiendaVecina = c.comprarBicicleta("CTR_A", b);
	if (!tiendaVecina)
	{
		cout << "Comment :=>> Error al comprar una bicicleta con stock solo en tiendas vecinas" << endl;
	}
	bool tienda = c.comprarBicicleta("INF_A", b);
	if (!tienda)
	{
		cout << "Comment :=>> Error al comprar una bicicleta con stock en tienda objetivo" << endl;
	}


	if (tienda && soloAlmacen && tiendaVecina && !noExiste) {
		grade++;
	}
	return grade;
}


float test_empresa_2() {
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ====================== Tests Empresa =======================" << endl;
	cout << "Comment :=>> =============================================================" << endl;
	float grade = 0.f;
	vector<Botiga*> bs = {
		new Botiga("B0", "000"),
		new Botiga("B1", "001"),
		new Botiga("B2", "002")
	};
	vector<Aresta> as = {
		{0, 1, 1},
		{1, 2, 1}
	};
	Proveidor p = Proveidor(1);
	try
	{
		Empresa e = Empresa("qwerty", bs, as, new Magatzem("M", "mmm"), p);

	}
	catch (const std::exception&)
	{
		cout << "Comment :=>> Error en el constructor de Empresa: se debe de generar el grafo y precalcular las rutas de consulta optimas." << endl;
	}

	Bicicleta* b = new BicicletaInfantil("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, false);
	bool noCodi = Empresa::afegeixSeguiment(b);
	b->setCodiRus("test_empresa_2");
	bool ok = Empresa::afegeixSeguiment(b);
	bool yaCodi = Empresa::afegeixSeguiment(b);
	bool nulCodi = Empresa::afegeixSeguiment(nullptr);

	if (noCodi) {
		cout << "Comment :=>> Error al intentar anadir seguimiento de un codigo inexistente." << endl;
	}
	if (!ok) {
		cout << "Comment :=>> Error al anadir el seguimiento en una bicicleta." << endl;
	}
	if (yaCodi) {
		cout << "Comment :=>> Error al intentar anadir seguimiento de un codigo ya registrado." << endl;
	}
	if (nulCodi) {
		cout << "Comment :=>> Error al intentar anadir seguimiento de una bicicleta nula." << endl;
	}
	if (ok && !noCodi && !yaCodi && !nulCodi) {
		grade++;
	}

	DadesSeguiment d = DadesSeguiment();
	bool dadesOk = d.m_bicicleta == nullptr && d.m_historic.empty();
	d.m_bicicleta = b;
	d.m_historic.emplace_back(EstatBicicleta::VENUDA, new Magatzem());
	bool dadesOkChanges = d.m_bicicleta == b && d.m_historic.size() == 1;

	if (dadesOk && dadesOkChanges) {
		grade++;
	}
	else {
		cout << "Comment :=>> Error al crear la estructura DadesSeguiment." << endl;
	}

	Bicicleta* b2 = new BicicletaInfantil("INF_A", ".", 2020, Talla::L, Quadre::ALUMINI, Roda::RODA_14, Fre::DISC, TipusBicicleta::INFANTIL, false);
	b2->setCodiRus("test_empresa_2_actualitza");
	Empresa::afegeixSeguiment(b2);
	bool codiNoValid = Empresa::actualitzaEstat("codiInvalid", EstatBicicleta::EN_BOTIGA, new Magatzem());
	bool eNula = Empresa::actualitzaEstat("test_empresa_2_actualitza", EstatBicicleta::EN_MAGATZEM, nullptr);
	bool okActualiza = Empresa::actualitzaEstat("test_empresa_2_actualitza", EstatBicicleta::EN_MAGATZEM, new Magatzem());

	if (codiNoValid) {
		cout << "Comment :=>> Error al intentar actualizar estado de un codigo inexistente." << endl;
	}
	if (eNula) {
		cout << "Comment :=>> Error al intentar actualizar estado con una Entidad nula." << endl;
	}
	if (!okActualiza) {
		cout << "Comment :=>> Error al intentar actualizar estado de un codigo ruso" << endl;
	}
	if (okActualiza && !eNula && !codiNoValid) {
		grade++;
	}

	bool okComproba = Empresa::comprobaEstatCodi("test_empresa_2_actualitza", EstatBicicleta::EN_MAGATZEM);
	bool noCodiComproba = Empresa::comprobaEstatCodi("codiInvalid", EstatBicicleta::EN_MAGATZEM);
	bool noEntitat = Empresa::comprobaEstatCodi("test_empresa_2_actualitza", EstatBicicleta::EN_BOTIGA);

	if (noCodiComproba) {
		cout << "Comment :=>> Error al intentar comprobar un estado de un codigo inexistente." << endl;
	}
	if (noEntitat) {
		cout << "Comment :=>> Error al intentar comprobar un estado por el que no ha pasado un codigo ruso." << endl;
	}
	if (!okComproba) {
		cout << "Comment :=>> Error al comprobar el estado de un codigo ruso valido" << endl;
	}
	if (okComproba && !noEntitat && !noCodiComproba) {
		grade++;
	}

	return grade;

}

float test_botiga2() {
	float grade = 0.f;
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ====================== Tests Botiga ========================" << endl;
	cout << "Comment :=>> =============================================================" << endl;

	Botiga* b = new Botiga("b0", "123");
	Magatzem* m = new Magatzem("m", "mmm");
	vector<lineaComanda> vl = { {TipusBicicleta::INFANTIL, 10, "INF_A"},{TipusBicicleta::INFANTIL, 10, "INF_B"} };
	Comanda c = Comanda(Data(10, 10, 10), vl);
	vector<Botiga*> veinesBuida = { new Botiga("b1", "456") };
	vector<Bicicleta*> bicis;
	for (int i = 0; i < 15; i++) {
		bicis.push_back(new BicicletaInfantil("INF_A", ".", 2, Talla::M, Quadre::ALUMINI, Roda::RODA_14, Fre::RIM, TipusBicicleta::CARRETERA, false));
		bicis.push_back(new BicicletaInfantil("INF_B", ".", 2, Talla::M, Quadre::ALUMINI, Roda::RODA_14, Fre::RIM, TipusBicicleta::CARRETERA, false));
		bicis.push_back(new BicicletaMTB("MTB_A", ".", 20, Talla::M, Quadre::ALUMINI, Roda::RODA_14, Fre::RIM, TipusBicicleta::CARRETERA, Categoria::DOBLE, Modalitat::DESCENS, false));
	}

	bool newAtributesDef = b->getMagatzem() == nullptr && b->getBotiguesProperes().empty();
	try
	{
		b->solicitaComanda(c);
		grade += 0.1f;
	}
	catch (const std::exception&)
	{
		cout << "Comment :=>> Error al solicitar comanda al Magatzem por defecto. Magatzem nulo" << endl;
	}
	b->setMatgatzem(m);
	m->enmagatzemarComanda(bicis, Data(10, 10, 1000));
	bool ok = b->solicitaComanda(c);
	bool okM = m->getStock()["INF_A"].size() == 5;
	bool incompleta = b->solicitaComanda(c);
	bool incompletaM = m->getStock()["INF_A"].empty();

	if (newAtributesDef) {
		grade++;
	}
	else {
		cout << "Comment :=>> atributos no inicializados correctamente en el constructor." << endl;
	}

	if (ok && okM && !incompleta && incompletaM) {
		grade += 0.9f;
	}
	else {
		cout << "Comment :=>> Error realizar la comanda en el almacen por defecto de la tienda" << endl;
	}

	bool error = false;
	for (pair<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> p : b->getStockBotiga()) {
		while (!p.second.empty()) {
			if (!Empresa::comprobaEstatCodi(p.second.top()->getCodiRus(), EstatBicicleta::EN_BOTIGA)) {
				error = true;
			}
			p.second.pop();
		}
	}
	if (!error) {
		grade++;
	}
	else {
		cout << "Comment :=>> Bicicletas no han actualizado el estado correctamente a EN_BOTIGA." << endl;
	}

	Bicicleta* bici = nullptr;
	bool noCodi = b->solicitaBicicletaAMagatzem("123", bici);
	bool errorNoCodi = bici != nullptr;
	bool noBici = b->solicitaBicicletaAMagatzem("INF_A", bici);
	bool errorBici = bici != nullptr;
	bool okSolicita = b->solicitaBicicletaAMagatzem("MTB_A", bici);
	bool errorOkBici = bici == nullptr;

	if (noCodi || errorNoCodi) {
		cout << "Comment :=>> Error en la solicitud de una bicicleta al almacen de modelo invalido" << endl;
	}
	if (noBici || errorBici) {
		cout << "Comment :=>> Error en la solicitud de una bicicleta al almacen de una bicicleta sin stock" << endl;
	}
	if (!okSolicita || errorOkBici) {
		cout << "Comment :=>> Error en la solicitud de una bicicleta al almacen de modelo valido. Se debe retornar la bicicleta por referencia" << endl;
	}

	if (!noCodi && !errorNoCodi && !noBici && !errorBici && okSolicita && !errorOkBici) {
		grade++;
	}

	bici = nullptr;
	bool noModel = b->comprobaBicicletaEnStock("123", bici);
	bool errorNoModel = bici != nullptr;
	bool siModel = b->comprobaBicicletaEnStock("INF_A", bici);
	bool errorSiModel = bici == nullptr;

	if (noModel || errorNoModel) {
		cout << "Comment :=>> Error al comprobar un modelo inexistente en el stock de la tienda" << endl;
	}
	if (!siModel || errorSiModel) {
		cout << "Comment :=>> Error al comprobar un modelo valido en el stock de la tienda. Se debe retornar la bicicleta por referencia" << endl;
	}

	if (!noModel && !errorNoModel && siModel && !errorSiModel) {
		grade++;
	}


	Botiga* b2 = new Botiga("b2", "789");
	vector<lineaComanda> vl2 = { {TipusBicicleta::INFANTIL, 10, "modelExistent"} };
	Comanda c2 = Comanda(Data(10, 10, 10), vl2);
	vector<Bicicleta*> bicis2;
	for (int i = 0; i < 15; i++) {
		bicis2.push_back(new BicicletaInfantil("modelExistent", ".", 2, Talla::M, Quadre::ALUMINI, Roda::RODA_14, Fre::RIM, TipusBicicleta::CARRETERA, false));
	}
	bici = nullptr;
	bool noModelComproba = b->ComprobaStockEnVeines("modelInexistent", bici);
	bool errorNoModelComproba = bici != nullptr;

	b->setveinesOrdenades(veinesBuida);
	bool veinaNo = b->ComprobaStockEnVeines("modelNoVeines", bici);
	bool errorVeninaNo = bici != nullptr;

	b2->setMatgatzem(m);
	m->enmagatzemarComanda(bicis2, Data(10, 10, 1000));
	b2->solicitaComanda(c2);
	vector<Botiga*> veines = { new Botiga("b1", "456") , b2 };
	b->setveinesOrdenades(veines);
	bool veinaSi = b->ComprobaStockEnVeines("modelExistent", bici);
	bool errorVeinaSi = bici == nullptr;

	if (noModelComproba || errorNoModelComproba) {
		cout << "Comment :=>> Error al comprobar el stock en tiendas vecinas de un modelo inexistente" << endl;
	}
	if (veinaNo || errorVeninaNo) {
		cout << "Comment :=>> Error al comprobar el stock de un modelo valido inexistente en todas las tiendas" << endl;
	}
	if (!veinaSi || errorVeinaSi) {
		cout << "Comment :=>> Error al comprobar el stock de un modelo valido existente en alguna de las tiendas vecinas. Se debe devolver por referencia la bicicleta" << endl;
	}

	if (!noModel && !errorNoModel && !veinaNo && !errorVeninaNo && veinaSi && !errorVeinaSi) {
		grade++;
	}
	bici = nullptr;
	bool failModel = b->procesa_venda("123", bici);
	bool errorVendaFail = bici != nullptr;
	bool success = b->procesa_venda("INF_A", bici);
	bool errorVendaSuccess = bici == nullptr;

	if (failModel || errorVendaFail) {
		cout << "Comment :=>> Error al procesar la venda, se debe derivar a otras tiendas y posteriormente al Magatzem." << endl;
	}
	if (!success || errorVendaSuccess) {
		cout << "Comment :=>> Error al procesar una venta de un modelo existente en alguna de las tiendas vecinas. Se debe devolver por referencia la bicicleta" << endl;
	}

	if (!failModel && !errorVendaFail && success && !errorVendaSuccess) {
		grade++;
	}

	return grade;
}

float entrega2()
{
	float grade = 0.f;
	Magatzem* m = new Magatzem("Principal", "0001");
	Proveidor p = Proveidor(101);
	vector<Botiga*> vGraf = vector<Botiga*>();
	vGraf.push_back(new Botiga("B0", "0"));
	vGraf.push_back(new Botiga("B1", "1"));
	vGraf.push_back(new Botiga("B2", "2"));
	vGraf.push_back(new Botiga("B3", "3"));
	vGraf.push_back(new Botiga("B4", "4"));
	vector<Aresta> eGraf = {
		Aresta{0, 1, 3},
		Aresta{0, 2, 1},
		Aresta{0, 3, 2},
		Aresta{1, 2, 2},
		Aresta{1, 4, 1},
		Aresta{3, 4, 3}
	};
	Empresa empresa = Empresa("Bicicletes AEM", vGraf, eGraf, m, p);

	bool error = false;
	if (empresa.getMagatzem() != m)
		error = true;
	for (Botiga* b : empresa.getBotigues())
	{
		if (b->getMagatzem() != m)
			error = true;
		if (b->getBotiguesProperes().size() != empresa.getBotigues().size() - 1)
			error = true;
	}
	if (!error)
		grade++;

	Data d = Data(11, 9, 2020);
	lineaComanda inf_a{ TipusBicicleta::INFANTIL, 50, "A" };
	lineaComanda inf_b{ TipusBicicleta::INFANTIL, 10, "B" };
	lineaComanda mtb_a{ TipusBicicleta::MTB, 50, "A" };
	lineaComanda mtb_b{ TipusBicicleta::MTB, 10, "B" };
	lineaComanda ctr_a{ TipusBicicleta::CARRETERA, 50, "A" };
	lineaComanda ctr_b{ TipusBicicleta::CARRETERA, 10, "B" };

	vector<lineaComanda> v = { inf_a,inf_b,mtb_a,mtb_b,ctr_a,ctr_b };
	Comanda c = Comanda(d, v);

	empresa.realitzaComanda(c);
	auto mStock = m->getStock();
	bool errorM = false;
	int cnt = 0;
	Data tmp;
	for (pair<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> l : mStock)
	{
		while (!l.second.empty())
		{
			cnt++;
			tmp = l.second.top()->getDataEntrada();
			l.second.pop();
			if (!l.second.empty())
				if (l.second.top()->getDataEntrada() < tmp)
					errorM = true;

		}
	}
	if (!errorM && cnt == 180)
	{
		grade++;
	}
	else
	{
		cout << "Comment :=>> Error al enviar el pedido al Magatzem. No ha llegado todo el paquete o esta mal ordenado" << endl;
	}

	vector<pair<TipusBicicleta, int>> comandaBotiga;

	lineaComanda infBotiga{ TipusBicicleta::INFANTIL, 10, "INF_A" };
	lineaComanda mtbBotiga{ TipusBicicleta::MTB, 10, "MTB_A" };
	lineaComanda carBotiga{ TipusBicicleta::CARRETERA, 10, "CTR_A" };

	vector<lineaComanda> vBotiga = { infBotiga, mtbBotiga, carBotiga };

	Comanda cBotiga = Comanda((d + 10), vBotiga);

	//Cada botiga fa la comanda al magatzem de la reposicio inical.
	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> bStock;
	bool errorB = false;
	int cntB;
	Data tmpB;
	for (auto* b : empresa.getBotigues())
	{
		b->solicitaComanda(cBotiga);
		bStock = b->getStockBotiga();
		cntB = 0;
		for (pair<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> l : bStock)
		{
			while (!l.second.empty())
			{
				cntB++;
				tmpB = l.second.top()->getDataEntrada();
				l.second.pop();
				if (!l.second.empty())
					if (l.second.top()->getDataEntrada() < tmpB)
						errorB = true;

			}
		}
		if (!errorB && cntB == 30)
		{
			grade += 1.f / empresa.getBotigues().size();
		}
		else
		{
			cout << "Comment :=>> Error al enviar el pedido a la Botiga. No ha llegado todo el paquete o esta mal ordenado" << endl;
		}
	}


	vector<lineaComanda> vBotiga0 = {
		{ TipusBicicleta::INFANTIL, 10, "INF_B" },
		{TipusBicicleta::MTB, 10, "MTB_B"},
	};
	Comanda cBotiga0 = Comanda((d + 10), vBotiga0);

	empresa.getBotigues()[0]->solicitaComanda(cBotiga0);

	Client client = Client("Cliente", "1234567890");
	Botiga* b0 = empresa.getBotigues()[0];
	Botiga* b1 = empresa.getBotigues()[1];
	Botiga* b2 = empresa.getBotigues()[2];

	bool estat0 = client.comprarBicicleta("INF_A", *b0);
	bool estat1 = client.comprarBicicleta("INF_B", *b1);
	bool estat2 = client.comprarBicicleta("CTR_B", *b1);
	bool estat3 = client.comprarBicicleta("CTR_C", *b1);

	if (estat0 && estat1 && estat2 && !estat3)
	{
		grade++;
	}



	return grade;

}


int main(int argc, char* argv[])
{
	srand(1070);
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> ====================== Tests unitarios ======================" << endl;
	cout << "Comment :=>> =============================================================" << endl;

	float grade = 0;
	float bestGrade = 24;
	cout << endl << endl;
	grade += test_entitat_2(); //1
	grade += test_client_2(); // 2
	grade += test_magatzem_2(); // 1
	grade += test_graf_2(); //3
	grade += test_empresa_2(); // 4
	grade += test_botiga2(); //7

	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>> =================== Tests de integracion ====================" << endl;
	cout << "Comment :=>> =============================================================" << endl;
	cout << "Comment :=>>" << endl;
	grade += entrega2(); // 4

	cout << "Grade :=>> " << grade << "/" << bestGrade << endl;



}