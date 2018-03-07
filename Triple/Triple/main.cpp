#include<iostream>
#include "Triple.h"

using namespace std;

int main()
{
	TripleList<int> T;
	T.Display();
	T.FastConvert();
	T.Display();
	T.Delete();
	T.Display();
	return 0;
}
