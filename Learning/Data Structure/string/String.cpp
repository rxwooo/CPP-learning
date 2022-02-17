#include "String.h"

int main()
{
    char s1[11] = "adabbadada";
    char s2[]= "adbadabbaabadabbadada";
    String ss1 = s1;
    String ss2 = s2;
    int n[12];
    //Getnext(n, s);
    int num = StrIndex(ss2,ss1);
    cout<<num<<endl;

    ss2 = StrReverse(ss1); 
    cout<<ss2<<endl;

    return 0;
}