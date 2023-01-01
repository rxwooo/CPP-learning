#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    vector<int> chk(n);
    vector<int> less(n);
    map<int, int> lessMap;
    unordered_map<int, int> numMap;
    unordered_map<int, int> lastCount;
    int res = 0;
    for(int i = 0; i < n; i ++)
    {
        cin >> nums[i];
        numMap[nums[i]] ++;
    }
    for(int i = 0; i < n; i ++)
    {
        int count = 0;
        for(auto item: lessMap)
        {
            if(item.first >= nums[i])
                break;
            count += item.second;
        }
        if(lessMap[nums[i]] > 0)
        {
            if(count != lastCount[nums[i]])
                numMap[nums[i]] --;
            res += (count - lastCount[nums[i]]) * numMap[nums[i]];
        }
        lastCount[nums[i]] = count;
        lessMap[nums[i]] ++;
    }
    cout << res << endl;
    return 0;
}