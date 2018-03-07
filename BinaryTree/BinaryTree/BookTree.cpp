#include "BinaryTree.h"
#include <string>
#include "Book.h"
#include <iostream>

class BookBinTree  //:public BinaryTree<Book>
{
private:
	BinaryTree<Book> BT;
public:
	BookBinTree(int n)
	{
		int count = 0;
		while (n--)
		{
			std::cout << "The No " << ++count << " Book Inf:" << std::endl;
			Book book;
			BT.InsertBST(book);
		}
	}

	void PrintBookInf()
	{
		BT.PrintBST();
	}

	void SearchBook()
	{
		std::string isbn;
		std::cout << "Input the Search ISBN:" << std::endl;
		std::cin >> isbn;
		std::cout << BT.SearchBST(Book(isbn))->getData() << std::endl << std::endl;
	}

	~BookBinTree();
};
