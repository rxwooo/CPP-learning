#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<vector<int>> str;
    vector<int> arr;
    int n;
    cin >> n;
    int count = 0;
    char ch;
    int c;
    int pos;
    n++;
    while(n--)
    {
        pos = 0;
        while (ch = getchar(), ch != '\n')
        {
            c = ch - '0';
            if(pos + 1 > str.size())
                str.push_back({});
            str[pos].push_back(c);
            pos++;
        }
    }
    int len = str.size();
    for(int i = 0; i < len; i++)
    {
        int vlen = str[i].size();
        int sum = 0;
        for(int j = 0; j < vlen; j++)
            sum += pow(10, vlen - j - 1) * str[i][j];
        arr.push_back(sum);
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i];
        if(i != arr.size() - 1)
            cout << " ";
    }
    return 0;
}