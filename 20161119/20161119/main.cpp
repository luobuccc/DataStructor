#include <stdio.h>
#include <stdlib.h>
#include <iostream>

typedef int ElementType;
typedef struct Node* PtrToNode;

struct Node
{
	ElementType Data;
	PtrToNode Next;
};

typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);


int i, n;

List Read()
{
	std::cin >> n;
	List arze, node, pre;
	arze = (List)malloc(sizeof(List));
	arze->Next = nullptr;
	pre = arze;
	for (i = 0; i < n; i++)
	{
		node = (List)malloc(sizeof(List));
		std::cin >> node->Data;
		pre->Next = node;
		pre = node;
	}
	node->Next = nullptr;
	return arze->Next;
}


void Print(List L)
{
	if (L == nullptr)
		std::cout << "NULL\n";
	else
	{
		std::cout << L->Data;
		L = L->Next;
		while (L != nullptr)
		{
			std::cout << " " << L->Data;
			L = L->Next;
		}
		std::cout << std::endl;
	}
	return;
}

//int main()
//{
//	List L1, L2, L;
//	L1 = Read();
//	L2 = Read();
//	L = Merge(L1, L2);
//	Print(L);
//	Print(L1);
//	Print(L2);
//	system("pause");
//	return 0;
//}

List Merge(List L1, List L2)
{
	List LL1 = L1->Next;
	List LL2 = L2->Next;
	List L = (List)malloc(sizeof(struct Node));;
	L1->Next = NULL;
	L2->Next = NULL;
	List arze = NULL, pre = NULL, node = NULL;
	pre = L->Next;
	while (LL1 != NULL && LL2 != NULL)
	{
		if (&LL1->Data <= &LL2->Data)
		{
			pre = LL1;
			pre->Next = LL1->Next;
			LL1 = LL1->Next;
		}
		else
		{
			pre = LL2;
			pre->Next = LL2->Next;
			LL2 = LL2->Next;
		}
	}
	if (LL2 == NULL && LL1 != NULL)
	{
		while (LL1->Next != NULL)
		{
			pre = LL1;
			pre->Next = LL1->Next;
			LL1 = LL1->Next;
		}
	}
	if (LL1 == NULL && LL2 != NULL)
	{
		while (LL2 != NULL)
		{
			pre = LL2;
			pre->Next = LL2->Next;
			LL2 = LL2->Next;
		}
	}
	//pre->Next = NULL;
	return L;
}

class cuboid
{
private:
	double x, y, z;
	double v;
	int id;
public:
	cuboid(int id, double x, double y, double z): id(id), x(x), y(y), z(z)
	{
	}

	void display()
	{
		std::cout << this->id<< v << std::endl;
	}

	void cal()
	{
		this->v = this->x*this->y*this->z;
	}
};

int main()
{
	int n;
	std::cin >> n;
	for(int i=1;i<=n;i++)
	{
		double x, y, z;
		std::cin >>x >> y >> z;
		cuboid t1(i, x, y, z);
		t1.cal();
		t1.display();
	}
	return 0;
}
