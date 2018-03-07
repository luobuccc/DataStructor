#include <iostream>
#include "DS.h"
using namespace std;

int main()
{
	int temp = 0;
	SeqList<int> SL(20);
	for (int i = 0; i < 15; i += 2)
	{
		SL.Insert(1, i);
	}
	SL.Display();
	SL.Delete(3, temp);
	cout << endl;
	SL.Display();
	cout << endl;
	LinkedList<int> LL;
	for (int i = 0; i < 15; i += 2)
	{
		LL.Insert(1, i);
	}
	LL.Display();
	LL.Delete(3, temp);
	LL.Update(1, 50);
	cout << endl;
	LL.Display();
	cout << endl;
	DoubleLinkedList<int> DLL;
	for (int i = 0; i < 15; i += 2)
	{
		DLL.Insert(1, i);
	}
	DLL.Display();
	cout << endl;
	DLL.Delete(3, temp);
	DLL.Update(1, 50);
	DLL.Display();
	cout << endl;
	SeqStack<int> SS(20);
	for (int i = 0; i < 15; i += 2)
	{
		SS.Push(i);
	}
	SS.Display();
	cout << endl;
	SS.Pop(temp);
	SS.Display();
	cout << endl;
	LinkedStack<int> LS;
	for (int i = 0; i < 15; i += 2)
	{
		LS.Push(i);
	}
	LS.Display();
	cout << endl;
	LS.Pop(temp);
	LS.Display();
	cout << endl;
	SeqQueue<int> SQ(20);
	for (int i = 0; i < 15; i += 2)
	{
		SQ.EnQueue(i);
	}
	SQ.Display();
	cout << endl;
	SQ.DeQueue(temp);
	SQ.Display();
	cout << endl;
	//cout << "LQ" << endl;
	LinkedQueue<int> LQ;
	for (int i = 0; i < 15; i += 2)
	{
		LQ.EnQueue(i);
	}
	LQ.Display();
	cout << endl;
	LQ.DeQueue(temp);
	LQ.Display();
	cout << endl;
	//cout << LQ.GetLength();
	

	return 0;
}
