#pragma once
template <class T>
class SeqList
{
private:
	int maxsize;
	int length;
	T* elements;
public:
	SeqList(int size): maxsize(size)
	{
		length = 0;
		elements = new T[size];
	}

	SeqList(const SeqList& src)
	{
		maxsize = src.maxsize;
		length = src.length;
		elements = new T[maxsize];
		for (int i = 0; i < length; ++i)
		{
			elements[i] = src.elements[i];
		}
	}

	~SeqList()
	{
		maxsize = length = 0;
		delete[] elements;
	}

	bool Insert(int k, const T& val);
	bool Delete(int k, T& val);
	bool Find(int k, T& val);
	bool Update(int k, const T& val);
	int GetLength() const { return length; }
	bool IsFull() const { return length == maxsize; }
	bool IsEmpty() const { return length == 0; }
	void Display();
};

template <class T>
bool SeqList<T>::Insert(int k, const T& val)
{
	if (IsFull())return false;
	if (k < 1 || k > length + 1)return false;
	for (int i = length - 1; i >= k - 1; --i)
	{
		elements[i + 1] = elements[i];
	}
	elements[k - 1] = val;
	++length;
	return true;
}

template <class T>
bool SeqList<T>::Delete(int k, T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length)return false;
	val = elements[k - 1];
	for (int i = k; i < length; ++i)
	{
		elements[i - 1] = elements[i];
	}
	--length;
	return true;
}

template <class T>
bool SeqList<T>::Find(int k, T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length)return false;
	val = elements[k - 1];
	return true;
}

template <class T>
bool SeqList<T>::Update(int k, const T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length)return false;
	elements[k - 1] = val;
	return true;
}

template <class T>
void SeqList<T>::Display()
{
	if (IsEmpty());
	for (int i = 0; i < length; ++i)
	{
		std::cout << elements[i] << "  ";
	}
}

template <class T>
class LinkedStack;

template <class T>
class LinkedList;

template <class T>
class LinkedQueue;

template <class T>
class QueueNode
{
private:
	T Data;
	QueueNode<T>* Link;
public:
	QueueNode(T data, QueueNode<T>* link = nullptr) : Data(data), Link(link)
	{
	}

	QueueNode(QueueNode<T>* link = nullptr) : Link(link)
	{
	}

	friend class LinkedQueue<T>;
};

template <class T>
class StackNode
{
private:
	T Data;
	StackNode<T>* Link;
public:
	StackNode(T data, StackNode<T>* link = nullptr) : Data(data), Link(link)
	{
	}

	StackNode(StackNode<T>* link = nullptr) : Link(link)
	{
	}

	friend class LinkedStack<T>;
};

template <class T>
class Node
{
private:
	T Data;
	Node<T>* Link;
public:
	Node(T data, Node<T>* link = nullptr): Data(data), Link(link)
	{
	}

	Node(Node<T>* link = nullptr): Link(link)
	{
	}

	friend class LinkedList<T>;
};

template <class T>
class LinkedList
{
private:
	int length;
	Node<T>* first;
	void MakeEmpty();
public:
	LinkedList()
	{
		length = 0;
		first = new Node<T>();
	}

	LinkedList(LinkedList<T>& list)
	{
		length = list.length;
		Node<T>* src = list.first->Link;
		first = new Node<T>();
		Node<T>* dst = first;
		while (src->Link)
		{
			dst->Link = new Node<T>(src->Data);
			src = src->Link;
			dst = dst->Link;
		}
		dst->Link = nullptr;
	}

	~LinkedList()
	{
		length = 0;
		MakeEmpty();
	}

	bool Insert(int k, const T& val);
	bool Delete(int k, T& val);
	bool Find(int k, T& val);
	bool Update(int k, const T& val);
	int GetLength() const { return length; }
	bool IsEmpty() { return first->Link == nullptr; }
	void Display();
};

template <class T>
void LinkedList<T>::MakeEmpty()
{
	Node<T>* ptr;
	while (first->Link)
	{
		ptr = first->Link;
		first->Link = ptr->Link;
		delete ptr;
	}
}

