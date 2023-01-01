#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s)
{
    map<char, int> _map;
    for (char c : s)
        _map[c]++;
    vector<char> _char;
    vector<int> _int;
    for (auto a : _map)
    {
        _char.push_back(a.first);
        _int.push_back(a.second);
    }
    string res = "";
    for(int i = 0; i < _char.size(); i++)
    {
        while(_int[i] --)
            res += _char[i];
    }
    return res;
}

int main()
{
    string test = "tree";
    frequencySort(test);
    return 0;
}