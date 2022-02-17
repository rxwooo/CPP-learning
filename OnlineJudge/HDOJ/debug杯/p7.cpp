#include <iostream>
#include <string.h>
#include<math.h>
using namespace std;

long long a[100010];
int sum=1;

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        memset(a,0,sizeof(a));
        int n,m,k;
        scanf("%d %d",&n,&m);

        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            for(int j=0;j<i;j++)
            {
                sum=((sum%m)*(abs(a[j]-a[i])%m))%m;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}