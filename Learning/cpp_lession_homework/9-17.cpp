#include<bits/stdc++.h>
using namespace std;

template<class T>
int seqsearch(const T list[],int n, const T& key)
{
    for(int i=0;i<n;i++)
    {
        if(list[i]==key) return i;
    }
    return -1;
}


int main()
{
    int data1[]={1,3,5,7,9,11,13,15,17,19,2,4,6,8,10,12,14,16,18,20};
    int n;
    int pos;
    cout<<"please input the number you want to search :";
    cin>>n;
    pos=seqsearch(data1 ,sizeof(data1)/sizeof(int) , n );
    if(pos!=-1)
        cout<<"the first position of "<<n<<" is "<<pos<<endl;
    else
        cout<<"not find"<<endl;
    return 0;
}