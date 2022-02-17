#include<bits/stdc++.h>
using namespace std;
char a[15], b[10];
int vis[15];
int n,num,len;
bool judge = false;

bool cmp(char a, char b)
{
    return a>b;
}
void init()
{
    len = strlen(a);
    judge = false;
    memset(vis,0,sizeof(vis));
    sort(a,a+len,cmp);
    for(int i = 0;i<len;++i){
        a[i] = a[i] -'A' + 1;
    }
}
void lnit()
{
    for(int i = 0;i<5;++i)
        b[i] = b[i]+'A'-1;
}
bool check()
{
    if(n == b[0] - b[1]*b[1] + b[2]*b[2]*b[2] - b[3]*b[3]*b[3]*b[3] + b[4]*b[4]*b[4]*b[4]*b[4]){
        judge = true;
        return true;
    }else return false;
}
void dfs(int depth)
{
    //递归边界
    if(judge) return;
    if(depth == 5) {check(); return;}
    for(int i = 0;i<len;++i){
        if(!vis[i]&&!judge){
            b[depth] = a[i];
            vis[i] = 1;
            dfs(depth+1);
            vis[i] = 0;
        }
    }
}
int main()
{
    while(cin>>n>>a&& !(n==0 && !strcmp(a,"END"))){
        init();
        dfs(0);
        lnit();
        if(judge)printf("%s\n",b);
        else printf("no solution\n");
    }
    return 0;
}