#pragma once
template <class T>
class DoubleStack
{
private:
	T* vector;
	int top[2];
	int bottom[2];
	int maxsize;
public:
	DoubleStack(int size): maxsize(size)
	{
		vector = new T[size];
		top[0] = bottom[0] = -1;
		top[1] = bottom[1] = size;
	}

	bool IsFull() const { return top[0] + 1 == top[1]; }
	bool IsEmpty(int i) const;
	bool Push(int i, const T& val);
	bool Peek(int i, T& val) const;
	bool Pop(int i, T& val);
	void Display();
};

template <class T>
bool DoubleStack<T>::IsEmpty(int i) const
{
	if (i < 1 || i > 2)return false;
	else return (top[i - 1] == bottom[i - 1]);
}

template <class T>
bool DoubleStack<T>::Push(int i, const T& val)
{
	if (i < 1 || i > 2 || IsFull())return false;
	if (i == 1)
	{
		vector[++top[0]] = val;
		return true;
	}
	else
	{
		vector[--top[1]] = val;
		return true;
	}
}

template <class T>
bool DoubleStack<T>::Peek(int i, T& val) const
{
	if (i < 1 || i > 2 || IsEmpty(i))return false;
	if (i == 1)
	{
		val = vector[top[0]];
		return true;
	}
	else
	{
		val = vector[top[1]];
		return true;
	}
}

template <class T>
bool DoubleStack<T>::Pop(int i, T& val)
{
	if (i < 1 || i > 2 || IsEmpty(i))return false;
	if (i == 1)
	{
		val = vector[top[0]--];
		return true;
	}
	else
	{
		val = vector[top[1]++];
		return true;
	}
}

template <class T>
void DoubleStack<T>::Display()
{
	std::cout << "The First Stack:" << std::endl;
	for (int i = top[0]; i >= 0; --i)
		std::cout << vector[i] << " ";// << std::endl;
	std::cout <<std::endl<< "The Second Stack:" << std::endl;
	for (int i = top[1]; i < maxsize; ++i)
		std::cout << vector[i] << " ";// << std::endl;
	std::cout<<std::endl;
}
