#pragma once
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

const int DEFAULTSIZE = 30;
int visited[DEFAULTSIZE];

template <class T, class E>
class Graph;

template <class T, class E>
class Edge
{
private:
	E cost;
	Edge<T, E>* Link;
	int dest;
public:
	Edge(int d = 0, E c = E(), Edge<T, E>* next = nullptr): cost(c), Link(next), dest(d)
	{
	}

	friend class Graph<T, E>;
};

template <class T, class E>
class Vertex
{
public:
	Vertex(const T& data = T(), Edge<T, E>* first = nullptr): data(data), first(first)
	{
	}

	T data;
	Edge<T, E>* first;
};

template <class T, class E>
class Graph
{
private:
	Vertex<T, E>* VerList;
	int maxSize;
	int numVer;
	int direction;
	int numEdge;

	int FindVertex(const T& ver)
	{
		for (int i = 0; i < numVer; ++i)
			if (VerList[i].data == ver)
				return i;
		return -1;
	}

	void DFS(int v);
	bool FindInEdge(int w);
public:
	Graph(int d = 0, int size = DEFAULTSIZE): maxSize(size), numVer(0), direction(d), numEdge(0)
	{
		VerList = new Vertex<T, E>[size];
	}

	~Graph();
	void Create(int n, int e);
	bool InsertVertex(const T& ver);
	bool InsertEdge(const T v1, const T v2, const E weight);
	bool DeleteVertex(const int pos);
	bool DeleteEdge(const int v1, const int v2);
	Edge<T, E>* getFirstNeighbor(const int v);
	Edge<T, E>* getNextNeighbor(const int v1, const int v2);
	void DFSTraverse();
	void BFSTraverse();
	void print();
};

template <class T, class E>
void Graph<T, E>::DFS(int v)
{
	visited[v] = 1;
	cout << VerList[v].data << " ";
	Edge<T, E>* p = getFirstNeighbor(v);
	for (; p; p = getNextNeighbor(v, p->dest))
	{
		int w = p->dest;
		if (!visited[w])
		{
			if (direction == 2)//对于有向图
			{
				if (VerList[w].first != NULL || !FindInEdge(w))//不存在出边||不存在入边
					DFS(w);
			}
			else { DFS(w); }
		}
	}
}

template <class T, class E>
bool Graph<T, E>::FindInEdge(int w)
{
	for (int i = 0; i < numVer; ++i)
	{
		Edge<T, E>* p = VerList[i].first;
		while (p)
		{
			if (p->dest == w)return true;
			else
				p = p->Link;
		}
	}
	return false;
}

template <class T, class E>
Graph<T, E>::~Graph()
{
	for (int i = 0; i < numVer; ++i)
	{
		Edge<T, E>* p = VerList[i].first;
		while (p)
		{
			VerList[i].first = p->Link;
			delete p;
			p = VerList[i].first;
		}
	}
	delete[] VerList;
}

template <class T, class E>
void Graph<T, E>::Create(int n, int e)
{
	T v1, v2;
	E weight;
	cout << "Input the vertex: " << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << i + 1 << ": ";
		cin >> v1;
		InsertVertex(v1);
	}
	cout << "Input Edge: " << endl;
	for (int i = 0; i < e; ++i)
	{
		cout << "Input two vertex and weight: ";
		cin >> v1 >> v2 >> weight;
		InsertEdge(v1, v2, weight);
	}
}

template <class T, class E>
bool Graph<T, E>::InsertVertex(const T& ver)
{
	if (numVer == maxSize)
		return false;
	VerList[numVer].data = ver;
	VerList[numVer].first = nullptr;
	++numVer;
	return true;
}

template <class T, class E>
bool Graph<T, E>::InsertEdge(const T v1, const T v2, const E weight)
{
	int p1 = FindVertex(v1), p2 = FindVertex(v2);
	if (p1 == -1 || p2 == -1)return false;
	VerList[p1].first = new Edge<T, E>(p2, weight, VerList[p1].first);
	if (direction == 0)
		VerList[p2].first = new Edge<T, E>(p1, weight, VerList[p2].first);
	++numEdge;
	return true;
}

