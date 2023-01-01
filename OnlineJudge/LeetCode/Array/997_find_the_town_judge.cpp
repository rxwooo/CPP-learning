#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> _map;
        int maxTrust = 0;
        int res = -1;
        for(auto vec: trust)
        {
            _map[vec[1]] ++;
            if(_map[vec[1]] > maxTrust)
            {
                res = vec[1];
                maxTrust = _map[vec[1]];
            } 
        }
        if(maxTrust ==  n - 1)
            return res;
        return -1;
    }
};

int main()
{
    Solution so;
    vector<vector<int>> test = {{1,3},{2,3},{3,1}};
    cout << so.findJudge(3, test) << endl;
    return 0;
}