#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string last;
    string cur;
    cin >> n;
    getchar();
    getline(cin, last);
    for(int i = 1; i < n; i++)
    {
        getline(cin, cur);
        int cur_len = cur.size();
        int last_len = last.size();
        int len = min(cur_len, last_len);
        int j;
        for(j = 1; j <= len; j++)
            if(cur[cur_len - j] != last[last_len - j])
                break;
        last = cur.substr(cur_len - j + 1, j - 1);
    }
    if(last.size() > 0)
        cout << last << endl;
    else
        cout << "nai" << endl;
    return 0;
}