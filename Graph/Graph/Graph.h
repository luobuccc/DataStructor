#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int DEFAULTVERTICES = 30;
const int maxWeight = 9999;

typedef struct
{
	int vex;
	int lowcost;
} CloseEdge[DEFAULTVERTICES];

template <class T, class E>
struct EdgeSet
{
	int vex1;
	int vex2;
	E weight;
};

template <class T, class E>
class GraphMtx
{
private:
	T* VerticeList;
	E Edge[DEFAULTVERTICES][DEFAULTVERTICES];
	int maxVertices;
	int numVertices = 0;
	int numEdges;
	int direction;
	CloseEdge closeedge;


public:
	int getVerPos(const T& vertex)
	{
		for (int i = 0; i < numVertices; ++i)
		{
			if (vertex == VerticeList[i])
				return i;
		}
		return -1;
	}

	GraphMtx(int size = 30, int d = 0);

	~GraphMtx()
	{
		delete[] VerticeList;
	}

	void CreateGM(int n, int x);
	int minmum() const;
	void Prim(T Vertex);
	void InsertSort(EdgeSet<T, E> V[]);
	void Kruskal();
	int getFirstNeighbor(int v) const;
	int getNextNeighbor(int v, int w) const;
	bool insertVertice(const T& vertex);
	bool deleteVertice(int v);
	bool insertEdge(int v1, int v2, E weight);
	bool deleteEdge(int v1, int v2);
	E getWeight(int v1, int v2) const;
	T getValue(int i) const;
	void print() const;
	void Dijkstra(const int v);
};


template <class T, class E>
GraphMtx<T, E>::GraphMtx(int size, int d): maxVertices(size), numVertices(0), numEdges(0), direction(d)
{
	VerticeList = new T[maxVertices];
	//if(maxVertices>DEFAULTVERTICES)
	//	Edge=
	for (int i = 0; i < maxVertices; ++i)
		for (int j = 0; j < maxVertices; ++j)
		{
			if (i == j)Edge[i][j] = 0;
			else
				Edge[i][j] = maxWeight;
		}
}

template <class T, class E>
void GraphMtx<T, E>::CreateGM(int n, int x)
{
	T e, e1;
	E weight;
	for (int i = 0; i < n; ++i)
	{
		cout << "input " << i + 1 << " vertex: ";
		cin >> e;
		insertVertice(e);
	}

	int i = 1;
	while (i <= x)
	{
		cout << "input two vertidex and weight: ";
		cin >> e >> e1 >> weight;
		int j = getVerPos(e);
		int k = getVerPos(e1);

		if (j == -1 || k == -1) { cout << "Error" << endl; }
		else
		{
			insertEdge(j, k, weight);
			++i;
		}
	}
}

template <class T, class E>
int GraphMtx<T, E>::minmum() const
{
	int i = 0;
	while (i < numVertices && !closeedge[i].lowcost)
	{
		++i;
	}
	int k = i;
	int min = closeedge[i].lowcost;
	for (int j = i + 1; j < numVertices; ++j)
	{
		if (closeedge[j].lowcost > 0 && min > closeedge[j].lowcost)
		{
			min = closeedge[j].lowcost;
			k = j;
		}
	}
	return k;
}

template <class T, class E>
void GraphMtx<T, E>::Prim(T Vertex)
{
	int pos = getVerPos(Vertex);
	if (pos == -1)
	{
		std::cout << "Wrong Vertex" << std::endl;
		return;
	}
	for (int i = 0; i < numVertices; ++i)
	{
		closeedge[i].vex = pos;
		closeedge[i].lowcost = getWeight(pos, i);//初始化从pos出发 到第i个顶点的权值
	}
	closeedge[pos].lowcost = 0;//pos本身置0
	for (int i = 0; i < numVertices - 1; ++i)// 遍历剩余所有节点
	{
		int minEdge = minmum();//取得代价最小边
		std::cout << '(' << VerticeList[closeedge[minEdge].vex] << "--->" << VerticeList[minEdge] << ')' << ' ';//访问
		closeedge[minEdge].lowcost = 0;//标记
		for (int j = 0; j < numVertices; ++j)//遍历所有顶点
		{
			if (Edge[minEdge][j] < closeedge[j].lowcost)
			{
				closeedge[j].vex = minEdge;//修正代价
				closeedge[j].lowcost = Edge[minEdge][j];
			}
		}
	}
}

template <class T, class E>
void GraphMtx<T, E>::InsertSort(EdgeSet<T, E> V[])
{
	EdgeSet<T, E> temp;
	for (int i = 0; i < numEdges; ++i)
	{
		temp = V[i];
		int j = i - 1;
		while (j >= 0 && temp.weight < V[j].weight)
		{
			V[j + 1] = V[j];
			--j;
		}
		V[j + 1] = temp;
	}
}

