#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int offset = 0;
        while(left != right)
        {
            left >>= 1;
            right >>= 1;
            offset ++;
        }
        return left << offset;
    }
};

int main()
{
    
    return 0;
}