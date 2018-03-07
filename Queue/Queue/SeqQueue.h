#pragma once
template <class T>
class SeqQueue
{
private:
	int maxsize;
	T* theArray;
	int front, rear;
public:

	SeqQueue(int size)
		: maxsize(size)
	{
		front = 0;
		rear = 0;
		theArray = new T[maxsize];
	}

	~SeqQueue() { delete[] theArray; }
	bool EnQueue(const T& val);
	bool DeQueue(T& val);
	bool GetFront(T& val);
	bool IsEmpty() const { return rear == front; }
	bool IsFull() const { return (rear + 1) % maxsize == front; }
	int GetLength() const { return (rear - front + maxsize) % maxsize; }
};

template <class T>
bool SeqQueue<T>::EnQueue(const T& val)
{
	if (IsFull())return false;
	theArray[rear] = val;
	rear = (rear + 1) % maxsize;
	return true;
}

template <class T>
bool SeqQueue<T>::DeQueue(T& val)
{
	if (IsEmpty())return false;
	val = theArray[front];
	front = (front + 1) % maxsize;
	return true;
}

template <class T>
bool SeqQueue<T>::GetFront(T& val)
{
	if (IsEmpty())return false;
	val = theArray[front];
	return true;
}
