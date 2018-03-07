#include <iostream>
#include "SeqQueue.h"
#include "ListedQueue.h"
using namespace std;

void YANGVI(int n);

int main()
{
	YANGVI(0);
	return 0;
}

void YANGVI(int n)
{
	ListedQueue<int> Q;
	Q.EnQueue(1);
	Q.EnQueue(1);

	for (int i = 0; i <= n; ++i)
	{
		int s = 0;
		//cout << endl;
		Q.EnQueue(0);
		for (int k = n - i - 1; k >= 0; --k)
		{
			cout << " ";
		}
		for (int j = 0; j <= i + 2; ++j)
		{
			int t = 0;
			Q.DeQueue(t);
			Q.EnQueue(s + t);
			s = t;
			if (j != i + 2)
				cout << s << " ";
		}
		cout << endl;
		Q.Display();
		cout << endl;
	}
}
