#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int odd = (len1 + len2) % 2;
        int target = (len1 + len2) / 2;
        double result = 0;
        vector<int> vec;

        int pos1 = 0, pos2 = 0;
        while(pos1 < len1 && pos2 < len2)
        {
            vec.push_back(nums1[pos1] <= nums2[pos2]? nums1[pos1++]: nums2[pos2++]);
            if(pos1+pos2 == target + 1)
                result = odd? vec[target]: ((double)vec[target] + (double)vec[target - 1]) / 2;
        }
        while(pos1 < len1)
        {
            vec.push_back(nums1[pos1++]);
            if(pos1+pos2 == target + 1)
            {
                result = odd? vec[target]: ((double)vec[target] + (double)vec[target - 1]) / 2;
                vec.insert(vec.end(), nums1.begin() + pos1, nums1.end());
                break;
            }
        }
        while (pos2 < len2)
        {
            vec.push_back(nums2[pos2++]);
            if(pos1+pos2 == target + 1)
            {
                result = odd? vec[target]: ((double)vec[target] + (double)vec[target - 1]) / 2;
                vec.insert(vec.end(), nums2.begin() + pos2, nums2.end());
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution so;
    vector<int> vec1 = {1, 2};
    vector<int> vec2 = {3, 4};
    cout << so.findMedianSortedArrays(vec1, vec2) << endl;
    return 0;
}