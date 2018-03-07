#include<stdio.h>  
#include "LinkedStack.h"


#define H_NUM 10 //迷宫行数  
#define V_NUM 10 //迷宫列数  

int maze[H_NUM][V_NUM] = {
	//     0  1  2  3  4  5  6  7  8  9  
	/*0*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,
	/*1*/ -1,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,-1,
	/*2*/ -1,0 ,-1,-1,-1,-1,-1,-1,0 ,-1,
	/*3*/ -1,0 ,-1,-1,-1,-1,-1,-1,0 ,-1,
	/*4*/ -1,0 ,-1,-1,-1,-1,-1,-1,0 ,-1,
	/*5*/ -1,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,-1,
	/*6*/ -1,0 ,-1,-1,-1,-1,-1,-1,0 ,-1,
	/*7*/ -1,0 ,-1,-1,-1,-1,-1,-1,0 ,-1,
	/*8*/ -1,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,-1,
	/*9*/ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1
};


#include <iostream>
#include <stack>

using namespace std;

typedef int MAZE[100][100];
typedef struct {
	int x, y;
} PostType;
typedef struct {
	int ord;
	int di;
	PostType seat;
} SElemType;


int direction[4][2] = { { 0,1 },{ 1,0 },{ 0,-1 },{ -1,0 } };

typedef stack<SElemType> WAY;

int main()
{

	PostType start, end;
	start.x = 1;
	start.y = 1;
	end.x = 8;
	end.y = 5;
	stack<WAY> ways;
	void mazePath(PostType start, PostType end, stack<WAY> & ways);
	mazePath(start, end, ways);
	int x = ways.size();
	cout << x << endl;

	stack<SElemType> temp;
	SElemType tem;
	while (!ways.empty())
	{
		cout << "number " << ways.size() << " way" << endl;
		temp = ways.top();
		tem = temp.top();
		cout << "number " << tem.ord + 1 << " step: (" << end.x << " , " << end.y << ")" << endl;
		while (!temp.empty())
		{

			tem = temp.top();
			cout << "number " << tem.ord << " step: (" << tem.seat.x << " , " << tem.seat.y << ")" << endl;
			temp.pop();
		}
		cout << "number " << 1 << " step: (" << start.x << " , " << start.y << ")" << endl;
		cout << endl << endl << endl;
		ways.pop();
	}



}

void mazePath(PostType start, PostType end, stack<WAY> & ways)
{
	bool judge = false;
	bool judge1 = false;
	int i, j, k, g, h, curstep = 1;
	PostType curpos;
	SElemType element, temp;
	stack<SElemType> s, Temp;
	maze[start.x][start.y] = 2;
	curpos = start;
	element.ord = curstep;
	element.di = -1;
	element.seat = curpos;
	s.push(element);
	while (!(s.empty()))
	{
		if (judge)
		{
			judge = false;
			//temp = s.top();
			maze[s.top().seat.x][s.top().seat.y] = 0;
			k = s.top().di + 1;
			s.pop();
			element = s.top();
			s.pop();
			judge1 = true;
			i = element.seat.x;
			j = element.seat.y;
			curstep = element.ord;
		}
		else {
			element = s.top();
			maze[s.top().seat.x][s.top().seat.y] = 0;
			s.pop();
			judge1 = true;
			i = element.seat.x;
			j = element.seat.y;
			curstep = element.ord;
			k = element.di + 1;
		}


		while (k < 4)
		{
			g = i + direction[k][0];
			h = j + direction[k][1];
			if (g == end.x && h == end.y && maze[g][h] == 0)
			{
				judge = true;
				ways.push(s);
				k++;
				break;

			}
			if (maze[g][h] == 0)
			{
				
				maze[g][h] = 2;
				curstep++;
				element.ord = curstep;
				element.seat.x = g;
				element.seat.y = h;
				element.di = k;
				s.push(element);
				i = g;
				j = h;
				k = 0;
			}
			else {
				k++;
			}
		}

	}
}





