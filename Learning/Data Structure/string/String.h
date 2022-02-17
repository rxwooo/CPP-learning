#ifndef __STRING__
#define __STRING__

#include <bits/stdc++.h>
using namespace std;

struct String
{
    String(char *c)
    {
        len = strlen(c);
        str = new char[len + 1];
        strcpy(str, c);
    }
    String()
    {
        len = 0;
        str[0] = 0;
    }
    char *str;
    int len;
};
//将字符串常量赋值给String
void StrAssign(String &, const char *);

//将String的值赋值给String&
void StrCopy(String &, String);
//将char复制给string
void StrCopy(String &, char *);
//将string的字符串复制给char*
void StrCopy(char *, String &);

//字典序对比s1和s2，相等返回0，前大后小返回正数，前小后大返回负数
bool StrCompare(String &s1, String &s2);

//返回String的长度
int Strlen(String &);

//将s2链接到s1的后面
String StrConnect(String &s1, String &s2);
//将字符串常量的值链接到String后
String StrConnect(String &, char *);

//返回pos开始长度为len的子串
String SubString(String &, int pos, int len);

//销毁String
void StrDestory(String &);

//判断String是否为空，空返回1，非空返回0
bool StrEmpty(String &);

//将String变为空串
void StrClear(String &);

//若s1中存在与s2相同的子串，返回子串首字母的坐标，若无则返回-1
int StrIndex(String &s1, String &s2);

int Strlen(String &s)
{
    return s.len;
}

bool StrEmpty(String &s)
{
    return s.len;
}

void StrClear(String &s)
{
    delete[] s.str;
    s.str = new char;
    s.str[0] = '\0';
    s.len = 0;
}

void StrDestory(String &s)
{
    delete[] s.str;
    delete &s;
}

void StrAssign(String &s, const char *c)
{
    int le = strlen(c);
    StrClear(s);
    s.str = new char[strlen(c) + 1];
    strcpy(s.str, c);
    s.len = le;
}

void StrCopy(String &a, String &b)
{
    StrClear(a);
    a.str = new char[strlen(b.str) + 1];
    strcpy(a.str, b.str);
    a.len = b.len;
}

void StrCopy(String &s, char *c)
{
    StrClear(s);
    s.str = new char[strlen(c) + 1];
    strcpy(s.str, c);
    s.len = strlen(c);
}

void StrCopy(char *c, String &s)
{
    strcpy(c, s.str);
}

bool StrCompare(String &s1, String &s2)
{
    return strcmp(s1.str, s2.str);
}

String StrConnect(String &s1, String &s2)
{
    char *s = new char[s1.len + s2.len + 1];
    strcpy(s, s1.str);
    strcpy(s + s1.len, s2.str);
    return String(s);
}

String StrConnect(String &s1, char *c)
{
    char *s = new char[s1.len + strlen(c) + 1];
    strcpy(s, s1.str);
    strcpy(s + s1.len, c);
    return String(s);
}

String SubString(String &s1, int pos, int len)
{
    char *s = new char[len + 1];
    for (int i = 0; i < len; i++)
        s[i] = s1.str[pos + i];
    s[len] = 0;
    return String(s);
}

void nextval(String &s, int *next)
{
    char *c = new char[s.len + 1]; //开辟字符数组用于生成nextval数组
    StrCopy(c, s);
    char *tp = c; //标记首字母地址

    int count = -1;
    int pos = 0; //当前next位置
    next[0] = -1;

    /*
    算法思想：
        next[j] = 第j个字符开始往前数的字符串与原字符串从开头往后尽量多的匹配数量
                  表述为
        eg:
                a b a b a b a c
        next:   0 0 0 1 2 3 4 0

                a b a a b c a c
        next:   0 0 0 1 1 2 0 1

                a d a b b a d a d a
        next:   0 0 0 1 0 0 1 2 3 2
    */

    while (pos < strlen(c) - 1)
    {
        if (count == -1 || c[pos] == c[count])
        {
            count++;
            pos++;
            next[pos] = count;
        }
        else
            count = next[count];
    }
}

int StrIndex(String &s1, String &s2)
{
    int *nex = new int[s2.len];
    nextval(s2, nex);
    int ps1 = 0;
    int ps2 = 0;

    while (ps1 < s1.len && ps2 < s2.len)
    {
        if (ps2 == -1 || s1.str[ps1] == s2.str[ps2])
        {
            ps1++;
            ps2++;
        }
        else
        {
            ps2 = nex[ps2];
        }
    }
    delete[] nex;
    if (ps2 == s2.len)
        return ps1 - ps2 + 1;
    else
        return 0;
}

String StrReverse(String& s)
{
    char *c = new char[s.len + 1];
    c[s.len] = 0;
    for(int i = s.len - 1 ;i>=0;i--)
    {
        c[i] = s.str[s.len - i - 1];
    }
    String ss(c);
    delete[] c;
    return ss;
}

ostream& operator << (ostream& os, String& s)
{
    return os << s.str;
}

#endif