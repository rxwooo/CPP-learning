#include <bits/stdc++.h>
using namespace std;

int low;
int high;

struct student
{
    student() : num(0), de(0), cai(0) {}
    student(int n, int d, int c) : num(n), de(d), cai(c) {}
    int num;
    int de;
    int cai;
};

bool cmp(student a, student b)
{
    // if(a.de > high && a.cai > high && b.de > high && b.cai > high)
    // de cai quan sheng
    if (a.de >= high && a.cai >= high)
    {
        if (b.de >= high && b.cai >= high)
        {
            if (a.cai + a.de == b.cai + b.de)
                if (a.de == b.de)
                    return a.num < b.num;
                else
                    return a.de > b.de;
            return a.cai + a.de > b.cai + b.de;
        }
        return 1;
    }
    // de sheng cai
    if (a.de >= high && a.cai < high)
    {
        if (b.de >= high && b.cai >= high)
            return 0;
        if (b.de >= high && b.cai < high)
        {
            if (a.cai + a.de == b.cai + b.de)
                if (a.de == b.de)
                    return a.num < b.num;
                else
                    return a.de > b.de;
            return a.cai + a.de > b.cai + b.de;
        }
        return 1;
    }
    // de sheng cai BUT cai de jian wang
    if (a.de >= a.cai)
    {
        if (b.de >= high && b.cai >= high)
            return 0;
        if (b.de >= high && b.cai < high)
            return 0;
        if (b.de >= b.cai)
        {
            if (a.cai + a.de == b.cai + b.de)
                if (a.de == b.de)
                    return a.num < b.num;
                else
                    return a.de > b.de;
            return a.cai + a.de > b.cai + b.de;
        }
        return 1;
    }
    // cai de jian wang
    if (b.de >= high && b.cai >= high)
        return 0;
    if (b.de >= high && b.cai < high)
        return 0;
    if (b.de >= b.cai)
        return 0;
    if (a.cai + a.de == b.cai + b.de)
        if (a.de == b.de)
            return a.num < b.num;
        else
            return a.de > b.de;
    return a.cai + a.de > b.cai + b.de;
}

int main()
{
    vector<student> stu;
    int n;
    cin >> n >> low >> high;
    while (n--)
    {
        int cai, de;
        int num;
        cin >> num >> de >> cai;
        if (de >= low && cai >= low)
            stu.push_back({num, de, cai});
    }
    sort(stu.begin(), stu.end(), cmp);
    cout << stu.size() << endl;
    for (int i = 0; i < stu.size(); i++)
        cout << stu[i].num << " " << stu[i].de << " " << stu[i].cai << endl;
    return 0;
}