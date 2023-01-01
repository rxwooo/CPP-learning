#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1 = 0;
        int pos2 = 0;
        int len1 = version1.size();
        int len2 = version2.size();
        while(pos1 < len1 || pos2 < len2)
        {
            string v1 = "";
            if(pos1 >= len1)
                v1 += '0';
            else
                while(pos1 < len1 && version1[pos1] != '.')
                    v1 += version1[pos1++];
            
            string v2 = "";
            if(pos2 >= len2)
                v2 += '0';
            else
                while(pos2 < len2 && version2[pos2] != '.')
                    v2 += version2[pos2++];

            int _v1 = stoi(v1);
            int _v2 = stoi(v2);
            if(_v1 > _v2)
                return 1;
            if(_v1 < _v2)
                return -1;
            pos1 ++;
            pos2 ++;
        }
        return 0;
    }
};

int main()
{
    Solution so;
    int res;
    res = so.compareVersion("1.00.1", "1.0.2");
    return 0;
}