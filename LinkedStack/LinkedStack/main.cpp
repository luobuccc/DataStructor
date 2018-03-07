#include "LinkedStack.cpp"

/*int ConvertNum(int number)
{
	LinkedStack<int> s;
	int e,num=0;
	while(number)
	{
		s.Push(number%8);
		number=number/8;
	}
	while(!s.IsEmpty())
	{
		s.Pop(e);
		num=num*10+e;
	}
	return num;
}

int main()
{
	LinkedStack<int> l;
	int num;
	num=ConvertNum(123);
	cout<<num;
	int j;
	cin>>j;
	return 0;
}*/


#include <iostream>
using namespace std;
class Rat
{
private:
	int a;
	int b;
public:
	Rat(int a1 = 1, int b2 = 1) :a(a1), b(b2) {}
	void seta(int a1);//修改对象的分子分母
	void setb(int b1);
	Rat operator +(Rat z);
	Rat operator -(Rat z);
	Rat operator *(Rat z);
	Rat operator /(Rat z);
	void yuefen(Rat&);
	friend istream& operator>>(istream&, Rat&);
	friend ostream& operator<<(ostream&, Rat&);

};
void Rat::seta(int a1)
{
	a = a1;
}
void Rat::setb(int b1)
{
	b = b1;
}
void Rat::yuefen(Rat&result)
{
	if (!result.a%result.b)
	{
		result.a = result.a / result.b;
		result.b = 1;
	}
	if (!result.b%result.a)
	{
		result.b = result.b / result.a;
		result.a = 1;
	}
}
Rat Rat::operator+(Rat z)
{
	Rat result;
	if (b != z.b&&b%z.b&&z.b%b)
	{
		result.b = b*z.b;
		result.a = a*z.b + b*z.a;
	}
	else if (b == z.b)
	{
		result.a = a + z.a;
		result.b = b;
	}
	else
	{
		if (!b%z.b)
		{
			result.b = b;
			result.a = a + z.a*b / z.b;
		}
		if (!z.b%b)
		{
			result.b = z.b;
			result.a = a*z.b / b + z.a;
		}
	}
	yuefen(result);
	return result;
}

Rat Rat::operator-(Rat z)
{
	Rat result;
	if (b == z.b)
	{
		result.a = a - z.a;
		result.b = b;
	}
	else if (b%z.b&&z.b%b)
	{
		result.b = b*z.b;
		result.a = a*z.b - b*z.a;
	}
	else
	{
		if (!b%z.b)
		{
			result.b = b;
			result.a = a - z.a*b / z.b;
		}
		if (!z.b%b)
		{
			result.b = z.b;
			result.a = a*z.b / b - z.a;
		}
	}
	yuefen(result);
	return result;
}
Rat Rat::operator *(Rat z)
{
	Rat result;
	result.a = a*z.a;
	result.b = b*z.b;
	yuefen(result);
	return result;
}
Rat Rat::operator/(Rat z)
{
	Rat result;
	result.a = a*z.b;
	result.b = b*z.a;
	yuefen(result);
	return result;
}
istream& operator>>(istream&in, Rat&z)
{
	cin >> z.a;
	if (z.a)
		cin >> z.b;
	return in;
}
ostream& operator<<(ostream&out, Rat&z)
{
	if (!z.a)
		cout << 0;
	else
		cout << z.a << "/" << z.b;
	return out;
}
int main()
{
	Rat r1, r2, r3;
	cin >> r1;
	cin >> r2;
	r3 = r1 + r2;
	cout << r3;
	system("pause");
	return 0;
}
