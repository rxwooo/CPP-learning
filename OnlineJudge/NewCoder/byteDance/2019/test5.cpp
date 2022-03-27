#include<bits/stdc++.h>
using namespace std;

vector<int> vec;

int dfs(int pos, int mul)
{
    if(pos == vec.size())
        return 0;
    
    int left = dfs(pos + 1, -1);
    int right = dfs(pos + 1, 1);
    if(left <= 0 && right <= 0)
        return max(left, right)+vec[pos]*mul;
    if(left > 0 && right > 0)
        return 1;
    if(left > 0)
            return right+vec[pos]*mul;
    return left+vec[pos]*mul;
}

int main()
{
    vec.push_back(0); 
    int n;
    int last = 0;
    cin >> n;
    if(n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(abs(num - last));
        last = num;
    }
    int re = dfs(n, 1);

    cout << re << endl;

    return 0;
}