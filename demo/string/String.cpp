#include<bits/stdc++.h>
#include"String.h"
using namespace std;

int main()
{
    char c[9]="hello";
    char* p;
    p=c;
    String s1;
    s1 = "hello,";
    String s2( "world!" );
    String s3(s1);
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;

    return 0;
}