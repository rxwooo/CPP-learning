#include<bits/stdc++.h>
using namespace std;

template<class T>
void myswap(T& x, T& y)
{
    T temp =x;
    x=y;
    y=temp;
}

template<class T>
void show(T a[],int n)
{
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

template<class T>
void bubblesort(T a[],int n)
{
    int i=n-1;
    while(i>0)
    {
        int lastindex=0;
        for(int j=0;j<i;j++)
        {
            if(a[j+1]>a[j])
            {
                myswap(a[j+1],a[j]);
                lastindex=j;
            }
        }
        show(a,n);
        i=lastindex;
    }

}

int main()
{
    int data1[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    cout<<"before sorting :"<<endl;
    show(data1,sizeof(data1)/sizeof(int));
    cout<<endl;
    cout<<"sorting :"<<endl;
    bubblesort(data1,sizeof(data1)/sizeof(int));
    cout<<endl;
    cout<<"result :"<<endl;
    show(data1,sizeof(data1)/sizeof(int));
    return 0;
}