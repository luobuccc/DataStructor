#include<iostream>
#include"SqeStack.h"
#include "LinkedQueue.h"
using namespace std;

int main()
{
	/*
	SeqStack<int> S(10);
	for (int i = 1; i <= 5; ++i)
		S.Push(i);
	S.Display();
	cout << endl;
	int t;
	S.Pop(t);
	S.Pop(t);
	S.Pop(t);
	S.Push(6);
	S.Push(7);
	S.Push(5);
	S.Display();
	cout << endl;
*/
	ListedQueue<int> L;
	for (int i = 1; i <= 5; ++i)
		L.EnQueue(i);
	L.Display();
	cout << endl;
	int t;
	L.DeQueue(t);
	L.DeQueue(t);
	L.Display();
	cout << endl;
	L.EnQueue(6);
	L.EnQueue(7);
	L.EnQueue(8);
	L.Display();
	cout << endl;

	return 0;
}
