#include <iostream>
#include "TripleList.h"
using namespace std;

int main()
{
	TripleList<int> S,T,V;
	S.Construct(T);
	T.FastConvert(V);
	V.Display();

	return 0;
}
