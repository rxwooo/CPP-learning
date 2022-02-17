#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;

int a[100002];

int main()
{
    int c;
    cin>>c;
    for(int z=1;z<=c;z++)
    {
        int n;
        int max=-1001;
        int bg=1,ed;
        cin>>n;
        memset(a,0,sizeof(a));
        cin>>a[1];
        max=a[1];
        for(int i=2;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=a[i-1];
            if(max<a[i]){
                max=a[i];bg=i;ed=i;
            }
            if(a[i]<0){
                a[i]=0;
                bg=i+1;
            }
            // if(a[i-1]<0&&a[i]>a[i-1]){
            //     max=a[i];bg=i;ed=i;
            // }
            // else{
            //     a[i]+=a[i-1];
            //     if(max<a[i])
            //     {
            //         max=a[i];
            //         ed=i;
            //     }
            // }
        }
        cout<<"Case "<<z<<':'<<endl;
		cout<<max<<' '<<bg<<' '<<ed<<endl;
        if(z!=c) printf("\n"); 
    }
    
}