template <class T, class E>
bool Graph<T, E>::DeleteVertex(const int pos)
{
	if (pos < 0 || pos > numVer - 1)return false;
	Edge<T, E>* p = VerList[pos].first;
	while (p)
	{
		VerList[pos].first = p->Link;
		delete p;
		--numEdge;
		p = VerList[pos].first;
	}
	for (int i = 0; i < numVer; ++i)
	{
		p = VerList[i].first;
		if (p && p->dest == pos)
		{
			VerList[i].first = p->Link;
			delete p;
		}
		else
		{
			if (p)
			{
				Edge<T, E>* q = p->Link;
				while (q && q->dest != pos)
				{
					p = q;
					q = q->Link;
				}
				if (q)
				{
					p->Link = q->Link;
					delete q;
				}
			}
		}
		if (direction)
			--numEdge;
	}
	--numVer;
	if (pos != numVer)
	{
		VerList[pos].data = VerList[numVer].data;
		VerList[pos].first = VerList[numVer].first;
		for (int i = 0; i < numVer; ++i)
		{
			if (i != pos)
				p = VerList[i].first;
		}
		while (p)
		{
			if (p->dest == numVer)
			{
				p->dest = pos;
				//break;
			}
			else
				p = p->Link;
		}
	}
	return true;
}

template <class T, class E>
bool Graph<T, E>::DeleteEdge(const int v1, const int v2)
{
	if (v1 < 0 || v2 < 0 || v1 > numVer - 1 || v2 > numVer - 1)return false;
	Edge<T, E>* p = VerList[v1].first;
	if (p->dest == v2)
	{
		VerList[v1].first = p->Link;
		delete p;
	}
	else
	{
		Edge<T, E>* q = p->Link;
		while (q && q->dest != v2)
		{
			p = q;
			q = q->Link;
		}
		if (q)
		{
			p->Link = q->Link;
			delete q;
		}
	}
	--numEdge;
	if (direction == 0)
	{
		p = VerList[v2].first;
		if (p->dest == v2)//no head_node can't synchronize operate
		{
			VerList[v2].first = p->Link;
			delete p;
		}
		else
		{
			Edge<T, E>* q = p->Link;
			while (q && q->dest != v1)
			{
				p = q;
				q = q->Link;
			}
			if (q)
			{
				p->Link = q->Link;
				delete q;
			}
		}
	}
	return true;
}

template <class T, class E>
Edge<T, E>* Graph<T, E>::getFirstNeighbor(const int v)
{
	if (v < 0 || v > numVer - 1)return nullptr;
	return VerList[v].first ? VerList[v].first : nullptr;
}

template <class T, class E>
Edge<T, E>* Graph<T, E>::getNextNeighbor(const int v1, const int v2)
{
	if (v1 < 0 || v1 > numVer - 1 || v2 < 0 || v2 > numVer - 1)return nullptr;
	Edge<T, E>* p = VerList[v1].first;
	while (p && p->dest != v2)
	{
		p = p->Link;
	}
	if (p)
	{
		if (p->Link)return p->Link;
		else { return nullptr; }
	}
	else { return nullptr; }
}

template <class T, class E>
void Graph<T, E>::DFSTraverse()
{
	// ReSharper disable once CppEntityNeverUsed
	int count = 0;
	for (int v = 0; v < numVer; ++v)visited[v] = 0;
	for (int v = 0; v < numVer; ++v)
		if (!visited[v])
		{
			cout << "Find Graph " << count++ << ':' << endl;
			DFS(v);
			cout << endl;
		}
}

template <class T, class E>
void Graph<T, E>::BFSTraverse()
{
	for (int v = 0; v < numVer; ++v)visited[v] = 0;
	int queue[DEFAULTSIZE], front = -1, rear = -1;
	for (int i = 0; i < numVer; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			cout << VerList[i].data << " ";
			queue[++rear] = i;
			while (rear != front)
			{
				int v = queue[++front];
				Edge<T, E>* p = getFirstNeighbor(v);
				while (p)
				{
					int w = p->dest;
					if (!visited[w])
					{
						visited[w] = 1;
						cout << VerList[w].data << " ";
						queue[++rear] = w;
					}
					p = getNextNeighbor(v, w);
				}
			}
		}
	}
}

template <class T, class E>
void Graph<T, E>::print()
{
	for (int i = 0; i < numVer; ++i)
	{
		cout << i + 1 << ": " << VerList[i].data << "--->";
		Edge<T, E>* p = VerList[i].first;
		while (p)
		{
			cout << p->dest << "(" << VerList[p->dest].data << "," << p->cost << ")--->";
			p = p->Link;
		}
		cout << endl;
	}
}