template <class T>
bool LinkedList<T>::Insert(int k, const T& val)
{
	if (k < 1 || k > length + 1) return false;
	int i = 0;
	Node<T>* ptr = first;
	while (i < k - 1)
	{
		ptr = ptr->Link;
		++i;
	}
	Node<T>* newPtr = new Node<T>(val);
	newPtr->Link = ptr->Link;
	ptr->Link = newPtr;
	++length;
	return true;
}

template <class T>
bool LinkedList<T>::Delete(int k, T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length) return false;
	int i = 0;
	Node<T>* ptr = first;
	while (i < k - 1)
	{
		ptr = ptr->Link;
		++i;
	}
	val = ptr->Link->Data;
	Node<T>* next = ptr->Link;
	ptr->Link = next->Link;
	--length;
	delete next;
	return true;
}

template <class T>
bool LinkedList<T>::Find(int k, T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length) return false;
	Node<T>* ptr = first;
	int i = 0;
	while (i < k && ptr)
	{
		ptr = ptr->Link;
		++i;
	}
	val = ptr->Data;
	return true;
}

template <class T>
bool LinkedList<T>::Update(int k, const T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length) return false;
	Node<T>* ptr = first;
	int i = 0;
	while (i < k && ptr)
	{
		ptr = ptr->Link;
		++i;
	}
	ptr->Data = val;
	return true;
}

template <class T>
void LinkedList<T>::Display()
{
	Node<T>* ptr = first->Link;
	while (ptr)
	{
		std::cout << ptr->Data << "  ";
		ptr = ptr->Link;
	}
}


template <class T>
class DoubleLinkedList;

template <class T>
class DouNode
{
private:
	T Data;
	DouNode<T> *prior, *next;
public:
	DouNode(DouNode<T>* p = nullptr, DouNode<T>* n = nullptr): prior(p), next(n)
	{
	}

	DouNode(T data, DouNode<T>* p = nullptr, DouNode<T>* n = nullptr) : Data(data), prior(p), next(n)
	{
	}

	friend class DoubleLinkedList<T>;
};

template <class T>
class DoubleLinkedList
{
private:
	int length;
	DouNode<T>* first;
	void MakeEmpty();
public:
	DoubleLinkedList()
	{
		first = new DouNode<T>();
		first->next = first;
		first->prior = first;
		length = 0;
	}

	~DoubleLinkedList()
	{
		length = 0;
		MakeEmpty();
	}

	bool Insert(int k, const T& val);
	bool Delete(int k, T& val);
	bool Find(int k, T& val);
	bool Update(int k, const T& val);
	int GetLength() const { return length; }
	bool IsEmpty() { return first->next == first; }
	void Display();
};

template <class T>
void DoubleLinkedList<T>::MakeEmpty()
{
	DouNode<T>* ptr = nullptr;
	while (first->next != first)
	{
		ptr = first->next;
		first->next = ptr->next;
		delete ptr;
	}
	first->next = first;
	first->prior = first;
}

template <class T>
bool DoubleLinkedList<T>::Insert(int k, const T& val)
{
	if (k < 1 || k > length + 1)return false;
	DouNode<T>* ptr = first;
	int i = 0;
	while (i < k)
	{
		ptr = ptr->next;
		++i;
	}
	DouNode<T>* newPtr = new DouNode<T>(val, ptr->prior, ptr);
	ptr->prior->next = newPtr;
	ptr->prior = newPtr;
	++length;
	return true;
}

template <class T>
bool DoubleLinkedList<T>::Delete(int k, T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length)return false;
	DouNode<T>* ptr = first;
	int i = 0;
	while (i < k)
	{
		ptr = ptr->next;
		++i;
	}
	val = ptr->Data;
	ptr->prior->next = ptr->next;
	ptr->next->prior = ptr->prior;
	delete ptr;
	--length;
	return true;
}

template <class T>
bool DoubleLinkedList<T>::Find(int k, T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length)return false;
	DouNode<T>* ptr = first;
	int i = 0;
	while (i < k)
	{
		ptr = ptr->next;
		++i;
	}
	val = ptr->Data;
	return true;
}

