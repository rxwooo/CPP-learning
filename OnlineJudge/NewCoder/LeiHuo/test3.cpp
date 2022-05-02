#include<bits/stdc++.h>
using namespace std;

string cmd;

class Func{
public:
    Func(){};
    Func(string names, string parms):name(names), parm(parms){};
    string name;
    string parm;
    int getStrNum()
    {
        int len = this->parm.size();
        int count = 0;
        for(int i = 0; i < len; i++)
            if(this->parm[i] == 's')
                count ++;
        return count;
    }
};
Func funcs[260];

int getInt(string& s, int bg, int ed)
{
    int len = ed - bg;
    int sum = 0;
    for(int i = 0; i <= len; i ++)
    {
        int wei;
        if(s[ed - i] >= 'A' && s[ed - i] <= 'F')
            wei = s[ed - i] - 'A' + 10;
        else
            wei = s[ed - i] - '0';
        sum += wei * (int)pow(16, i);
    }
    return sum;
}

int funcPro(int id, int pos)
{
    queue<int> slen;
    int snum = funcs[id].getStrNum();
    for(int i = 0; i < snum; i++, pos+=2)
        slen.push(getInt(cmd, pos, pos+1));
    cout << funcs[id].name << "(";
    int plen = funcs[id].parm.size();
    for(int i = 0; i < plen; i++)
    {
        if(funcs[id].parm[i] == 'i')
        {
            cout << getInt(cmd, pos, pos + 7);
            pos += 8;
        }
        else if(funcs[id].parm[i] == 's')
        {
            cout << "\"" << cmd.substr(pos, slen.front() * 2) << "\"";
            pos += slen.front() * 2;
            slen.pop();
        }
        if(i != plen - 1)
            cout << ",";
        else
            cout << ")" << endl;
    }
    return pos;
}

int main()
{
    int funcNum;
    cin >> funcNum;

    //get funcs
    for(int i = 0; i < funcNum; i++)
    {
        int n;
        cin >> n;
        string name, parm;
        cin >> name >> parm;
        funcs[i] = Func(name, parm);
    }

    //get cmd
    cin >> cmd;
    int pos = 0;
    int len = cmd.size();
    while(pos < len)
    {
        int funcId = getInt(cmd, pos, pos + 1);
        pos = funcPro(funcId, pos + 2);
    }
    return 0;
}

/*
2
0 Login  ssi
1 MoveTo iii
01FFFFFFFF0000000100000A000003050A0B0C1A2B3C4F5D01000000
*/