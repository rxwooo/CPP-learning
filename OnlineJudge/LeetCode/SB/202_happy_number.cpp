#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n)
{
    unordered_set<int> nums;
    while(1)
    {
        int tp = 0;
        while(n)
        {
            tp += (n % 10) * (n % 10);
            n /= 10;
        }
        n = tp;
        if(n == 1)
            return 1;
        if(nums.find(n) != nums.end())
            break;
        nums.insert(n);
    }
    return 0;
}

int main()
{
    cout << isHappy(19) << endl;
    return 0;
}