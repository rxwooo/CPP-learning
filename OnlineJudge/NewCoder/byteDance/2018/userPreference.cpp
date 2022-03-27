#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, vector<int>> kmap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int like;
        cin >> like;
        if(kmap.find(like) == kmap.end())
        {
            vector<int> tp;
            tp.push_back(i+1);
            kmap.insert({like, tp});
        }
        else
        {
            kmap[like].push_back(i + 1);
        }
    }
    int q;
    cin >> q;
    while(q --)
    {
        int bg, ed, k;
        cin >> bg >> ed >> k;
        if(kmap.find(k) == kmap.end())
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> tp = kmap[k];
        int len = tp.size();
        int count = 0;
        for(int i = 0; i < len; i++) 
        {
            if(tp[i] > ed)
                break;
            if(tp[i] >= bg) 
                count++;
        }
        cout << count << endl;
    }
    return 0;
}