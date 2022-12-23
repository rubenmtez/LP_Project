#pragma once
#include <map>
#include <queue>
#include <string>
#include "Entitat.h"

#include "Comanda.h"


/**
* La clase Magatzem gestiona el estoc de la empresa antes de ser enviado a tiendas.
* En el almacen se pasan controles de calidad para notificar a la empresa del estado en el que llega el pedido.
* El almacen tambien genera la factura final en funcion del estado con el que llega el pedido.
*
**/

class Magatzem : public Entitat
{
public:
	/*
	Magatzem();
	Magatzem(string nom, string codi);
	*/
	Magatzem() { m_stock = map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>(); }
	~Magatzem() {};
	Magatzem(string nom, string codi) : Entitat(nom, codi) { m_stock = map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>>(); };

	void enmagatzemarComanda(vector<Bicicleta*>& paquet, Data dataEntrada);
	float procesQA(Comanda& c, vector<Bicicleta*>& paquet, Data dataActual);
	bool rebreComanda(Comanda& c, vector<Bicicleta*>& paquet, Data dataRecepcioPaquet);
	void generaFactura(bool paquetComplet, float costCorregit, Comanda& c);
	Bicicleta* agafaBicicletaAntiga(const string& model);
	void mostraCataleg();

	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> getStock() const { return m_stock; }; //  <---NUEVO
	//map<string, priority_queue<Bicicleta*>> getStock() const { return m_stock; } // <---VIEJO

private:

	float m_taxaEndarreriment = 1.1f;
	map<string, priority_queue<Bicicleta*, vector<Bicicleta*>, CmpBicicleta>> m_stock;
	//Data data; (?)
};