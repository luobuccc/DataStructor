/*
#include<stdio.h>
#include<timeb.h>
void main()
{
    timeb t1,t2; long t;double x,sum=1,sum1; int i,j,n;
    cout<<"请输入x，n"<<endl;
    cin>>x>>n;
    ftime(&t1);
    for(i=1;i<=n;++i){
        sum1=1;
        for(j=1;j<=i;++j){
            sum1=sum1*(-1.0/x);
        }
        sum+=sum1;
    }
    ftime(&t2);
    t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
    cout<<"sum="<<sum<<."用时"<<t<<"毫秒"<<endl;
}


#include<stdio.h>
#include<timeb.h>
void main()
{
    timeb t1,t2; long t;double x,sum=1,sum1; int i,j,n;
    cout<<"请输入x，n"<<endl;
    cin>>x>>n;
    ftime(&t1);
    for(i=1;i<=n;++i){
        sum1*=-1.0/x;
        sum+=sum1;
    }
    ftime(&t2);
    t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
    cout<<"sum="<<sum<<."用时"<<t<<"毫秒"<<endl;
}

*/
