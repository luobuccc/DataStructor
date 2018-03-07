#pragma once
#include <iostream>

template <class T>
class SeqList
{
private:
	int length;
	int maxSize;
	T* array;
public:
	SeqList(int size = 40): length(0), maxSize(size), array(new T[maxSize])
	{
	}

	SeqList(const SeqList<T>& src)
	{
		length = src.length;
		maxSize = src.maxSize;
		array = new T[maxSize];
		for (int i = 0; i < length; ++i)
			array[i] = src.array[i];
	}

	~SeqList()
	{
		delete[]array;
		maxSize = length = 0;
	}

	bool isEmpty() const { return length == 0; }

	bool isFull() const { return length == maxSize; }

	int Length() const { return length; }

	bool Insert(int k, const T& val)
	{
		if (isFull())return false;
		if (k < 1 || k > length + 1)return false;
		for (int i = length - 1; i >= k - 1; --i)
			array[i + 1] = array[i];
		array[k - 1] = val;
		++length;
		return true;
	}

	bool Delete(int k, T& val)
	{
		if (isEmpty())return false;
		if (k < 1 || k > length)return false;
		val = array[k - 1];
		for (int i = k; i < length; ++i)
			array[i - 1] = array[i];
		--length;
		return true;
	}

	T Find(int k)
	{
		if (isEmpty())return -1;
		if (k < 1 || k > length)return -1;
		return array[k - 1];
	}

	int Find(const T& val) const
	{
		if (isEmpty())return -1;
		else
			for (int i = 0; i < length; ++i)
				if (val == array[i])
					return i + 1;
		return -1;
	}

	bool Update(int k, const T& val)
	{
		if (isEmpty())return false;
		if (k < 1 || k > length)return false;
		array[k - 1] = val;
		return true;
	}

	void Create()
	{
		std::cout << "Input length: " << std::endl;
		cin >> length;
		if (length > maxSize)
		{
			delete[] array;
			array = new T[length * 2];
		}
		std::cout << "Input elements: " << std::endl;
		for (int i = 0; i < length; ++i)
			std::cin >> array[i];
	}

	void Display()
	{
		for (int i = 0; i < length; ++i)
			std::cout << array[i] << " ";
	}
};
