#pragma once
template <class T>
class SeqStack
{
private:
	int top;
	int maxsize;
	T* theArray;
public:
	SeqStack(int size) : maxsize(size)
	{
		theArray = new T[size];
		top = -1;
	}

	bool Push(const T val);
	bool Pop(T& val);
	bool Peek(T& val);
	bool IsEmpty() const { return top == -1; };
	bool IsFull() const { return top == (maxsize - 1); };
	void Display();
};

template <class T>
bool SeqStack<T>::Push(const T val)
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
bool SeqStack<T>::Peek(T& val)
{
	if (IsEmpty())return false;
	val = theArray[top];
	return true;
}

template <class T>
void SeqStack<T>::Display()
{
	int i = top;
	while (i >= 0)
	{
		std::cout << theArray[i] << std::endl;
		--i;
	}
}
