#pragma once
#include "Book.h"
#include <string>
class BookList
{
private:
	int maxsize;
	int length;
	Book *array;
public:

	BookList(int maxsize=30)
		: maxsize(maxsize)
	{
		length = 0;
		array = new Book[maxsize];
	}

	bool creatList(int n)
	{
		
		if (n < 1)return false;
		if(n>maxsize)
		{
			maxsize = n + 1;
			auto p = array;
			delete[] p;
			array = new Book[maxsize];
		}length = n;
		for(int i=0;i<n;++i)
		{
			std::string id;
			std::cout << "input id: ";
			std::cin >> id;
			Book book(id);
			int mark = 0;
			for(int j=0;j<i;++j)
			{
				if (id > array[j].id)
					mark = j;
			}
			for (int j = i;j < mark;++j)
				array[j + 1] = array[j];
			array[mark] = book;
			
		}
		return true;
	}

	void print()
	{
		
		for(int i=0;i<length;++i)
		{
			std::cout << array[i].id << std::endl;
		}
	}
};
