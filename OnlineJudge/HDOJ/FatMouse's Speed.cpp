#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

struct mice{
    int sp;
    int we;
    int num;
    char s[2002]={'\n'};
    bool operator <(mice a){
        if(we==a.we) return sp<a.sp;
        return we<a.we;
    }
}mc[1001];

int main()
{
    int n=0,re[1001]={1},m=0,f;
    while(cin>>mc[n].we>>mc[n].sp)
    {
        if(mc[n].we==0) break;
        n++;
        mc[n-1].num=n;
    }
    for(int i=0;i<1001;i++){
        re[i]=1;
        sprintf(mc[i].s,"\n%d",mc[i].num);
    } 
    sort(mc,mc+n);
    for(int i=1;i<n;i++)
    {
        int max=0,flag1=0;
        char *flag2;
        for(int j=0;j<i;j++)
        {
            if(mc[j].sp>=mc[i].sp)
            {
                if(max<re[j]&&mc[j].we<mc[i].we){
                    max=re[j];
                    flag1=mc[j].num;
                    flag2=mc[j].s;
                }
            }
        }
        if(flag1&&(flag1!=mc[i].num)){
            re[i]+=max;
            char s2[2002];
            sprintf(s2,"%s%s",flag2,mc[i].s);
            sprintf(mc[i].s,"%s",s2);
        } 
        if(m<=re[i]){
            m=re[i];
            f=i;
        }
    }
    cout<<m<<mc[f].s<<endl;

}