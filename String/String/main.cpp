#include<iostream>
#include "String.h"
using std::cout;
using std::cin;
using std::endl;
int main()
{
	String s("0123456789");
	cout << s;
	String t;
	t = s(3, 3);
	cout << t;

	
	return 0;
}