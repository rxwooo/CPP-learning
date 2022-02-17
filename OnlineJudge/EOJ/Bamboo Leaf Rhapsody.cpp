#include<bits/stdc++.h>
using namespace std;

struct node
{
    int x,y,z;
    double f;
};


int main()
{
    int test;
    cin>>test;
    node min{0,0,0,0};
    cin>>min.x>>min.y>>min.z;
    min.f=sqrt(min.x*min.x+min.y*min.y+min.z*min.z);
    while(--test)
    {
        node n;
        cin>>n.x>>n.y>>n.z;
        n.f=sqrt(n.x*n.x+n.y*n.y+n.z*n.z);
        if(n.f<min.f) min=n;
    }
    printf("%.3f",min.f);
}