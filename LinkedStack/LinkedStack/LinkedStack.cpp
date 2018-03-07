#include "LinkedStack.h"
#include <iostream>
using namespace std;

template<class T>
void LinkedStack<T>::MakeEmpty()
{
	LinkNode<T>*p;
	while(top)
	{
		p=top;
		top=top->link;
		delete p;
	}
}

template <class T>
void LinkedStack<T>::Push(const T val)
{
	top=new LinkNode<T>(val,top);
}

template <class T>
bool LinkedStack<T>::Pop(T &val)
{
	if(IsEmpty())
	{
		cout<<"Õ»¿Õ£¬²Ù×÷Ê§°Ü";
		return false;
	}
	LinkNode<T> *p=top;
	val=top->data;
	top=top->link;
	delete p;
	return true;
}

template<class T>
void LinkedStack<T>::Traverse()const
{
	LinkNode<T> *p=top;
	while(p)
	{
		cout<<p->data<<endl;
		p=p->link;
	}
}