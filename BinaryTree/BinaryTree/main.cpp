#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main()
{
	BinaryTree<char> T;
	T.CreateBST();

	T.PrintBST();
	T.PrintBSTMax();
	T.PrintBSTMin();

	//cout << T.GetParent(X);
	return 0;
}
