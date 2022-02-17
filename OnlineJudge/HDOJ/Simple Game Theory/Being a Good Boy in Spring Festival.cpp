#include<iostream>
#include<cstdio>
using namespace std;
int a[101];
int main()
{
    int k,ans;
    while(cin>>k,k)
    {
      ans=0;
      for(int i=1;i<=k;i++)
      {
        cin>>a[i];
        ans^=a[i];
      }
      int an=0;
      if(ans)
      {
        for(int i=1;i<=k;i++)
        {
          ans^=a[i];
          if(a[i]>=ans) 
            an++;
          ans^=a[i];
        }
        cout<<an<<endl;
      }
      else cout<<ans<<endl;
    }
}