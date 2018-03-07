#pragma once
#include <iostream>

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode
{
private:
	T data;
	BinaryTreeNode<T> *left, *right;
public:

	BinaryTreeNode(const T& data, BinaryTreeNode<T>* left, BinaryTreeNode<T>* right): data(data), left(left), right(right)
	{
	}

	BinaryTreeNode(BinaryTreeNode<T>* left = nullptr, BinaryTreeNode<T>* right = nullptr): left(left), right(right)
	{
	}

	void Release();
	void setLeft(BinaryTreeNode<T>* val);
	void setRight(BinaryTreeNode<T>* val);
	BinaryTreeNode<T>* Copy();
};

template <class T>
void BinaryTreeNode<T>::Release()
{
	if (left)
	{
		left->Release();
		delete left;
		left = nullptr;
	}
	if (right)
	{
		right->Release();
		delete right;
		right = nullptr;
	}
}

template <class T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T>* val)
{
	if (left)
		left->Release();
	left = val;
}

template <class T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T>* val)
{
	if (right)
		right->Release();
	right = val;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::Copy()
{
	BinaryTreeNode<T> *newL, *newR;
	if (left)
		newL = left->Copy();
	else
		newL = nullptr;
	if (right)
		newR = right->Copy();
	else
		newR = nullptr;
	BinaryTreeNode<T> BT = new BinaryTreeNode<T>(data, newL, newR);
	if (BT)
		return BT;
	return nullptr;
}

template <class T>
class BinaryTree
{
public:
	BinaryTree(): root(nullptr)
	{
	}

	BinaryTree(T value, BinaryTreeNode<T>* left = nullptr, BinaryTreeNode<T>* right = nullptr)
	{
		root = new BinaryTreeNode<T>(value, left, right);
	}

	~BinaryTree();
	int Height() const { return Height(root); }
	int Size() const { return Size(root); }
	bool isEmpty() const { return root == nullptr; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { preOrder(root); }

	void Print() { Print(root); }
private:
	BinaryTreeNode<T>* root;
	void preOrder(BinaryTreeNode<T>* src);
	void inOrder(BinaryTreeNode<T>* src);
	void postOrder(BinaryTreeNode<T>* src);
	int Size(BinaryTreeNode<T>* src);
	int Height(BinaryTreeNode<T>* src);
	void Print(BinaryTreeNode<T>* src);
};

template <class T>
BinaryTree<T>::~BinaryTree()
{
	if (root)
	{
		root->Release();
		delete root;
		root = nullptr;
	}
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* src)
{
	if (src)
	{
		std::cout << src->data << std::endl;
		preOrder(src->left);
		preOrder(src->right);
	}
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* src)
{
	if (src)
	{
		inOrder(src->left);
		std::cout << src->data << std::endl;
		inOrder(src->right);
	}
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* src)
{
	if (src)
	{
		postOrder(src->left);
		postOrder(src->right);
		std::cout << src->data << std::endl;
	}
}

template <class T>
int BinaryTree<T>::Size(BinaryTreeNode<T>* src)
{
	if (!src)return 0;
	return (Size(src->left) + Size(src->right) + 1);
}

template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T>* src)
{
	int lH, rH;
	if (!src)return 0;
	lH = Height(src->left);
	rH = Height(src->right);
	return lH >= rH ? lH + 1 : rH + 1;
}

template <class T>
void BinaryTree<T>::Print(BinaryTreeNode<T>* src)
{
	if (src)
	{
		std::cout << src->data << std::endl;
		if (src->left || src->right)
		{
			std::cout << '(';
			if (src->left)
			{
				Print(src->left);
				if (src->right)
					std::cout << ',';
			}
			if (src->right)
				Print(src->right);
			std::cout << ')';
		}
		std::cout << std::endl;
	}
}
