#pragma once
#include "Queue.h"

template <class T>
class BinaryTree;

template <class T>
class BinaryTreeNode
{
private:
	T data;
	BinaryTreeNode<T> *left, *right;
public:
	BinaryTreeNode(T data, BinaryTreeNode<T>* lptr = nullptr, BinaryTreeNode<T>* rptr = nullptr): data(data), left(lptr), right(rptr)
	{
	}

	BinaryTreeNode(BinaryTreeNode<T>* lptr = nullptr, BinaryTreeNode<T>* rptr = nullptr) : left(lptr), right(rptr)
	{
	}

	BinaryTreeNode<T>* Copy();

	static void printData(BinaryTreeNode<T>* src)
	{
		std::cout << src->data << std::endl;
	}

	void SetLeft(const BinaryTreeNode<T>* ptr);
	void SetRight(const BinaryTreeNode<T>* ptr);
	void Release();
	bool operator==(const BinaryTreeNode<T>* src);
	friend class BinaryTree<T>;
};

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::Copy()
{
	BinaryTreeNode<T> *newL, *newR;
	if (left)
		newL = left->Copy();
	else newL = nullptr;
	if (right)
		newR = right->Copy();
	else newR = nullptr;
	BinaryTreeNode<T>* newT = new BinaryTreeNode<T>(data, newL, newR);
	if (newT)return newT;
	else return nullptr;
}

template <class T>
void BinaryTreeNode<T>::SetLeft(const BinaryTreeNode<T>* ptr)
{
	if (left)
		left->Release();
	left = ptr;
}

template <class T>
void BinaryTreeNode<T>::SetRight(const BinaryTreeNode<T>* ptr)
{
	if (right)
		right->Release();
	right = ptr;
}

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
bool BinaryTreeNode<T>::operator==(const BinaryTreeNode<T>* src)
{
	if (src->data == data)
		return true;
	else
		return false;
}

template <class T>
class BinaryTree
{
private:
	BinaryTreeNode<T>* root;
	int SizeFull(BinaryTreeNode<T>* ptr) const;
	int Size1(BinaryTreeNode<T>* ptr) const;
	int Height(BinaryTreeNode<T>* ptr) const;
	void preOrder(BinaryTreeNode<T>* ptr);
	void inOrder(BinaryTreeNode<T>* ptr);
	void postOrder(BinaryTreeNode<T>* ptr);
	void Traverse(BinaryTreeNode<T>* ptr);
	void Create(BinaryTreeNode<T>*& ptr);
	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* cur, BinaryTreeNode<T>* pat);
	char RefValue = '#';

public:

	BinaryTree(): root(nullptr)
	{
	}

	BinaryTree(T item, BinaryTreeNode<T>* lT = nullptr, BinaryTreeNode<T>* rT = nullptr)
	{
		root = new BinaryTreeNode<T>(item, lT, rT);
	}

	~BinaryTree()
	{
		root->Release();
		delete root;
		root = nullptr;
	}

	BinaryTreeNode<T>* GetParent(BinaryTreeNode<T>* pat)
	{
		return GetParent(root, pat);
	};

	void PrintBST()
	{
		std::cout << "BST:" << std::endl;
		inOrder(root);
		std::cout << std::endl;
	}

	void Display()
	{
		Traverse(root);
		std::cout << std::endl;
	}

	BinaryTreeNode<T>* GetRoot() { return root; }
	BinaryTreeNode<T>* GetParent1(BinaryTreeNode<T>* src);
	BinaryTreeNode<T>* BST_Min(BinaryTreeNode<T>* val) const;
	BinaryTreeNode<T>* BST_Max(BinaryTreeNode<T>* val) const;
	bool isEmpty() const { return root == nullptr; }
	void InsertBST(T val);
	void CreateBST();
	void RemoveBST(const T val, BinaryTreeNode<T>* & ptr);
	void PrintBSTMin() const;
	void PrintBSTMax() const;
	void preOrder() { preOrder(root); };
	void inOrder() { inOrder(root); };
	void postOrder() { postOrder(root); };
	void levelOrder() const;
	void Create() { Create(root); };
	int SizeFull() { return SizeFull(root); }
	int Size1() { return Size1(root); }
	int Height() { return Height(root); }
};

template <class T>
int BinaryTree<T>::SizeFull(BinaryTreeNode<T>* ptr) const
{
	if (!ptr)return 0;
	return (SizeFull(ptr->left) + SizeFull(ptr->right) + 1);
}

template <class T>
int BinaryTree<T>::Size1(BinaryTreeNode<T>* ptr) const
{
	if (!ptr)return 0;
	if ((ptr->left && !ptr->right) || (!ptr->left && ptr->right))return 1 + (Size1(ptr->left) + Size1(ptr->right));
	return (Size1(ptr->left) + Size1(ptr->right));
}

template <class T>
int BinaryTree<T>::Height(BinaryTreeNode<T>* ptr) const
{
	if (!ptr)return 0;
	int lH = Height(ptr->left);
	int rH = Height(ptr->right);
	return (lH >= rH) ? lH + 1 : rH + 1;
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* ptr)
{
	if (ptr)
	{
		std::cout << ptr->data << "--->";
		preOrder(ptr->left);
		preOrder(ptr->right);
	}
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* ptr)
{
	if (ptr)
	{
		inOrder(ptr->left);
		std::cout << ptr->data << "--->";
		inOrder(ptr->right);
	}
}

