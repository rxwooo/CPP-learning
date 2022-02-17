#include<bits/stdc++.h>
using namespace std;

int nn[10];

int sub(int n[],int bg ,int ed)
{
    int left,right,mid;
    int center;
    center = ( ed + bg ) / 2;

    if(ed-bg==0) 
        if(n[bg]>0) return n[bg];
        else return 0;

    left=sub(n,bg,center);
    right=sub(n,center+1,ed); 

    //mid
    int ml=0xc0c0c0c0,mr=0xc0c0c0c0,sum=0;
    for(int i = center; i >= bg; i--)
    {
        sum+=n[i];
        if(sum>ml) 
            ml=sum;
    }
    sum=0;
    for(int i = center+1; i<=ed; i++)
    {
        sum+=n[i];
        if(sum>mr) 
            mr=sum;
    }
    mid=mr+ml;

    int max=0xc0c0c0c0;
    if( left > max ) max = left;
    if( right > max ) max = right;
    if( mid > max ) max = mid;

    return max;
}
//4 -3 5 -2 -1 2 6 -2

int main()
{
    int num;
    int count=0;
    while(cin>>num) nn[count++]=num;
    num=sub(nn,0,count-1);
    cout<<num<<endl;
    return 0;
}