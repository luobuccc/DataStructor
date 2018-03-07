#pragma once
#include <string>
#include <ostream>

class Book
{
private:
	std::string ISBN;
	std::string bookName;
	std::string author;
	int num;
	float price;

public:

	Book(const std::string& isbn = nullptr, const std::string& book_name = nullptr, const std::string& author = nullptr, int num = 0, float price = 0.0):
		ISBN(isbn), bookName(book_name), author(author), num(num), price(price)
	{
	}


	~Book() = default;

	friend std::ostream& operator<<(std::ostream& os, const Book& obj)
	{
		return os
			<< "ISBN: " << obj.ISBN
			<< " bookName: " << obj.bookName
			<< " author: " << obj.author
			<< " num: " << obj.num
			<< " price: " << obj.price;
	}

	friend bool operator==(const Book& lhs, const Book& rhs)
	{
		return lhs.ISBN == rhs.ISBN
			&& lhs.bookName == rhs.bookName
			&& lhs.author == rhs.author
			&& lhs.num == rhs.num
			&& lhs.price == rhs.price;
	}

	friend bool operator!=(const Book& lhs, const Book& rhs)
	{
		return !(lhs == rhs);
	}

	friend bool operator<(const Book& lhs, const Book& rhs)
	{
		return lhs.ISBN < rhs.ISBN;
	}

	friend bool operator<=(const Book& lhs, const Book& rhs)
	{
		return !(rhs < lhs);
	}

	friend bool operator>(const Book& lhs, const Book& rhs)
	{
		return rhs < lhs;
	}

	friend bool operator>=(const Book& lhs, const Book& rhs)
	{
		return !(lhs < rhs);
	}
};
