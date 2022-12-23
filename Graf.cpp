#include "Graf.h"

Graf::Graf(vector<Botiga*> llistaVertexs, vector<Aresta> llistaArestes)
{
	m_nodes.resize(llistaVertexs.size());
	for (int i = 0; i < llistaVertexs.size(); i++)
	{
		m_nodes[i] = new Node(llistaVertexs[i]);
	}

	m_matriuAdj.resize(m_nodes.size());
	for (int i = 0; i < m_nodes.size(); i++)
	{
		m_matriuAdj[i].resize(m_nodes.size(), ARESTA_NULA);
	}

	for (int i = 0; i < llistaArestes.size(); i++)
	{
		m_matriuAdj[llistaArestes[i].inici][llistaArestes[i].desti] = llistaArestes[i].pes;
		m_matriuAdj[llistaArestes[i].desti][llistaArestes[i].inici] = llistaArestes[i].pes;
	}
}

vector<Node*> Graf::getVertexs() const
{
	return m_nodes;
}

vector<vector<int>> Graf::getArestes() const
{
	return m_matriuAdj;
}

vector<Botiga*> Graf::getBotiguesOrdenades(Node* nodeInici)
{
	vector<Node*> camiNodes = dijkstra(nodeInici);
	vector<Botiga*> res;
	res.resize(camiNodes.size());
	for (int i = 0; i < camiNodes.size(); i++)
	{
		res[i] = camiNodes[i]->botiga;
	}

	return res;
}

Graf& Graf::operator=(Graf g)
{
	m_nodes.resize(g.m_nodes.size());
	for (int i = 0; i < g.m_nodes.size(); i++)
	{
		m_nodes[i] = new Node(new Botiga((*g.m_nodes[i]->botiga)));
	}

	m_matriuAdj = g.m_matriuAdj;
	
	return (*this);
}

int Graf::getPes(Node* inici, Node* desti)
{
	return m_matriuAdj[getIndex(inici)][getIndex(inici)];
}

int Graf::getIndex(Node* vertex)
{
	for (int i = 0; i < m_nodes.size(); i++)
	{
		//if((*m_nodes[i]) == (*vertex))
		if (m_nodes[i]->botiga == vertex->botiga)
			return i;
	}
	return -1;
}

Node* Graf::distanciaMinima()
{
	int min = INT_MAX;
	int minIndex = -1;

	for (int i = 0; i < m_nodes.size(); i++)
	{
		if ((m_nodes[i]->distanciaMinima <= min) && (!m_nodes[i]->visitat))
		{
			min = m_nodes[i]->distanciaMinima;
			minIndex = i;
		}
	}
	if (minIndex < 0)
		return nullptr;
	else
		return m_nodes[minIndex];
}

vector<Node*> Graf::dijkstra(Node* nodeInici)
{

	for (int i = 0; i < m_nodes.size(); i++)
	{
		m_nodes[i]->distanciaMinima = INT_MAX;
		m_nodes[i]->visitat = false;
	}

	int node = getIndex(nodeInici);
	int numNodes = m_nodes.size();

	m_nodes[node]->distanciaMinima = 0;

	while (node != -1)
	{
		m_nodes[node]->visitat = true;

		for (int i = 0; i < numNodes; i++)
		{
			int num = m_matriuAdj[node][i];
			if (num == -1)
				num = 0;
			if ((num != 0) && ((num + m_nodes[node]->distanciaMinima) <= m_nodes[i]->distanciaMinima) && (!m_nodes[i]->visitat))
			{
				m_nodes[i]->distanciaMinima = num + m_nodes[node]->distanciaMinima;
			}
		}
		Node* tmp = distanciaMinima();
		if (tmp == nullptr)
			node = -1;
		else
			node = getIndex(tmp);
	}

	vector<Node*> res;
	for (int i = 1; i < m_nodes.size(); i++)
	{
		int indiceMinDist = getIndex(nodeInici);
		int min = INT_MAX;
		for (int j = 0; j < m_nodes.size(); j++)
		{
			if (m_nodes[j]->distanciaMinima < min && m_nodes[j]->distanciaMinima > 0 && m_nodes[j]->visitat)
			{
				indiceMinDist = j;
				min = m_nodes[j]->distanciaMinima;
			}
		}
		res.push_back(m_nodes[indiceMinDist]);
		m_nodes[indiceMinDist]->visitat = false;
	}

	return res;
}