#include<bits/stdc++.h>
using namespace std;

struct car{
    car(){}
    car(string n, int t, int a):name(n), time(t), act(a){}
    string name;
    int time;
    int act;
};

bool cmp(car& a, car& b)
{
    if(a.time == b.time)
        return a.name < b.name;
    return a.time < b.time;
}

bool cmp2(car& a, car& b)
{
    if(a.time == b.time)
        return a.name < b.name;
    return a.time > b.time;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<car> carvec;
    vector<car> keep;
    vector<int> query(n+1, 0);
    unordered_map<string, int> carmap;
    unordered_map<string, int> carpos;
    while(n--)
    {
        string tpname, tpact;
        int h, m, s;
        cin >> tpname;
        scanf("%2d:%2d:%2d", &h, &m, &s);
        cin >> tpact;
        carvec.push_back({tpname, h * 3600 + m * 60 + s, tpact == "in"});
    }
    sort(carvec.begin(), carvec.end(), cmp);
    int count = 0;
    for(int i = 1; i <= carvec.size(); i++)
    {
        if(carvec[i-1].act == 1)
        {
            query[i] = query[i - 1] + (carmap.find(carvec[i-1].name) == carmap.end());
            carmap[carvec[i-1].name] = carvec[i-1].time;
        }
        else
        {
            if(carmap.find(carvec[i-1].name) == carmap.end())
            {
                query[i] = query[i - 1];
                continue;
            }
            query[i] = query[i - 1] == 0? 0: query[i - 1] - 1;
            if(carpos.find(carvec[i-1].name) == carpos.end())
            {
                keep.push_back({carvec[i-1].name, carvec[i-1].time - carmap[carvec[i-1].name], -1});
                carpos.insert({carvec[i-1].name, count});
                count++;
            }
            else
                keep[carpos[carvec[i-1].name]].time += carvec[i-1].time - carmap[carvec[i-1].name];
            carmap.erase(carvec[i-1].name);
        }
    }
    while(q--)
    {
        int h, m, s, i;
        scanf("%2d:%2d:%2d", &h, &m, &s);
        int t = h * 3600 + m * 60 + s;
        for(i = 1; i <= carvec.size();)
            if(t < carvec[i++].time)
                break;
        cout << query[i - 1] << endl;
    }
    sort(keep.begin(), keep.end(), cmp2);
    set<string> once;
    int maxKeep = keep[0].time;
    for(int i = 0; i < keep.size(); i++)
    {
        if(keep[i].time != maxKeep)
            break;
        cout << keep[i].name << " ";
        once.insert(keep[i].name);
    }
    int h, m ,s;
    h = maxKeep / 3600;
    maxKeep -= h * 3600;
    m = maxKeep / 60;
    maxKeep -= m * 3600;
    printf("%02d:%02d:%02d\n", h, m ,s);
    return 0;
}