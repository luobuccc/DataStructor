#include <iostream>
#include"RationalNumber.h"
using namespace std;

int main()
{
    RationalNumber r1;
    RationalNumber r2;
    cin>>r1;
    cin>>r2;
    r1.Sub(r2);
    cout<<r1;
    return 0;
}
