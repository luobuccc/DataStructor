#pragma once

#include <iostream>
#include <string>
template <class T>
class HFTree;

template <class T>
class HFNode
{
private:
	T data;
	int weight, left, right, parent;
public:
	HFNode(int weight = 0, int left = 0, int right = 0, int parent = 0) :
		weight(weight), left(left), right(right), parent(parent)
	{
	}

	HFNode(T item, int weight = 0, int left = 0, int right = 0, int parent = 0) :
		data(item), weight(weight), left(left), right(right), parent(parent)
	{
	}

	friend class HFTree<T>;
};

//typedef char** HC;

template <class T>
class HFTree
{
private:
	HFNode<T>* hf;
	int size, maxsize;
	int min(int i) const;
	void select(int k, int& s1, int& s2) const;

public:
	HFTree(int size = 100);
	~HFTree() { delete[] hf; }
	void creatTree(T* d, unsigned* w, int n);
	void print();
	void Hcoding(int n);
};

template <class T>
int HFTree<T>::min(int i) const
{
	int flag;
	int max = INT16_MAX;
	for (int j = 1; j <= i; ++j)
		if (hf[j].weight < max && hf[j].parent == 0)
		{
			flag = j;
			max = hf[j].weight;
		}
	hf[flag].parent = 1;
	return flag;
}

template <class T>
void HFTree<T>::select(int k, int& s1, int& s2) const
{
	s1 = min(k);
	s2 = min(k);
}

template <class T>
HFTree<T>::HFTree(int siz)
{
	maxsize = siz;
	size = 0;
	hf = new HFNode<T>[siz];
}

template <class T>
void HFTree<T>::creatTree(T* d, unsigned* w, int n)
{
	if (n < 0)return;
	int m = 2 * n - 1;
	auto p = hf;
	delete[] p;
	hf = new HFNode<T>[m + 1];
	size = m;
	HFNode<T>* ptr;
	int i;
	for (ptr = hf , i = 1; i <= n + 1; ++i , ++ptr , ++w , ++d)
	{
		ptr->data = *d;
		ptr->weight = *w;
	}
	int s1, s2;

	for (i = n + 1; i <= m; ++i)
	{
		select(i - 1, s1, s2);
		hf[s1].parent = i;
		hf[s2].parent = i;
		hf[i].left = s1;
		hf[i].right = s2;
		hf[i].weight = hf[s1].weight + hf[s2].weight;
	}
}

template <class T>
void HFTree<T>::print()
{
	std::cout << 'i' << ":" << "data" << "  " << " weight" << "  " << " left" << "  " << " right" << "  " << " parent" << std::endl;
	for (int i = 1; i <= size; ++i)
	{
		std::cout << i << ":" << hf[i].data << " " << hf[i].weight << " " << hf[i].left << " " << hf[i].right << " " << hf[i].parent << std::endl;
	}
}

template <class T>
void HFTree<T>::Hcoding(int n)
{
	//typedef char** HC;
	std::cout << "The result HFCoding is" << std::endl;
	char* cd = new char[n];
	cd[n - 1] = '\0';
	auto HC = new char* [n + 1];
	for (int i = 1; i <= n; ++i)
	{
		int start = n - 1;
		std::string s;
		for (int c = i, f = hf[i].parent; f != 0; c = f , f = hf[f].parent)
		{
			if (hf[f].left == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		HC[i] = new char[n - start];

		//char *r = new char[n - start];
		// ReSharper disable once CppDeprecatedEntity
		strcpy(HC[i], &cd[start]);
	}
	for (int i = 1; i <= n; ++i)
	{
		std::cout << hf[i].data << ": " << HC[i] << std::endl;
	}
}
