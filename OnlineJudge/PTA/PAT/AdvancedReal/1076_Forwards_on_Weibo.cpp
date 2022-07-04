#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, limit;
    cin >> n >> limit;
    unordered_map<int, vector<int>> users(n);
    for(int i = 1; i <= n; i++)
    {
        int num, tp;
        cin >> num;
        while(num --)
        {
            cin >> tp;
            users[tp].push_back(i);
        }
    }
    int query;
    cin >> query;
    while (query--)
    {
        int root;
        cin >> root;
        queue<int> tra;
        unordered_set<int> chk;
        tra.push(root);
        int last = 1;
        int count = 0;
        int level = 0;
        chk.insert(root);
        while(last && level <= limit)
        {
            while(last--)
            {
                int user = tra.front();
                int len = users[user].size();
                for(int i = 0; i < len; i++)
                    tra.push(users[user][i]);
                tra.pop();
                if(chk.find(user) == chk.end())
                    count ++;
                chk.insert(user);
            }
            last = tra.size();
            level++;
        }
        cout << count << endl;
    }
    
    return 0;
}