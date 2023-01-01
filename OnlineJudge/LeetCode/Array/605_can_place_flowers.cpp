#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int pos = 0;
        int count = 0;
        int len = flowerbed.size();
        while(pos < len)
        {
            if(flowerbed[pos] == 1)
                pos ++;
            else
            {
                int bg = pos;
                while(pos < len && flowerbed[pos] == 0)
                    pos ++;
                int size = pos - bg;
                if(bg == 0 && flowerbed[bg] == 0)
                    size ++;
                if(pos == len && flowerbed[len - 1] == 0)
                    size ++;
                n -= (size - 1) / 2;
            }
        }
        if(n <= 0)
            return 1;
        return 0;
    }
};

int main()
{
    
    return 0;
}