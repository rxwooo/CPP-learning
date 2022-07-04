#include<bits/stdc++.h>
using namespace std;

int main()
{
    string raw, now;
    cin >> raw >> now;
    set<char> chset;
    for(int i = 0; i < now.size(); i++)
    {
        if(now[i] >= 'a' && now[i] <= 'z')
            now[i] += ('A' - 'a');
        chset.insert(now[i]);
    }
        
    for(int i = 0; i < raw.size(); i++)
    {
        if(raw[i] >= 'a' && raw[i] <= 'z')
            raw[i] += ('A' - 'a');
        if(chset.find(raw[i]) == chset.end())
        {
            cout << raw[i];
            chset.insert(raw[i]);
        }
    }
    cout << endl;
    return 0;
}