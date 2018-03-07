#include<stdio.h>  
#define M 8   //����  
#define N 8     //����  
#define MaxSize    100     //ջ���Ԫ�ظ���  
int mg[M + 2][N + 2] = {      //һ���Թ���������Ҫ���Ͼ�Ϊ1�����  
	{ 1,1,1,1,1,1,1,1,1,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,0,0,1,1,0,0,1 },
	{ 1,0,1,1,1,0,0,0,0,1 },
	{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1 },
	{ 1,0,1,1,1,0,1,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1 },
	{ 1,1,1,1,1,1,1,1,1,1 }
};
struct migong {
	int i;      //·��������  
	int j;      //·��������  
	int di;     //����  
}Stack[MaxSize], Path[MaxSize];      //����ջ�ʹ�����·��������  
int top = -1;     //ջ��ָ��  
int count = 1;    //·��������  
int minlen = MaxSize;     //���·������  
void mgpath() {      //·��Ϊ:(1,1)->(M,N)  
	int i, j, di, find, k;
	top++;Stack[top].i = 1;Stack[top].j = 1;Stack[top].di = -1;
	mg[1][1] = -1;        //��ʼ����ջ  
	while (top>-1) {      //ջ����ʱѭ��  
		i = Stack[top].i;j = Stack[top].j;di = Stack[top].di;
		if (i == M && j == N) {       //�ҵ��˳��ڣ����·��  
			printf("M:  ", count++);
			for (k = 0;k <= top;k++) {
				printf("(%d,%d)  ", Stack[k].i, Stack[k].j);
				if ((k + 1) % 5 == 0)      //���ʱÿ5����㻻һ��  
					printf("\n\t");
			}
			printf("\n");
			if (top + 1<minlen) {       //�Ƚ�������·��  
				for (k = 0;k <= top;k++)
					Path[k] = Stack[k];
				minlen = top + 1;
			}
			mg[Stack[top].i][Stack[top].j] = 0;   //�ø�λ�ñ�Ϊ����·���Ŀ��߽��  
			top--;
			i = Stack[top].i;j = Stack[top].j;di = Stack[top].di;
		}
		find = 0;
		while (di<4 && find == 0) {     //����һ�����߽��  
			di++;
			switch (di) {
			case 0:i = Stack[top].i - 1;j = Stack[top].j;break;   //����  
			case 1:i = Stack[top].i;j = Stack[top].j + 1;break;   //�ұ�  
			case 2:i = Stack[top].i + 1;j = Stack[top].j;break;   //����  
			case 3:i = Stack[top].i;j = Stack[top].j - 1;break;   //���  
			}
			if (mg[i][j] == 0)
				find = 1;
		}
		if (find == 1) {      //�ҵ�����һ�����߽��  
			Stack[top].di = di;   //�޸�ԭջ��Ԫ�ص�diֵ  
			top++;      //��һ�����߽���ջ  
			Stack[top].i = i;
			Stack[top].j = j;
			Stack[top].di = -1;
			mg[i][j] = -1;        //�����ظ��ߵ��ý��  
		}
		else {
			mg[Stack[top].i][Stack[top].j] = 0;   //�ø�λ�ñ�Ϊ����·���Ŀ��߽��  
			top--;
		}
	}
	
	printf("����:  %d\n", minlen);
	printf("·��:  ");
	for (k = 0;k<minlen;k++) {
		printf("(%d,%d)  ", Path[k].i, Path[k].j);
		if ((k + 1) % 5 == 0)      //���ʱÿ5����㻻һ��  
			printf("\n\t");
	}
	printf("\n");
}
int main() {
	printf("�Թ�����·������:\n");
	mgpath();
	return 0;
}