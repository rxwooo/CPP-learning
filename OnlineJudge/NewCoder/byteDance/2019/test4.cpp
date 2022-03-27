#include<bits/stdc++.h>
using namespace std;

unordered_map< vector<int, int> ,int > vecMap;
unordered_map< vector<int, int> ,int > last;

int feature[10010];

int main()
{
    int n,m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        memset(feature, 0, sizeof(feature));
        int arr[2];
        for(int i = 0; i < m ; i++)
        {
            int num;
            cin >> num;
            for(int j = 0; j < num; j++)
            {
                if(j % 2 == 0 && j != 0)
                {
                    vector<int ,int> tp = {arr[0], arr[1]};
                    if(vecMap.find(tp) == vecMap.end()) 
                        vecMap.insert({tp, 0});
                    else
                        vecMap[tp] ++;
                    memset(arr, 0, sizeof(arr));
                }
                cin >> arr[j%2];
            }
            
        }

    }
    
    return 0;
}