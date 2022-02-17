#include<iostream>
#include<algorithm>
using namespace std;

struct rice{
    double pr=0,he=0;
    bool operator <(const rice& a)
    {
        return pr<a.pr;
    }
};

int main(){
    int c;
    cin>>c;
    for(int j=0;j<c;j++){
        int n,m;
        double sum=0;
        scanf("%d %d",&n,&m);
        rice r[1001];
        for(int i=0;i<m;i++)
        {
            scanf("%lf %lf",&(r[i].pr),&(r[i].he));
        }
        sort(r,r+m);
        for(int i=0;i<m;i++){
            if(n>r[i].pr*r[i].he){
                sum+=r[i].he;
                n-=r[i].pr*r[i].he;
            }
            else{
                sum+=1.0*n/r[i].pr;
                break;
            }
        }
        printf("%.2f\n",sum);
    }
}