template <class T, class E>
void GraphMtx<T, E>::Kruskal()
{
	EdgeSet<T, E> E[DEFAULTVERTICES];
	int vset[DEFAULTVERTICES];
	int k = 0;
	for (int i = 0; i < numVertices; ++i)
	{
		for (int j = i + 1; j < numVertices; ++j)
		{
			if (Edge[i][j] != 0 && Edge[i][j] != maxWeight)
			{
				E[k].vex1 = i;
				E[k].vex2 = j;
				E[k].weight = Edge[i][j];
				++k;
			}
		}
	}
	for (int i = 0; i < numVertices; ++i)
	{
		vset[i] = i;
	}
	k = 1;
	int j = 0;
	this->InsertSort(E);
	while (k < numVertices)
	{
		int e1 = E[j].vex1;
		int e2 = E[j].vex2;
		int s1 = vset[e1];
		int s2 = vset[e2];
		if (s1 != s2)
		{
			std::cout << '(' << VerticeList[e1] << "--->" << VerticeList[e2] << ')' << ' ';//访问
			++k;
			for (int i = 0; i < numVertices; ++i)
				if (s2 == vset[i])vset[i] = s1;
		}
		++j;
	}
}

template <class T, class E>
int GraphMtx<T, E>::getFirstNeighbor(int v) const
{
	if (v == -1)return -1;
	for (int i = 0; i < numVertices; ++i)
		if (Edge[v][i] > 0 && Edge[v][i] < maxWeight)
			return i;
	return -1;
}

template <class T, class E>
int GraphMtx<T, E>::getNextNeighbor(int v, int w) const
{
	if (v == -1 || w == -1)return -1;
	for (int i = w + 1; i < numVertices; ++i)
		if (Edge[v][i] > 0 && Edge[v][i] < maxWeight)
			return i;
	return -1;
}

template <class T, class E>
bool GraphMtx<T, E>::insertVertice(const T& vertex)
{
	if (numVertices == maxVertices)return false;
	VerticeList[numVertices++] = vertex;

	return true;
}

template <class T, class E>
bool GraphMtx<T, E>::deleteVertice(int v)
{
	if (v < 0 || v >= numVertices)return false;
	VerticeList[v] = VerticeList[numVertices - 1];
	for (int i = 0; i < numEdges; ++i)
		if (Edge[i][v] > 0 && Edge[i][v] < maxWeight)
			--numEdges;
	for (int i = 0; i < numVertices; ++i)
		Edge[i][v] = Edge[i][numVertices - 1];

	for (int i = 0; i < numVertices; ++i)
		Edge[v][i] = Edge[numVertices - 1][i];
	--numVertices;
	return true;
}

template <class T, class E>
bool GraphMtx<T, E>::insertEdge(int v1, int v2, E weight)
{
	if (v1 > -1 && v2 > -1 && v1 < numVertices && v2 < numVertices)
	{
		Edge[v1][v2] = weight;
		++numEdges;
		if (!direction)
			Edge[v2][v1] = weight;
		return true;
	}
	return false;
}

template <class T, class E>
bool GraphMtx<T, E>::deleteEdge(int v1, int v2)
{
	if (v1 > -1 && v2 > -1 && v1 < numVertices && v2 < numVertices && Edge[v1][v2] > 0 && Edge[v1][v2] < maxWeight)
	{
		Edge[v1][v2] = maxWeight;
		--numEdges;
		if (!direction)
			Edge[v2][v1] = maxWeight;
		return true;
	}
	return false;
}

template <class T, class E>
E GraphMtx<T, E>::getWeight(int v1, int v2) const
{
	if (v1 > -1 && v2 > -1 && v1 < numVertices && v2 < numVertices)
		return Edge[v1][v2];
	else
		return E();
}

template <class T, class E>
T GraphMtx<T, E>::getValue(int i) const
{
	if (i >= 0 && i <= maxVertices)
		return VerticeList[i];
	else
		return T();
}

template <class T, class E>
void GraphMtx<T, E>::print() const
{
	cout << "This Graph has " << numVertices << " vertexs " << numEdges << " edges" << endl;
	for (int i = 0; i < numVertices; ++i)
		for (int j = i + 1; j < numVertices; ++j)
		{
			E w = getWeight(i, j);
			if (w > 0 && w < maxWeight)
			{
				T e1 = getValue(i);
				T e2 = getValue(j);
				cout << '(' << e1 << ',' << e2 << ',' << w << ')' << endl;
			}
		}
	cout << endl;
}


template <class T, class E>
void GraphMtx<T, E>::Dijkstra(const int v)
{
	int S[DEFAULTVERTICES], path[DEFAULTVERTICES], dist[DEFAULTVERTICES];
	for (int i = 0; i < numVertices; ++i)
	{
		dist[i] = Edge[v][i];
		S[i] = 0;
		if (i != v && dist[i] < maxWeight)
		{
			path[i] = v;
		}
		else { path[i] = -1; }
	}
	S[v] = 1;
	int mark=v;
	for(int i=0;i<numVertices-1;++i)
	{
		int min = maxWeight;
		for(int j=0;j<numVertices;++j)
		{
			if(!S[j]&&dist[j]<min)
			{
				min = dist[j];
				mark = j;
			}
		}
		S[mark] = 1;
		for(int w=0;w<numVertices;++w)
		{
			if(!S[w]&&Edge[mark][w]<maxWeight&&dist[mark]+Edge[mark][w]<dist[w])
			{
				path[w] = mark;
				dist[w] = dist[mark] + Edge[mark][w];
			}
		}

	}
	for(int i=0;i<numVertices;++i)
	{
		if(i!=v)
		{
			cout << i << '(' << VerticeList[i] << ':' << dist[i] << ")--->";
			for (int u = path[i];u!=-1;u=path[u])
			{
				cout << u << "(" << VerticeList[u] << ")--->";
			}
		}
	}
}
