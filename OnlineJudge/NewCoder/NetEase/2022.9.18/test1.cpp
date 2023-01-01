#include<bits/stdc++.h>
using namespace std;

int chk(string& src, string& tar)
{
    vector<int> res(6, 0);
    int maxN = 0;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int tp = 0;
            for(int k = 0; k < 5 - j; k ++)
            {
                if(i + k == 5 || j + k == 5)
                    break;
                if(src[i + k] == tar[j + k])
                    tp ++;
                else
                    break;
            }
            maxN = max(maxN, tp);
        }
    }
    return maxN;
}

int main()
{
    int n;
    cin >> n;
    float total = n * 100000;
    float grade = 0;
    int loop = n;
    while(loop -- ) 
    {
        string src, tar;
        cin >> src >> tar;
        int len = src.size();
        char srcColor = src[0];
        char tarColor = tar[0];
        string srcRegion = src.substr(1, len - 6);
        string tarRegion = tar.substr(1, len - 6);
        string srcID = src.substr(len - 5, 5);
        string tarID = tar.substr(len - 5, 5);

        if(srcColor == tarColor)
            grade += 20000;
        if(srcRegion == tarRegion)
            grade += 30000;
        grade += chk(srcID, tarID) * 10000;
    }
    printf("%.2f", grade * 100 / total);
    cout << "%" << endl;
    return 0;
}
// 5
// YZHEA163N8 YZHEA163NB
// GHUCNE163 GHUCNE163
// OJINGA88688 BJINGAB6868
// GMINGA366A BMING886A3
// BJIN1A66686 BJIN2A66666