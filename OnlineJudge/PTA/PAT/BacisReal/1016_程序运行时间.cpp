#include<bits/stdc++.h>
using namespace std;


int main()
{
    int start, end;
    cin >> start >> end;    
    int sec = (end - start) / 100;
    int yu = (end - start) % 100;
    if(yu >= 50)
        sec ++;
    int hour = sec / 3600;
    sec -= hour * 3600;
    int min = sec / 60;
    sec -= min * 60;
    printf("%02d:%02d:%02d\n", hour, min, sec);
    return 0;
}