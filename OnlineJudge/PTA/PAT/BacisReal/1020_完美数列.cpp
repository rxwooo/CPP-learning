#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n, p;
    vector<int> num;
    cin >> n >> p;
    for(int i = 0 ; i < n ; i ++)
    {
        int tp;
        cin >> tp;
        num.push_back(tp);
    }
    sort(num.begin(), num.end());
    int longest = 0;
    int slow = 0;
    int fast = 0;
    while(fast < num.size())
    {
        if(num[slow] * p >= num[fast])
        {
            longest = max(fast - slow + 1, longest);
            fast ++;
        }
        else
            slow ++;
        
    }
    cout << longest << endl;
    return 0;
}