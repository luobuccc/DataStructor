#include <iostream>
#include <cstdio>
#include<stack>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		stack<int> S;
		int t;
		cin >> t;
		int a = 0, p;
		for (int i = 0; i < t; ++i)
		{//±éÀú
			cin >> p;
			for (int i = 0; i < p - a; i++)//
				S.push(-1);
			if (S.top() == -1)
			{
				i == 0 ? cout << "1" : cout << " 1";
				S.pop();
				S.push(1);
			}
			else
			{
				int top = S.top();
				S.pop();
				while (S.top() != -1)
				{
					top += S.top();
					S.pop();
				}
				cout << " " << top + 1;
				S.pop();
				S.push(top + 1);
			}
			a = p;
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}
