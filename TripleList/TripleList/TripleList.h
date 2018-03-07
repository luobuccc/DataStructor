#pragma once
template <class T>
class TripleList;

template <class T>
class Triple
{
private:
	int row, col;
	T data;
public:

	Triple()
	{
	}

	Triple(int row, int col, const T& data): row(row), col(col), data(data)
	{
	}

	friend class TripleList<T>;
};


template <class T>
class TripleList
{
private:
	Triple<T>* data = nullptr;
	int row;
	int col;
	int nums;
	int maxsize;
public:


	TripleList(int maxsize = 40): maxsize(maxsize)
	{
		nums = 0;
		data = new Triple<T>[maxsize];
	}

	TripleList(int row, int col, int maxsize): row(row), col(col), maxsize(maxsize)
	{
		nums = 0;
		data = new Triple<T>[maxsize];
	}

	~TripleList()
	{
		delete[] data;
		nums = 0;
	}

	void Construct(TripleList<T>& M);
	bool Insert(const Triple<T>& src);
	bool Delete(Triple<T>& src);
	bool GetNums() const { return nums; }
	bool IsFull() const { return nums == maxsize - 1; }
	bool IsEmpty() const { return nums == 0; }

	void Convert()
	{
	}

	void Convert(TripleList<T>& src);
	void FastConvert(TripleList<T>& src);
	bool Display();
};

template <class T>
void TripleList<T>::Construct(TripleList<T>& M)
{
	int nums, col, row;
	std::cout << "Input maxsize nums cols rows" << std::endl;
	std::cin >> nums;
	std::cin >> col;
	std::cin >> row;
	M.col = col;
	M.row = row;
	M.nums = nums;
	for (int i = 0; i < nums; ++i)
	{
		std::cout << "Input " << i << std::endl;
		T data;
		std::cin >> row;
		std::cin >> col;
		std::cin >> data;
		Triple<T> temp(row, col, data);
		M.data[i] = temp;
	}
}

template <class T>
bool TripleList<T>::Insert(const Triple<T>& src)
{
	if (IsFull()) return false;
	if (src.col < 0 || src.row < 0 || src.col > col - 1 || src.row > row - 1)return false;
	data[nums++] = src;
	return true;
}

template <class T>
bool TripleList<T>::Delete(Triple<T>& src)
{
	if (IsEmpty())return false;
	src = data[--nums];
	return true;
}

template <class T>
void TripleList<T>::Convert(TripleList<T>& src)
{
	if (src.IsEmpty())
	{
	}
	src.col = row;
	src.row = col;
	src.nums = nums;
	src.data = new Triple<T>[maxsize];
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < nums; ++j)
		{
			if (data[j].col == i)
			{
				Triple<T> T;
				T.col = data[i].rol;
				T.row = data[i].col;
				T.data = data[i].data;
				src.Insert(T);
			}
		}
}

template <class T>
void TripleList<T>::FastConvert(TripleList<T>& src)
{
	if (src.IsEmpty())
	{
	}
	src.col = row;
	src.row = col;
	src.nums = nums;
	src.data = new Triple<T>[nums];
	int* num = new int[col];
	int* cpos = new int[col];
	for (int i = 0; i < col; ++i) num[i] = 0;
	for (int i = 0; i < nums; ++i)
		++num[data[i].col];
	cpos[0] = 0;
	for (int i = 1; i < col; ++i)
		cpos[i] = cpos[i - 1] + num[i - 1];
	for (int i = 0; i < nums; ++i)
	{
		int p = cpos[data[i].col];
		src.data[p].row = data[i].col;
		src.data[p].col = data[i].row;
		src.data[p].data = data[i].data;
		++cpos[data[i].col];
	}
}

template <class T>
bool TripleList<T>::Display()
{
	if (IsEmpty())return false;
	std::cout << "This Triple: " << row << " * " << col << "have " << nums << " elements" << std::endl;
	for (int i = 0; i < nums; ++i)
	{
		Triple<T> t = data[i];
		std::cout << t.row << "   " << t.col << "   " << t.data << std::endl;
	}
	return true;
}
