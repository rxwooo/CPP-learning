#include<bits/stdc++.h>
using namespace std;

bool isBadVersion(int a)
{
    return 1;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1;
        int end = n;
        while(start + 1 < end)
        {
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid))
                end = mid;
            else 
                start = mid; 
        }
        if(isBadVersion(start))
            return start;
        return end;
    }
};

int main()
{
    
    return 0;
}