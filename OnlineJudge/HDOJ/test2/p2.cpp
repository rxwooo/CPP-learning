#include<bits/stdc++.h>
using namespace std;

struct node{
    char nm[11];
    int age;
    float grade;
};

bool cmp(node a,node b)
{
    if(a.grade==b.grade)
    {
        if(a.age==b.age)
        {
            return strcmp(a.nm,b.nm)<0;
        }
        else return a.age<b.age;
    }
    else return a.grade>b.grade;
}

int main()
{
    int n;
    while(cin>>n)
    {
        node st[100];
        
        for(int i=0;i<n;i++)
        {
            cin>>st[i].nm>>st[i].age>>st[i].grade;
        }
        sort(st,st+n,cmp);
        for(int i=0;i<n;i++)
        {
            printf("%s %d %.2f\n",st[i].nm,st[i].age,st[i].grade);
        }

    }

}