#pragma once
#include <ostream>
#include <iostream>

template <class T>
class LinkedStack;

template <class T>
class Node
{
private:
	T Data;
	Node<T>* Link;
public:
	Node(Node<T>* ptr = nullptr) : Link(ptr)
	{
	}

	Node(T data, Node<T>* ptr = nullptr) : Data(data), Link(ptr)
	{
	}

	friend class LinkedStack<T>;
};

template <class T>
class LinkedStack
{
private:
	Node<T>* top;

	void Empty()
	{
		while (top)
		{
			Node<T>* ptr = top;
			top = top->Link;
			delete ptr;
		}
	};
public:
	LinkedStack() { top = nullptr; }

	bool Push(const T& val)
	{
		top = new Node<T>(val, top);
		return true;
	}

	bool IsEmpty() const { return top == nullptr; }

	bool Pop(T& val)
	{
		if (IsEmpty())return false;
		val = top->Data;
		Node<T>* ptr = top;
		top = top->Link;
		delete ptr;
		return true;
	}

	bool Peek(T& val);
	void Display();
};

template <class T>
bool LinkedStack<T>::Peek(T& val)
{
	if (IsEmpty())return false;
	val = top->Data;
	return true;
}

template <class T>
void LinkedStack<T>::Display()
{
	while (top)
	{
		std::cout << top->Data << std::endl;
		top = top->Link;
	}
}
