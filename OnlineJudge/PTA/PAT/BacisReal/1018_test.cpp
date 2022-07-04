#include<bits/stdc++.h>
using namespace std;


bool check(string year, string month, string day)
{
    if(year > "2014")
        return 0;
    if(year == "2014" && month > "09")
        return 0;
    if(year == "2014" && month == "09" && day > "06")
        return 0;
    if(year < "1814")
        return 0;
    if(year == "1814" && month < "09")
        return 0;
    if(year == "1814" && month == "09" && day < "06")
        return 0;
    return 1;
}

struct person
{
    person(string n, string y, string m, string d):name(n), year(y), month(m), day(d){}
    string name;
    string year;
    string month;
    string day;
};

bool cmp(person a, person b)
{
    if(a.year == b.year)
    {
        if(a.month == b.month)
            return a.day < b.day;
        return a.month < b.month;
    }
    return a.year < b.year;
}

int main()
{
    int n;
    cin >> n;
    char ch;
    vector<person> p; 
    for(int i = 0; i < n; i++)
    {
        string name;
        string date;
        cin >> name >> date;
        if(check(date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)))
            p.push_back({name, date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)});
    }
    sort(p.begin(), p.end(), cmp);
    cout << p.size() << " " << p[0].name << " " << p[p.size() - 1].name;
    return 0;
}