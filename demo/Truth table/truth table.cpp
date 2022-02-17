#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int cnt = 0, chval[26] = {};

void getAlpha(string str, char *chs, int &cnt)  //获取真值表中的字符 
{
    int ch[26] = {};
    for(int i = 0; i < (int)str.length(); ++i) {
        if(isalpha(str[i])) ch[str[i] - 'a'] ++;
    }
    for(int i = 0; i < 26; ++i) {
        if(ch[i]) {
            chs[cnt++] = i+97;
        }
    }
}

string shuzhitihuan(string str, int chval[26])
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] <= 'z' && str[i] >= 'a') {
            st += chval[str[i] - 'a'] ? "1":"0";
        } else st += str[i];
    }
    return st;
}

void qvkuohao(string & str)  //需要去除两种括号()(1)(0)
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '(' && i+2 < str.size() && str[i+2] == ')') {
            st += str[i+1];
            i += 2;
        } else st += str[i];
    }
    str = st;
}

void qvfei(string &str) 
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '!' && i+1 < str.size() && str[i+1] == '0') {
            st += '1';
            i++;
        } else if(str[i] == '!' && i + 1 < str.size() && str[i+1] == '1') {
            st += '0';
            i++;
        } else st += str[i];
    }
    str = st;
} 

void qvheqv(string &str)
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '1' && i+2 < str.size() && str[i+2] == '1' && str[i+1] == '*') {
            st += '1';
            i += 2;
        } else if(i+2 < str.size() && str[i+1] == '*' && ((str[i] == '1' && str[i+2] == '0')
        || (str[i] == '0' && str[i+2] == '1') || (str[i] == '0' && str[i+2] == '0'))) {
            st += '0';
            i += 2;
        } else st += str[i];
    }
    str = st;
}

void qvxiqv(string & str)
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i] == '0' && i+2 < str.size() && str[i+2] == '0' && str[i+1] == '|') {
            st += '0';
            i += 2;
        } else if (i+2 < str.size() && str[i+1] == '|' && ((str[i] == '1' && str[i+2] == '0')
        || (str[i] == '0' && str[i+2] == '1') || (str[i] == '1' && str[i+2] == '1'))) {
            st += '1';
            i += 2;
        } else st += str[i];
    }
    str = st;
}

void qvdantiaojian(string &str)
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i + 1] == '>' && str[i] == '1' && str[i+2] == '0') {
            st += '0';
            i += 2;
        } else if(str[i+1] == '>' && ((str[i] == '1' && str[i+2] == '1')
        || str[i] == '0' &&(str[i+2] == '1' || str[i+2] == '0'))) {
            st += '1';
            i += 2;
        } else st += str[i];
    }
    str = st;
}

void qvshuangtiaojian(string &str)
{
    string st = "";
    for(int i = 0; i < str.size(); ++i) {
        if(str[i+1] == '-' && ((str[i] == '1' && str[i+2] == '1') || (str[i] == '0' && str[i+2] == '0'))) {
            st += '1';
            i += 2;
        } else if(str[i+1] == '-' && ((str[i] == '1' && str[i+2] == '0') || (str[i] == '0' && str[i+2] == '1'))) {
            st += '0';
            i += 2;
        } else st += str[i]; 
    }
    str = st;
}

int main()
{
    string str, tmp;
    char chs[12];
    cin >> str;
    getAlpha(str, chs, cnt);  //只讨论小写字母
    tmp = str;
    for(int j = 0; j < cnt; ++j) {
        cout << chs[j] << "  ";
    } 
    cout << tmp;
    cout << endl;
    for(int i = 0; i < pow(2, cnt); ++i) {
        for(int j = 0; j < cnt; ++j) { //赋值过程 
            chval[chs[j] - 'a'] = (1 & (i>>(cnt-1-j)));
        }   cout << endl;
        for(int j = 0; j < cnt; ++j) {
            cout << chval[chs[j] - 'a'] << "  ";
        }
        str = shuzhitihuan(str, chval);
        while(str.size() != 1) {
            qvkuohao(str);
            qvfei(str);
            qvheqv(str);
            qvxiqv(str);
            qvdantiaojian(str);
            qvshuangtiaojian(str); 
        }
        for(int i = 0; i < tmp.size() / 2; ++i) cout << ' ';
        cout <<  str << endl;
        str = tmp;
    }
    getchar();getchar();
    return 0;
}

/*
((p*q)*r) 
(p*q)|(!p*!q)
(!p|q)*(!q|p) 
(p>q)*(q>p)
!(p*q)>(!p*!q)
p-q 
(!p|r)*(r>q)|p*q
p*q|r*b
*/