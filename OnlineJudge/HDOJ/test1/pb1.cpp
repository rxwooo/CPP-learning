#include<algorithm>
#include<iostream>

using namespace std;

int a[1010];

bool cmp(int a,int b)
{
    return a>b;
}

int main(){
   
    int c;
    cin>>c;
    for(int i=0;i<c;i++)
    {
        int n,m;
        cin>>n>>m;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        sort(a,a+n,cmp);
        for(int j=0;j<m;j++)
        {
            printf("%d ",a[j]);
            if(j==m-1) printf("\n");
        }
    }
    return 0;
}