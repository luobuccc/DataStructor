#pragma once

template <class T>
class TripleList;

template <class T>
class Triple
{
private:
	int row = 0;
	int col = 0;
	T data;
public:
	Triple() = default;

	Triple(int row, int col, const T& data): row(row), col(col), data(data)
	{
	}

	friend class TripleList<T>;
};


template <class T>
class TripleList
{
private:
	Triple<T>* data;
	int row, col, nums, maxsize;
public:
	TripleList(): row(0), col(0), nums(0), maxsize(0)
	{
		std::cout << "Input row col nums maxsize:" << std::endl;
		std::cin >> row >> col >> nums >> maxsize;
		data = new Triple<T>[maxsize];
		for (int i = 0; i < nums; ++i)
		{
			int row, col;
			T dt;
			std::cout << "input " << i + 1 << " elements row col data: " << std::endl;
			std::cin >> row >> col >> dt;
			data[i] = Triple<T>(row, col, dt);
		}
	}

	~TripleList()
	{
		delete[] data;
		row = col = nums = 0;
	}

	bool IsEmpty() const { return nums == 0; }
	bool IsFull() const { return nums == maxsize; }
	void Display();
	bool Insert(const Triple<T>& src);
	bool Delete();
	void Convert();
	void FastConvert();
};

template <class T>
void TripleList<T>::Display()
{
	if (IsEmpty())return;
	std::cout << "This TripleList have " << nums << "  NUM  " << row << " * " << col << std::endl;
	for (int i = 0; i < nums; ++i)
	{
		std::cout << data[i].row << "\t" << data[i].col << "\t" << data[i].data << std::endl;
	}
}

template <class T>
bool TripleList<T>::Insert(const Triple<T>& src)
{
	if (IsFull())return false;
	if (src.row < 0 || src.col < 0 || src.col > col - 1 || src.row > row - 1)return false;
	data[nums++] = src;
	return true;
}

template <class T>
bool TripleList<T>::Delete()
{
	if (IsEmpty()) return false;
	Triple<T> temp;
	temp = data[--nums];
	return true;
}

template <class T>
void TripleList<T>::Convert()
{
	Triple<T>* dst = new Triple<T>[nums];
	static int count = 0;
	for (int i = 0; i < col; ++i)
		for (int j = 0; j < nums; ++j)
			if (data[j].col == i)
			{
				Triple<T> temp;
				temp.data = data[j].data;
				temp.col = data[j].row;
				temp.row = data[j].col;
				dst[count++] = temp;
			}
	int temp = this->row;
	row = col;
	col = temp;
	auto dt = this->data;
	this->data = dst;
	delete[] dt;
}

template <class T>
void TripleList<T>::FastConvert()
{
	Triple<T>* dst = new Triple<T>[nums];
	int* num = new int[col];
	for (int i = 0; i < col; ++i)
		num[i] = 0;
	for (int i = 0; i < nums; ++i)
		++num[data[i].col];
	int* cpot = new int[col];
	cpot[0] = 0;
	for (int i = 1; i < col; ++i)
		cpot[i] = cpot[i - 1] + num[i - 1];
	for (int i = 0; i < nums; ++i)
	{
		int p = cpot[data[i].col];
		Triple<T> temp;
		temp.data = data[i].data;
		temp.row = data[i].col;
		temp.col = data[i].row;
		dst[p] = temp;
		++cpot[data[i].col];
	}
	int temp = this->row;
	row = col;
	col = temp;
	auto dt = this->data;
	this->data = dst;
	delete[] dt;
}
