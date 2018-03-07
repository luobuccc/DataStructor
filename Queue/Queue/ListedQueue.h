#pragma once
template <class T>
class ListedQueue;

template <class T>
class Node
{
private:
	T Data;
	Node<T>* Link;
public:
	Node(Node<T>* ptr = nullptr): Link(ptr)
	{
	}

	Node(T data, Node<T>* ptr = nullptr): Data(data), Link(ptr)
	{
	}

	friend class ListedQueue<T>;
};

template <class T>
class ListedQueue
{
private:
	Node<T>* front;
	Node<T>* rear;
	void Empty();
public:
	ListedQueue()
	{
		front = rear = nullptr;
	}

	~ListedQueue()
	{
		Empty();
	}

	bool EnQueue(const T& val);
	bool DeQueue(T& val);
	bool GetFront(T& val);
	bool IsEmpty() const { return front == nullptr; }
	int GetLength() const;
	void Display();
};

template <class T>
void ListedQueue<T>::Empty()
{
	while (front != nullptr)
	{
		Node<T>* ptr = nullptr;
		ptr = front;
		front = front->Link;
		delete ptr;
	}
}

template <class T>
bool ListedQueue<T>::EnQueue(const T& val)
{
	if (front == nullptr)
	{
		front = rear = new Node<T>(val);
		return true;
	}
	else
	{
		rear->Link = new Node<T>(val);
		rear = rear->Link;
		return true;
	}
}

template <class T>
bool ListedQueue<T>::DeQueue(T& val)
{
	if (IsEmpty())return false;
	val = front->Data;
	Node<T>* ptr = front;
	front = front->Link;
	delete ptr;
	if (front == nullptr)
		rear = front;
	return true;
}

template <class T>
bool ListedQueue<T>::GetFront(T& val)
{
	if (IsEmpty()) return false;
	val = front->Data;
	return true;
}

template <class T>
int ListedQueue<T>::GetLength() const
{
	Node<T>* ptr = front;
	static int count = 0;
	while (ptr)
	{
		ptr = ptr->Link;
		++count;
	}
	return count;
}

template <class T>
void ListedQueue<T>::Display()
{
	if(!IsEmpty())
	{
		Node<T> *ptr = front;
		while (ptr != rear) {
			cout << ptr->Data << " ";
			ptr = ptr->Link;
		}
		
	}
}
