#include <iostream>
#include <string.h>
using namespace std;

char s[35];

int main()
{
    int c;
    cin>>c;
    getchar();
    while(c--)
    {
        memset(s,0,sizeof(0));
        int ze=0;
        for(int i=0;;i++)
        {
            s[i]=getchar();
            if(s[i]=='\n')
            {
                s[i]='\0';
                break;
            }
            if(s[i]=='9'){
                ze++;
            }
        }

        int flag=0;
        int sz=strlen(s);
        if(sz>19)
        {
            flag=1;
        }
        if(flag==0)
        {
            if(ze==sz) printf("1");
            while(s[sz-1]=='9')
            {
                s[sz-1]='0';
                sz--;
            }
            s[sz-1]+=1;
            printf("%s\n",s);
        }
        else{
            printf( "Zhang San will never have girlfriend!\n");
        }
    }
    return 0;
}