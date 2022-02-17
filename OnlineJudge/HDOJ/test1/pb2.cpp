#include<algorithm>
#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    int c;
    scanf("%d",&c);
    getchar();
    for(int i=0;i<c;i++){
        char s[1000];
        int count=0;
        scanf("%s",s);
        getchar();
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]>='A'&&s[i]<='Z') s[i]+='a'-'A';
        }
        printf("%s\n",s);
    }
    return 0;
}