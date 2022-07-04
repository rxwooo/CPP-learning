#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        int c;
        while(n --)
        {
            cin >> c;
            arr.push_back(c);
        }
        sort(arr.begin(), arr.end());
        if(arr.size() == 1)
            cout << c << endl;
        else
            cout << arr[arr.size() - 1] + arr[arr.size() - 2] << endl;
    }
    return 0;
}