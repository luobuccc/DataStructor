#include<iostream>
#include"Graph.h"
#include "GraphAList.h"
using namespace std;

int main()
{
	/*
	GraphMtx<int, int> G;
	G.CreateGM();
	G.print();*/
	Graph<int, int> G(0);
	G.Create(7, 12);
	G.DFSTraverse();
	//G.Dijkstra(3);

	return 0;
}
