#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H
#include<iostream>
using namespace std;

class RationalNumber
{
    public:
        RationalNumber(int x,int y);
        RationalNumber();
        ~RationalNumber();
        int Getnumerator();
        int Getdenominator();
        void Updatenumerator(int x);
        void Updatedenominator(int x);
        RationalNumber operator + (const RationalNumber &src);
        RationalNumber operator - (const RationalNumber &src);
        RationalNumber operator * (const RationalNumber &src);
        RationalNumber operator / (const RationalNumber &src);
        void Add(const RationalNumber &src);
        void Sub(const RationalNumber &src);
        void Mult(const RationalNumber &src);
        void Div(const RationalNumber &src);
        friend istream& operator>>(istream &is,RationalNumber &src);
        friend ostream& operator<<(ostream &os,const RationalNumber &src);
    protected:
    private:
        int numerator,denominator;
};

istream& operator>>(istream &is,RationalNumber &src);
ostream& operator<<(istream &os,const RationalNumber &src);

#endif // RATIONALNUMBER_H
