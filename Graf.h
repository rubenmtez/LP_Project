#pragma once
#include <limits.h>
#include "Botiga.h"
#include <algorithm>


struct Node
{
	bool visitat;
	Botiga* botiga;
	int distanciaMinima;
	Node(Botiga* b) :visitat(false), botiga(b), distanciaMinima(INT_MAX) {}
};

struct Aresta
{
	int inici, desti, pes;
};

class Graf
{
public:
	Graf() {};
	Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes);
	vector<Node*> getVertexs() const;
	vector<vector<int>> getArestes() const;
	vector<Botiga*> getBotiguesOrdenades(Node* nodeInici);
	Graf& operator=(Graf g);

private:
	const int ARESTA_NULA = -1;
	vector<Node*> m_nodes;
	vector<vector<int>> m_matriuAdj;

	int getPes(Node* inici, Node* desti);
	int getIndex(Node* vertex);
	Node* distanciaMinima();
	vector<Node*> dijkstra(Node* nodeInici);

	
};

