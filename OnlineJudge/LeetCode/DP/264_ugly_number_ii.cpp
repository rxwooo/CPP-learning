#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n)
{
    vector<int> ugly;
    ugly.push_back(1);
    int count2 = 0;
    int count3 = 0;
    int count5 = 0;
    while(ugly.size() <= n)
    {
        int two = ugly[count2] * 2; 
        int three = ugly[count3] * 3;
        int five = ugly[count5] * 5;
        int minN = min(two, min(three, five));
        if(minN == two)
        {
            if(ugly[ugly.size() - 1] != two)
                ugly.push_back(two);
            count2 ++;
        }
        if(minN == three)
        {
            if(ugly[ugly.size() - 1] != three)
                ugly.push_back(three);
            count3 ++;
        }
        if(minN == five)
        {
            if(ugly[ugly.size() - 1] != five)
                ugly.push_back(five);
            count5 ++;
        }
    }
    return ugly[n - 1];
}

int main()
{
    cout << nthUglyNumber(10) << endl;
    return 0;
}