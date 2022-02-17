#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

char s[2010],bd[5]="zsbd";

int main()
{
    int c;
    cin>>c;
    while(c--)
    {
        int n;
        cin>>n;
        memset(s,0,sizeof(s));
        scanf("%s",s);
        getchar();
        int sz=strlen(s);
        while(sz<n)
        {
            strcpy(s+sz,bd);
            sz=strlen(s);
        }
        cout<<s<<endl;
    }
    return 0;
}