#pragma once
#include <string>
#include <iostream>
class Book
{
private:
	std::string id;
public:

	Book()
	{
	}

	Book(const std::string& id)
		: id(id)
	{
	}

	 void print() const
	{
		std::cout << id << std::endl;
	}

	 friend class BookList;
};