template <class T>
bool DoubleLinkedList<T>::Update(int k, const T& val)
{
	if (IsEmpty())return false;
	if (k < 1 || k > length)return false;
	DouNode<T>* ptr = first;
	int i = 0;
	while (i < k)
	{
		ptr = ptr->next;
		++i;
	}
	ptr->Data = val;
	return true;
}

template <class T>
void DoubleLinkedList<T>::Display()
{
	DouNode<T>* ptr = first->next;
	while (ptr != first)
	{
		std::cout << ptr->Data << "  ";
		ptr = ptr->next;
	}
}


template <class T>
class SeqStack
{
private:
	int top;
	int maxsize;
	int* theArray;
public:
	SeqStack(int size = 20): maxsize(size)
	{
		top = -1;
		theArray = new T[size];
	}

	~SeqStack()
	{
		top = -1;
		maxsize = 0;
		delete[] theArray;
	}

	bool Push(const T& val);
	bool Pop(T& val);
	bool Peek(const T& val);
	bool IsEmpty() const { return top == -1; }
	bool IsFull() const { return top == maxsize - 1; }
	void Display() const;
};

template <class T>
bool SeqStack<T>::Push(const T& val)
{
	if (IsFull())return false;
	theArray[++top] = val;
	return true;
}

template <class T>
bool SeqStack<T>::Pop(T& val)
{
	if (IsEmpty())return false;
	val = theArray[top--];
	return true;
}

template <class T>
bool SeqStack<T>::Peek(const T& val)
{
	if (IsEmpty()) return false;
	val = theArray[top];
	return true;
}

template <class T>
void SeqStack<T>::Display() const
{
	for (int i = top; i > -1; --i)
		std::cout << theArray[i] << "  ";
}


template <class T>
class LinkedStack
{
private:
	StackNode<T>* top;
	void MakeEmpty();
public:
	LinkedStack() { top = nullptr; }
	~LinkedStack() { MakeEmpty(); }
	bool Push(const T& val);
	bool Pop(T& val);
	bool Peek(const T& val);
	bool IsEmpty() const { return top == nullptr; }
	void Display() const;
};

template <class T>
void LinkedStack<T>::MakeEmpty()
{
	StackNode<T>* ptr = nullptr;
	while (top)
	{
		ptr = top;
		top = top->Link;
		delete ptr;
	}
}

template <class T>
bool LinkedStack<T>::Push(const T& val)
{
	StackNode<T>* newPtr = new StackNode<T>(val);
	newPtr->Link = top;
	top = newPtr;
	return true;
}

template <class T>
bool LinkedStack<T>::Pop(T& val)
{
	if (IsEmpty())return false;
	StackNode<T>* ptr = top;
	val = top->Data;
	top = top->Link;
	delete ptr;
	return true;
}

template <class T>
bool LinkedStack<T>::Peek(const T& val)
{
	if (IsEmpty())return false;
	val = top->Data;
	return true;
}

template <class T>
void LinkedStack<T>::Display() const
{
	StackNode<T>* ptr = top;
	while (ptr)
	{
		std::cout << ptr->Data << "  ";
		ptr = ptr->Link;
	}
}


template <class T>
class SeqQueue
{
private:
	int front, rare;
	T* vector;
	int maxsize;
public:
	SeqQueue(int size): maxsize(size)
	{
		front = rare = 0;
		vector = new T[size];
	}

	~SeqQueue()
	{
		maxsize = front = rare = 0;
		delete[] vector;
	}

	bool EnQueue(const T& val);
	bool DeQueue(T& val);
	bool GetFront(T& val);

	bool IsEmpty() const
	{
		return front == rare;
	}

	bool IsFull() const
	{
		return (rare + 1) % maxsize == front;
	}

	int GetLength() const
	{
		return (rare - front + maxsize) % maxsize;
	}

	void Display();
};

template <class T>
bool SeqQueue<T>::EnQueue(const T& val)
{
	if (IsFull())return false;
	vector[rare] = val;
	rare = (rare + 1) % maxsize;
	return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T& val)
{
	if (IsEmpty())return false;
	val = vector[front];
	front = (front + 1) % maxsize;
	return true;
}

