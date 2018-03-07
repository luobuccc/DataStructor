#include "RationalNumber.h"

int gcd(int a, int b)
{
        if(!b) return a;
        else  return gcd(b, a%b );
}

RationalNumber::RationalNumber(int x,int y):numerator(x),denominator(y)
{

}

RationalNumber::~RationalNumber()
{
    //dtor
}

RationalNumber::RationalNumber()
{
    numerator=0;
    denominator=1;
    //dtor
}

int RationalNumber::Getnumerator()
{
    return numerator;
}

int RationalNumber::Getdenominator()
{
    return denominator;
}

void RationalNumber::Updatenumerator(int x)
{
    numerator=x;
}

void RationalNumber::Updatedenominator(int x)
{
    denominator=x;
}

RationalNumber RationalNumber::operator+(const RationalNumber &src)
{
    RationalNumber result;
    result.numerator=numerator*src.denominator+src.numerator*denominator;
    result.denominator=denominator*src.denominator;
    return result;
}

RationalNumber RationalNumber::operator-(const RationalNumber &src)
{
    RationalNumber result;
    result.numerator=numerator*src.denominator-src.numerator*denominator;
    result.denominator=denominator*src.denominator;
    return result;
}

RationalNumber RationalNumber::operator*(const RationalNumber &src)
{
    RationalNumber result;
    result.numerator=numerator*src.numerator;
    result.denominator=denominator*src.denominator;
    return result;
}

RationalNumber RationalNumber::operator/(const RationalNumber &src)
{
    RationalNumber result;
    if(src.denominator==0||src.numerator==0)
    {
        std::cout<<"Error!";
        return *this;
    }
    result.numerator=numerator*src.denominator;
    result.denominator=denominator*src.numerator;
    return result;
}

void RationalNumber::Add(const RationalNumber &src)
{
    numerator=numerator*src.denominator+src.numerator*denominator;
    denominator=denominator*src.denominator;
}

void RationalNumber::Mult(const RationalNumber &src)
{
    numerator*=src.numerator;
    denominator*=src.denominator;
}

void RationalNumber::Div(const RationalNumber &src)
{
    if(src.denominator==0||src.numerator==0)
    {
        std::cout<<"Error!";
    }
    numerator*=src.denominator;
    denominator*=src.numerator;
}

void RationalNumber::Sub(const RationalNumber &src)
{
    numerator=numerator*src.denominator-src.numerator*denominator;
    denominator=denominator*src.denominator;
}


istream& operator>>(istream &is,RationalNumber &src)
{
    cout<<"please input numerator:";
    is>>src.numerator;
    lop:
    cout<<"please input denominator:";
    int temp;
    is>>temp;
    if(temp==0)
       {
        cout<<"Error!\n";
        goto lop;}
    else
    src.denominator=temp;
    return is;
}

ostream& operator<<(ostream &os,const RationalNumber &src)
{
    if(src.numerator==0)
        os<<0<<endl;
    else
    {
    int cm = gcd(src.numerator,src.denominator);
    int x=src.numerator/cm;
    int y=src.denominator/cm;
    os<<x<<"/"<<y<<endl;
    }
    return os;
}
