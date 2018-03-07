#include<iostream>
#include "HuffmanTree.h"
using namespace std;

int main()
{
	HFTree<char>H;
	char data[] = { 'x','a','b','c','d','e','f' };
	unsigned weight[] = { 0,1,2,3,4,5,6 };
	H.creatTree(data, weight, 6);
	H.print();
	H.Hcoding(6);
	return 0;
}