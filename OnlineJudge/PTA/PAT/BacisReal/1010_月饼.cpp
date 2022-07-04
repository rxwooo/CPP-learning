#include<bits/stdc++.h>
using namespace std;

struct bing{
    bing(): total(0), cost(0), per(0){}
    float total;
    float cost;
    float per;
};

bool cmp(bing a, bing b)
{
    return a.per > b.per;
}

int main()
{
    int n;
    float need;
    float fee = 0;
    cin >> n >> need;
    vector<bing> vec(n);
    for(int i = 0; i < n; i++)
        cin >> vec[i].total;
    for(int i = 0; i < n; i++)
    {
        cin >> vec[i].cost;
        vec[i].per = (vec[i].cost / vec[i].total);
    }
    sort(vec.begin(), vec.end(), cmp);
    int pos = 0;
    while(need > 0 && pos < n)
    {
        if(vec[pos].total <= need)
        {
            fee += vec[pos].cost;
            need -= vec[pos].total;
        }
        else if(vec[pos].total > need)
        {
            fee += vec[pos].per * need;
            need = 0;
        }
        pos++;
    }
    printf("%.2f", fee);
    return 0;
}