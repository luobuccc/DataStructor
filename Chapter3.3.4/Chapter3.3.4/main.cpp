#include <iostream>
#include "LinkedStack.h"
using namespace std;
int Max0(const int* src, int length);
int Max1(const int* src, int length);
int Max2(const int* src, int begin, int end);
void Convert(int val, int k);

int main()
{
	/*
	int A[10] = {1000,2,6,23,50000,45,8,89,107,0};
	cout << Max0(A, 10) << endl;
	cout << Max1(A, 10) << endl;
	cout << Max2(A, 0, 9) << endl;
	*/
	Convert(208, 16);

	return 0;
}


int Max0(const int* src, int length)
{
	int max = src[0], i = 1;
	while (i < length)
	{
		int temp = src[i];
		if (temp >= max) max = temp;
		++i;
	}
	return max;
}

int Max1(const int* src, int length)
{
	if (length == 1) return src[0];
	int temp = Max1(src, length - 1);
	return temp >= src[length] ? temp : src[length];
}

int Max2(const int* src, int begin, int end)
{
	if (end == begin)return src[end];
	int mid = (begin + end) / 2;
	int t1 = Max2(src, begin, mid);
	int t2 = Max2(src, mid + 1, end);
	return (t1 >= t2) ? t1 : t2;
}

void Convert(int val, int k)
{
	LinkedStack<int> S;
	while(val)
	{
		S.Push(val%k);
		val /= k;
	}
	int i = 0;
	while(!S.IsEmpty())
	{
		char temp=0;
		int x=0;
		S.Pop(x);
		if (x >= 0 && x <= 9) temp = x+'0';
		else temp = x + 'A'-10;
		++i;
		cout << temp;
	}
	cout << endl;
}
