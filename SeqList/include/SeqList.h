#ifndef SEQLIST_H
#define SEQLIST_H

#include<iostream>

template<class T>
class SeqList
{
    public:
            //SeqList()=default;
            SeqList(int size=20);
            ~SeqList();
            SeqList(const SeqList& src);
            bool Insert(int k,const T &src);
            int Length(){return length;}
            int MaxSize(){return maxsize;}
    private:
            T *elements;
            int maxsize;
            int length;

};


template<class T>
SeqList<T>::~SeqList()
{

}


template<class T>
SeqList<T>::SeqList(int size)
{
    maxsize=size;
    length=0;
    elements=new T[size];
}

template<class T>
SeqList<T>::SeqList(const SeqList& src)
{
    maxsize=src.maxsize;
    length=src.length;
    elements=new T[maxsize];
    for(int i=0;i<length;++i)
        elements[i]=src.elements[i];
}

template<class T>
bool SeqList<T>::Insert(int k,const T &src)
{
    if(length==maxsize)
    {
        std::cout<<"Error OverFlow"<<std::endl;
        return false;
    }
    if(k<1||k>length+1)
    {
        std::cout<<"List Full"<<std::endl;
        return false;
    }
    for(int i=length-1;i>=k-1;--i)
        elements[i+1]=elements[i];
    elements[k-1]=src;
    ++length;
    return true;
}




#endif // SEQLIST_H
