#include<stdio.h>
#include<cstring>
int main()
{
    char s[10000];     //考虑到大数，使用char数组
    while(scanf("%s",s)&&s[0]!='0'){
        getchar();
        int sum=0;
        for(int i=0;i<strlen(s);i++)
            sum+=s[i]-'0';
            printf("%d\n",(sum-1)%9+1);
    }
    return 0;
}