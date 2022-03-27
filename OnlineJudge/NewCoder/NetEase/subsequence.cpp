#include<bits/stdc++.h>
using namespace std;

char s[110];
unordered_map<char, vector<int>> cmap;

bool dfs(int index, int limit)
{
    if(index == strlen(s))
        return 1;
    
    char c = s[index];
    vector<int> tp = cmap[c];
    int len = tp.size();
    bool re = 0;
    for(int i = 0; i < len; i++)
    {
        if(tp[i] > limit)
            re = re || dfs(index + 1, tp[i]);
    }
    return re;
}

int main()
{
    memset(s, 0, sizeof(s));
    cin >> s;
    getchar();
    int count = 0;
    while (1)
    {
        char c = getchar();
        if(c == '\n') 
            break;
        if(cmap.find(c) == cmap.end()) 
            cmap.insert({c,{count}});
        else
            cmap[c].push_back(count);
        count ++;
    }
    
    int re = dfs(0, -1);
    if(re)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    return 0;
}