#include<bits/stdc++.h>
using namespace std;

vector<string> cvec;
string s;
int re = 0;

void generatecvec()
{
    cvec.push_back({"0"});
    cvec.push_back({"1"});
    cvec.push_back({"10"});
    cvec.push_back({"11"});
    cvec.push_back({"100"});
    cvec.push_back({"101"});
    cvec.push_back({"110"});
    cvec.push_back({"111"});
}

void dfs(int index)
{
    if(index > s.length())
        return ;
    if(index == s.length())
        re++;
    //A 0
    string tp = cvec[0];
    if(s.substr(index, 1) == tp)
        dfs(index + 1);
    //B 1
    tp = cvec[1];
    if(s.substr(index, 1) == tp)
        dfs(index + 1);
    //C 10
    tp = cvec[2];
    if(s.substr(index, 2) == tp)
        dfs(index + 2);
    //D 11
    tp = cvec[3];
    if(s.substr(index, 2) == tp)
        dfs(index + 2);
    //E 100
    tp = cvec[4];
    if(s.substr(index, 3) == tp)
        dfs(index + 3);
    //F 101
    tp = cvec[5];
    if(s.substr(index, 3) == tp)
        dfs(index + 3);
    //G 110
    tp = cvec[6];
    if(s.substr(index, 3) == tp)
        dfs(index + 3);
    //H 111
    tp = cvec[7];
    if(s.substr(index, 3) == tp)
        dfs(index + 3);
    
    return ;
}

int main()
{
    generatecvec(); 
    cin >> s;
    dfs(0);
    cout << re << endl;
    return 0;
}