template <class T>
bool SeqQueue<T>::GetFront(T& val)
{
	if (IsEmpty())return false;
	val = vector[front];
	return true;
}

template <class T>
void SeqQueue<T>::Display()
{
	for (int i = 0; i < GetLength(); ++i)
		std::cout << vector[i] << "  ";
}


template <class T>
class LinkedQueue
{
private:
	QueueNode<T> *front, *rare;
	void MakeEmpty();
public:
	LinkedQueue() { front = rare = nullptr; }
	~LinkedQueue() { MakeEmpty(); }
	bool EnQueue(const T& val);
	bool DeQueue(T& val);
	bool GetFront(T& val);
	bool IsEmpty() const { return front == nullptr; }
	int GetLength() const;
	void Display();
};

template <class T>
void LinkedQueue<T>::MakeEmpty()
{
	QueueNode<T>* ptr = nullptr;
	while (front)
	{
		ptr = front;
		front = front->Link;
		delete ptr;
	}
}

template <class T>
bool LinkedQueue<T>::EnQueue(const T& val)
{
	QueueNode<T>* newPtr = new QueueNode<T>(val);
	if (front == nullptr)
		front = rare = newPtr;
	else
	{
		rare->Link = newPtr;
		rare = rare->Link;
	}
	return true;
}

template <class T>
bool LinkedQueue<T>::DeQueue(T& val)
{
	if (IsEmpty())return false;
	QueueNode<T>* ptr = front;
	val = ptr->Data;
	front = front->Link;
	delete ptr;
	if (!front)rare = front;
	return true;
}

template <class T>
bool LinkedQueue<T>::GetFront(T& val)
{
	if (IsEmpty())return false;
	val = front->Data;
	return true;
}

template <class T>
int LinkedQueue<T>::GetLength() const //
{
	int i = 0;
	QueueNode<T>* ptr = front;
	while (ptr)
	{
		ptr = ptr->Link;
		++i;
	}
	return i;
}

template <class T>
void LinkedQueue<T>::Display()
{
	QueueNode<T>* ptr = front;
	while (ptr)
	{
		std::cout << ptr->Data << "  ";
		ptr = ptr->Link;
	}
}


template <class T>
class DoubleStack
{
private:
	int top[2], bottom[2];
	int maxsize;
	T* elements;
public:
	DoubleStack(int size): maxsize(size)
	{
		elements = new T[size];
		top[0] = bottom[0] = -1;
		top[1] = bottom[1] = maxsize;
	}

	~DoubleStack()
	{
		maxsize = 0;
		delete[] elements;
	}

	bool Push(int k, const T& val);
	bool Peek(int k, T& val);
	bool Pop(int k, T& val);
	bool IsEmpty(int k);
	bool IsFull() { return top[0] + 1 == top[1]; }
	void Display();
};

template <class T>
void DoubleStack<T>::Display()
{
	for (int i = top[0]; i >= 0; --i)
		std::cout << elements[i] << "  ";
	for (int i = top[1]; i < bottom[1]; ++i)
		std::cout << elements[i] << "  ";
}

template <class T>
bool DoubleStack<T>::IsEmpty(int k)
{
	if (k < 1 || k > 2)return false;
	return top[k - 1] == bottom[k - 1];
}

template <class T>
bool DoubleStack<T>::Push(int k, const T& val)
{
	if (IsFull())return false;
	if (k < 1 || k > 2) return false;
	if (k == 1)
	{
		elements[++top[0]] = val;
		return true;
	}
	else
	{
		elements[--top[1]] = val;
		return true;
	}
}

template <class T>
bool DoubleStack<T>::Peek(int k, T& val)
{
	if (IsEmpty(k))return false;
	if (k < 1 || k > 2) return false;
	if (k == 1)
	{
		val = elements[top[0]];
		return true;
	}
	else
	{
		val = elements[top[1]];
		return true;
	}
}

template <class T>
bool DoubleStack<T>::Pop(int k, T& val)
{
	if (IsEmpty(k))return false;
	if (k < 1 || k > 2) return false;
	if (k == 1)
	{
		val = elements[top[0]--];
		return true;
	}
	else
	{
		val = elements[top[1]++];
		return true;
	}
}