template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T>* ptr)
{
	if (ptr)
	{
		postOrder(ptr->left);
		postOrder(ptr->right);
		std::cout << ptr->data << "--->";
	}
}

template <class T>
void BinaryTree<T>::Traverse(BinaryTreeNode<T>* ptr)
{
	if (ptr)
	{
		std::cout << ptr->data;
		if (ptr->left || ptr->right)
		{
			std::cout << '(';
			if (ptr->left)
			{
				Traverse(ptr->left);
				if (ptr->right)
					std::cout << ',';
			}
			if (ptr->right)
				Traverse(ptr->right);
			std::cout << ')';
		}
	}
}

template <class T>
void BinaryTree<T>::Create(BinaryTreeNode<T>* & ptr)
{
	T ch;
	std::cin >> ch;
	if (ch != RefValue)
	{
		ptr = new BinaryTreeNode<T>(ch);
		if (ptr)
		{
			Create(ptr->left);
			Create(ptr->right);
		}
	}
	else ptr = nullptr;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent(BinaryTreeNode<T>* cur, BinaryTreeNode<T>* src)
{
	if (!cur)return nullptr;
	if (cur->left == src || cur->right == src)//operator == ?
		return cur;
	BinaryTreeNode<T>* ptr;
	if ((ptr = GetParent(cur->left, src)) != nullptr)
		return ptr;
	else
		return GetParent(cur->right, src);
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::BST_Min(BinaryTreeNode<T>* val) const
{
	BinaryTreeNode<T>* current = val;
	BinaryTreeNode<T>* p = nullptr;
	while (current)
	{
		p = current;
		current = current->left;
	}
	return p;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::BST_Max(BinaryTreeNode<T>* val) const
{
	BinaryTreeNode<T>* current = val;
	BinaryTreeNode<T>* p = nullptr;
	while (current)
	{
		p = current;
		current = current->right;
	}
	return p;
}

template <class T>
void BinaryTree<T>::InsertBST(T val)
{
	BinaryTreeNode<T>* s = new BinaryTreeNode<T>(val);

	if (root == nullptr)
	{
		root = s;
		return;
	}

	BinaryTreeNode<T>* current = root;
	BinaryTreeNode<T>* p = nullptr;

	while (current)
	{
		p = current;
		if (current->data > val)
			current = current->left;
		else
		{
			if (current->data < val)current = current->right;
			else
				return;
		}
	}
	if (val < p->data)p->left = s;
	else { p->right = s; }
}

template <class T>
void BinaryTree<T>::CreateBST()
{
	T key;
	std::cin >> key;
	while (key != RefValue)
	{
		InsertBST(key);
		std::cin >> key;
	}
	//for (int i = 0; i < 9; ++i)
	//{
	//std::cin >> key;
	//InsertBST(key);
	//}
}

template <class T>
void BinaryTree<T>::RemoveBST(const T val, BinaryTreeNode<T>*& ptr)
{
	if (ptr != nullptr)
	{
		if (val < ptr->data)RemoveBST(val, ptr->left);
		else
		{
			if (val > ptr->data)RemoveBST(val, ptr->right);
			else
			{
				if (ptr->left || ptr->right)
				{
					BinaryTreeNode<T>* temp = BST_Min(ptr->right);
					ptr->data = temp->data;
					RemoveBST(ptr->data, temp);
				}
				else
				{
					if (ptr->left == nullptr)ptr = ptr->right;
					else { ptr = ptr->left; }
				}
			}
		}
	}
}

template <class T>
void BinaryTree<T>::PrintBSTMin() const
{
	std::cout << "The BST_Min:" << BST_Min(root)->data << std::endl;
}

template <class T>
void BinaryTree<T>::PrintBSTMax() const
{
	std::cout << "The BST_Max:" << BST_Max(root)->data << std::endl;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::GetParent1(BinaryTreeNode<T>* src)
{
	if (src == root)return nullptr;
	LinkedQueue<BinaryTreeNode<T>*> Q;
	BinaryTreeNode<T>* ptr = root;
	Q.EnQueue(ptr);
	while (!Q.IsEmpty())
	{
		Q.DeQueue(ptr);
		if (ptr->left == src || ptr->right == src)
		{
			return ptr;
		}
		if (src->left)
			Q.EnQueue(ptr->left);
		if (src->right)
			Q.EnQueue(ptr->right);
	}
	return nullptr;
}

template <class T>
void BinaryTree<T>::levelOrder() const
{
	LinkedQueue<BinaryTreeNode<T>*> Q;

	BinaryTreeNode<T>* ptr = root;
	if (!root)
	{
	}
	Q.EnQueue(ptr);
	while (!Q.IsEmpty())
	{
		Q.DeQueue(ptr);
		std::cout << ptr->data << " ";
		if (ptr->left)
			Q.EnQueue(ptr->left);
		if (ptr->right)
			Q.EnQueue(ptr->right);
	}
}
