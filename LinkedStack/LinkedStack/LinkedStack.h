#pragma once
#include <Windows.h>

template <class T> class LinkedStack;
template<class T>
class LinkNode{
private:
	T data;
	LinkNode *link;
public:
	friend class LinkedStack<T>;
	LinkNode(LinkNode<T> *ptr=NULL):link(ptr){}
	LinkNode(T item,LinkNode<T> *ptr=NULL):data(item),link(ptr){}
};

template <class T>
class LinkedStack
{
private:
	LinkNode<T> *top;

public:
	LinkedStack(){top=NULL;}
	~LinkedStack(){MakeEmpty();}
	void Push(const T val);
	bool Pop(T &val);
	bool GetTop(T &val)const;
	bool IsEmpty()const {return top==NULL;}
	void MakeEmpty();
	void Traverse()const;
};

