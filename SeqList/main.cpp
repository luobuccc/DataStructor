#include <iostream>
#include"SeqList.h"
using namespace std;

int main()
{
    SeqList<int> ls(20);
    cout<<ls.Length()<<endl;
    cout<<ls.MaxSize()<<endl;
    for(int i=1;i<21;i++)
    {
        ls.Insert(i,i);
        cout<<ls.Length()<<endl;
    }

    return 0;
}
