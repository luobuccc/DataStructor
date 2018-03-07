#pragma once
#include <string.h>

const int DEFAULTSIZE = 20;

class String
{
private:
	int maxSize;
	int curLength;
	char* array;
public:
	String(int size = 20): maxSize(size)
	{
		curLength = 0;
		array = new char[size + 1];
		array[0] = '\0';
	}

	String(const String& src)
	{
		maxSize = src.maxSize;
		curLength = src.curLength;
		array = new char[maxSize + 1];
		strcpy(array, src.array);
	}

	String(const char* src)
	{
		curLength = strlen(src);
		maxSize = DEFAULTSIZE;
		array = new char[maxSize + 1];
		strcpy(array, src);
	}

	String& operator=(String& src)
	{
		if (maxSize < src.maxSize)
		{
			maxSize = src.maxSize;
			array = new char[maxSize + 1];
		}
		curLength = src.curLength;
		strcpy(array, src.array);
		return *this;
	}

	String operator()(int pos, int len) const
	{
		String temp;
		if (pos < 1 || len < 0 || pos + len - 1 > maxSize) { return temp; }
		else
		{
			if (pos + len - 1 > curLength)
				len = curLength - pos + 1;
			temp.curLength = len;
			int i, j;
			for (i = 0 , j = pos - 1; i < len; ++i , ++j)
				temp.array[i] = array[j];
			temp.array[i] = '\0';
		}
		return temp;
	}

	String& operator+=(const String& src)
	{
		char* temp = array;
		int len = curLength + src.curLength;
		if (len > maxSize)
		{
			maxSize = len;
			array = new char[maxSize + 1];
			strcpy(array, temp);
			delete[] temp;
		}
		curLength = len;
		strcat(array, src.array);
		return *this;
	}

	char& operator[](unsigned i) const
	{
		char non = 0;
		if (i < curLength)return array[i - 1];
		else
			return non;
	}

	bool Insert(int k, const char* src)
	{
		int len = strlen(src);
		if (k < 0 || k > curLength + 1)return false;
		if ((curLength + len) > maxSize)
		{
			char* temp = array;
			int le = maxSize + 2 * len;
			array = new char[le];
			strcpy(array, temp);
			delete[] temp;
		}
		for (int i = curLength - 1; i >= k - 1; --k)array[i + len] = array[i];
		for (int i = k - 1, j = 0; j < len; ++j , ++k)
			array[k] = src[j];
		curLength += len;
		array[curLength] = '\0';
		return true;
	}

	bool Delete(int i, int len) //............................
	{
		String sub;
		if (curLength == 0)return false;
		if (i < 1 || i > curLength)return false;
		if ((i + len - 1) > curLength)
		{
			int k, j;
			for (k = 0 , j = i - 1; j < curLength; ++j , ++k)
				sub.array[k] = array[j];
			curLength = i - 1;
			sub.curLength = k;
			sub.array[k] = '\0';
		}
		else
		{
			int k, j = 0;
			for (k = i + len - 1; k < curLength; ++k)
			{
				sub.array[j++] = array[k - len];
				array[k - len] = array[k];
			}
			sub.curLength = j;
			curLength = curLength - len;
			sub.array[j] = '\0';
		}
		array[curLength] = '\0';
		return true;
	}

	friend std::istream& operator>>(std::istream& in, String& src)
	{
		char str[DEFAULTSIZE];
		in.getline(str, DEFAULTSIZE);
		src.curLength = strlen(str);
		strcpy(src.array, str);
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const String& src)
	{
		if (src.curLength == 0)out << "Empty!";
		else out << src.array;
		out << std::endl;
		return out;
	}

	int BFMatch(const String& src, int k) const
	{
		int j;
		for (int i = 0; i < curLength - src.curLength; ++i)
		{
			for (j = 0; i < src.curLength; ++j)
			{
				if (array[i + j] != src.array[j])
					break;
			}
			if (j == src.curLength)return i + 1;
		}
		return 0;
	}

	void getNext(int next[]);

	int KMPMatch(const String& src, int k) const
	{
		const int len = curLength;
		int posP = 0, posT = k - 1;
		int lengthP = src.curLength;
		int lengthT = curLength;
		//constexpr int next[len] = {0};

		//src.getNext(next);
		while (posP < lengthP && posT < lengthT)
		{
			if (posP == -1 || array[posT] == src.array[posP])
			{
				++posP;
				++posT;
			}
			//else
				//posP = next[posP];
		}
		if (posP < lengthP)return -1;
		else return (posT - lengthT + 1);
	}
};


/*
 void compute_overlay(const string& pattern)
{
    const int pattern_length = curLength;
    int *overlay_function = new int[pattern_length];
    int index=0;
    overlay_function[0] = -1;

    for(int i=1;i<pattern_length;++i)
    {
        index = overlay_function[i-1];            of[0]=-1
        //store previous fail position k to index;
        // a b a a b c a b a  ....................................//i=1  index=-1   pattern[1]!=0    of[1]=-1
		   0 1 2 3 4 5 6 7 8										i=2  index=-1   pattern[2]==0    of[2]=0
																	i=3  index=0    pattern[3]==1
        while(index>=0 && pattern[i]!=pattern[index+1])
        {
            index = overlay_function[index];
        }

        if(pattern[i]==pattern[index+1])
        {
            overlay_function[i] = index + 1;  
        }

        else
        {
            overlay_function[i] = -1;
        }
    }


    for(i=0;i<pattern_length;++i)
    {
        cout<<overlay_function[i]<<endl;
    }


    delete[] overlay_function;
}

 */
