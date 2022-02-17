#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <iomanip>
#include <stack>
using namespace std;
const int maxnlen = 1e4;

class Grammar
{
private:
    set<char> Vn;
    set<char> Vt;
    char S; //文法的开始符号
    map<char, set<string> > P;
    map<char, set<char> > FIRST;
    map<char, set<char> > FOLLOW;
    map<string, string> Table;
    vector<char> X;              //储存终结符——>列名
    vector<char> Y;              //储存非终结符——>行名
    vector<vector<string> > rule; //储存产生式规则
    stack<char> cmp;
    int eli_flag = 0; //消除标志

public:
    int flag;
    Grammar(string filename);
    void setHead(char c);
    void add(string s);
    void print();
    void getFirst();
    void getFollow();
    void getTable();
    void remove_left_recursion();
    void remove_left_gene(char c); //提取左因子
    void ShowByTogether();
    int findH(char a);
    int findL(char b);
    void analyze(char str[], int len); //预测分析
};

int main()
{

    string filename_gramer = "专题6.txt";
    Grammar* grammar = new Grammar(filename_gramer);
    cout << endl;
    cout << "消除左递归前"<< endl;
    cout <<  endl;
    cout << "初始文法显示：" << endl;
    grammar->ShowByTogether();
    cout << endl;
    grammar->getFirst();
    cout << endl;
    grammar->getFollow();
    cout << endl;
    grammar->getTable();

    cout << endl
        << endl;

    cout << endl;
    cout << "消除左递归后" << endl;
    cout << endl;

    // 消除左递归之后的判断
    grammar->remove_left_recursion();
    cout << "改善后，文法显示：" << endl;
    cout << endl;
    grammar->ShowByTogether();
    cout << endl;
    grammar->getFirst();
    cout << endl;
    grammar->getFollow();
    cout << endl;
    grammar->getTable();
    cout << endl
        << endl;

    cout << "/——————————————————————————————————————————————————————————/" << endl;
    cout << "/***************************************************预测分析********************************************************/" << endl;
    cout << "/——————————————————————————————————————————————————————————/" << endl;
    string str1;
    getline(cin, str1);
    char* str = (char*)str1.c_str();
    int len = strlen(str);

    grammar->analyze(str, len + 1);
    if (grammar->flag == 1)
        cout << "\n当前语句不合法!" << endl;
    else
        cout << "\n当前语句合法!" << endl;
    system("pause");
    return 0;
}
Grammar::Grammar(string filename)
{
    {
        Vn.clear();
        Vt.clear();
        P.clear();
        FIRST.clear();
        FOLLOW.clear();
        ifstream in("专题6.txt");
        if (!in.is_open())
        {
            cout << "文法  文件打开失败" << endl;
            exit(1);
        }
        char* buffer = new char[maxnlen];
        in.getline(buffer, maxnlen, '$');
        string temps = "";
        bool is_sethead = 0;
        for (int i = 0; i < strlen(buffer); i++)
        {
            if (buffer[i] == '\n' || buffer[i] == ' ')
                continue;
            if (buffer[i] == ';')
            {
                if (!is_sethead)
                {
                    this->setHead(temps[0]);
                    is_sethead = 1;
                }
                this->add(temps);
                temps = "";
            }
            else
                temps += buffer[i];
        }
        delete buffer;
        cmp.push('$');
        cmp.push(this->S);
        /*
            输出Vn，Vt，set

        */
    }
}
void Grammar::setHead(char c)
{
    S = c;
}
void Grammar::add(string s)
{
    char s1 = s[0];
    string s2 = "";
    int num = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '>')
            num = i;
        if (num == 0)
            continue;
        if (i > num)
            s2 += s[i];
    }
    s2 += ';';
    Vn.insert(s1);
    string temp = "";
    for (char s : s2)
    {
        if (!isupper(s) && s != '|' && s != ';' && s != '#')
            Vt.insert(s);
        if (s == '|' || s == ';')
        {
            P[s1].insert(temp);
            temp = "";
        }
        else
        {
            temp += s;
        }
    }
}
void Grammar::print()
{
    cout << "当前分析文法为：" << endl
        << endl;
    for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
    {
        char cur_s = *it;
        for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++)
        {
            string cur_string = *it1;
            cout << cur_s << "->" << cur_string << endl;
        }
    }
}
void Grammar::getFirst()
{
    FIRST.clear();
    //判断迭代次数
    int iter = 4;
    while (iter--)
    {
        for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
        {
            char cur_s = *it;
            /*
                cur_s->cur_string[0]
                    a加到A的FIRST集
                cur_s->cur_string[0]
                    B的FITRST集加到A的FIRST集
                */
            for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++)
            {
                string cur_string = *it1;
                if (!isupper(cur_string[0]))
                {
                    FIRST[cur_s].insert(cur_string[0]);
                }
                else
                {
                    char nxt_s = cur_string[0];
                    for (set<char>::iterator it2 = FIRST[nxt_s].begin(); it2 != FIRST[nxt_s].end(); it2++)
                    {
                        if ((*it2) != '#')
                        {
                            FIRST[cur_s].insert(*it2);
                        }
                    }
                }
            }
        }
    }
    //输出FIRST集
    cout << "FIRST集为：" << endl;
    for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
    {
        char cur_s = *it;
        cout << "FIRST(" << cur_s << "): {";
        for (set<char>::iterator it1 = FIRST[cur_s].begin(); it1 != FIRST[cur_s].end(); it1++)
        {
            if (std::distance(it1, FIRST[cur_s].end()) != 1)
                cout << *it1 << " ,";
            else
                cout << *it1;
        }

        cout << "}" << endl;
    }
}
void Grammar::getFollow()
{
    FOLLOW.clear();
    FOLLOW[S].insert('$');
    //判断迭代次数
    int iter = 4;
    while (iter--)
    {
        for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
        {
            char cur_s = *it;
            /*
                cur_s->cur_string[0]
                a加到A的FIRST集
                cur_s->cur_string[0]
                B的FITRST集加到A的FIRST集
                */
            for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++)
            {
                string cur_string = *it1;
                for (int i = 0; i < cur_string.length() - 1; i++)
                {
                    /*
                            B->Ac
                            将c加到A的follow集
                        */
                    if (isupper(cur_string[i]) && !isupper(cur_string[i + 1]))
                    {
                        FOLLOW[cur_string[i]].insert(cur_string[i + 1]);
                    }
                    /*
                            B->AC
                            将C的first集加到A的follow集
                        */
                    if (isupper(cur_string[i]) && isupper(cur_string[i + 1]))
                    {
                        //遍历C的first去除#，加到A的follow集
                        for (auto it2 = FIRST[cur_string[i + 1]].begin(); it2 != FIRST[cur_string[i + 1]].end(); it2++)
                        {
                            if ((*it2) != '#')
                                FOLLOW[cur_string[i]].insert(*it2);
                        }
                    }
                }
                int len = cur_string.length();
                if ((len >= 1 && isupper(cur_string[len - 1])))
                {
                    for (auto it2 = FOLLOW[cur_s].begin(); it2 != FOLLOW[cur_s].end(); it2++)
                    {
                        if (isupper(cur_string[len - 1]))
                            FOLLOW[cur_string[len - 1]].insert(*it2);
                    }
                }
                if ((len >= 2 && isupper(cur_string[len - 2]) && isupper(cur_string[len - 1]) && FIRST[cur_string[len - 1]].count('#') > 0))
                {
                    for (auto it2 = FOLLOW[cur_s].begin(); it2 != FOLLOW[cur_s].end(); it2++)
                    {
                        FOLLOW[cur_string[len - 2]].insert(*it2);
                    }
                }
            }
        }
    }
    //输出FOLLOW集
    cout << "FOLLOW集为：" << endl;
    for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
    {
        char cur_s = *it;
        cout << "FOLLOW(" << cur_s << "): {";
        for (set<char>::iterator it1 = FOLLOW[cur_s].begin(); it1 != FOLLOW[cur_s].end(); it1++)
        {
            if (std::distance(it1, FOLLOW[cur_s].end()) != 1)
                cout << *it1 << " ,";
            else
                cout << *it1;
        }
        cout << "}" << endl;
    }
}
void Grammar::getTable()
{
    set<char> Vt_temp;
    for (char c : Vt)
    {
        Vt_temp.insert(c);
    }
    Vt_temp.insert('$');
    for (auto it = Vn.begin(); it != Vn.end(); it++)
    {
        char cur_s = *it;
        for (auto it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++)
        {
            /*
                产生式为
                    cur_s->cur_string
                */
            string cur_string = *it1;
            if (isupper(cur_string[0]))
            {
                char first_s = cur_string[0];
                for (auto it2 = FIRST[first_s].begin(); it2 != FIRST[first_s].end(); it2++)
                {
                    string TableLeft = "";
                    TableLeft = TableLeft + cur_s + *it2;
                    Table[TableLeft] = cur_string;
                }
            }
            else
            {
                string TableLeft = "";
                TableLeft = TableLeft + cur_s + cur_string[0];
                Table[TableLeft] = cur_string;
            }
        }
        if (FIRST[cur_s].count('#') > 0)
        {
            for (auto it1 = FOLLOW[cur_s].begin(); it1 != FOLLOW[cur_s].end(); it1++)
            {
                string TableLeft = "";
                TableLeft = TableLeft + cur_s + *it1;
                Table[TableLeft] = "#";
            }
        }
    }
    /*
            检查出错信息：即表格中没有出现过的
        */

    for (auto it = Vn.begin(); it != Vn.end(); it++)
    {
        for (auto it1 = Vt_temp.begin(); it1 != Vt_temp.end(); it1++)
        {
            string TableLeft = "";
            TableLeft = TableLeft + *it + *it1;
            if (!Table.count(TableLeft))
            {
                Table[TableLeft] = "null";
            }
        }
    }

    /*
            显示Table
        */
    cout << "文法分析表：" << endl
        << endl;
    cout.setf(std::ios::left);
    for (auto it1 = Vt_temp.begin(); it1 != Vt_temp.end(); it1++)
    {
        if (it1 == Vt_temp.begin())
        {
            cout << setw(10) << " ";
        }
        cout << setw(10) << *it1;
        if (eli_flag == 1)
            X.push_back(*it1);
    }
    cout << endl;
    vector<string> t;
    for (auto it = Vn.begin(); it != Vn.end(); it++)
    {
        for (auto it1 = Vt_temp.begin(); it1 != Vt_temp.end(); it1++)
        {
            string TableLeft = "";
            if (it1 == Vt_temp.begin())
            {
                cout << setw(10) << *it;
                if (eli_flag == 1)
                    Y.push_back(*it);
            }
            TableLeft = TableLeft + *it + *it1;
            string temp;
            if (Table[TableLeft] != "null")
            {
                if (eli_flag == 1)
                {
                    temp += "::";
                    temp += Table[TableLeft];
                    t.push_back(temp);
                    // cout << "temp:" << temp;
                }
                cout << *it << "->" << setw(7) << Table[TableLeft];
            }
            else
            {
                // cout << "Table[TableLeft]:  " << Table[TableLeft] << endl;
                if (eli_flag == 1)
                {
                    string temp = "null";
                    t.push_back(temp);
                }
                cout << " "
                    << "  " << setw(7) << "   ";
            }
        }
        cout << endl;
        if (eli_flag == 1)
        {
            rule.push_back(t);
            t.clear();
        }
    }
}
/*
        消除左递归
    */
void Grammar::remove_left_recursion()
{
    eli_flag = 1;
    string tempVn = "";
    for (auto it = Vn.begin(); it != Vn.end(); it++)
    {
        tempVn += *it;
    }

    for (int i = 0; i < tempVn.length(); i++)
    {
        char pi = tempVn[i];
        set<string> NewPRight;
        for (auto it = P[pi].begin(); it != P[pi].end(); it++)
        {
            bool isget = 0;
            string right = *it;
            for (int j = 0; j < i; j++)
            {
                char pj = tempVn[j];
                if (pj == right[0])
                {
                    isget = 1;
                    for (auto it1 = P[pj].begin(); it1 != P[pj].end(); it1++)
                    {
                        string s = *it1 + right.substr(1);
                        NewPRight.insert(s);
                    }
                }
            }
            if (isget == 0)
            {
                NewPRight.insert(right);
            }
        }

        if (i != 0)
            P[pi] = NewPRight;

        remove_left_gene(pi);
    }
}
void Grammar::remove_left_gene(char c)
{
    eli_flag = 1;
    char NewVn;
    for (int i = 0; i < 26; i++)
    {
        NewVn = i + 'A';
        if (!Vn.count(NewVn))
        {
            break;
        }
    }
    bool isaddNewVn = 0;
    for (auto it = P[c].begin(); it != P[c].end(); it++)
    {
        string right = *it;

        if (right[0] == c)
        {
            isaddNewVn = 1;

            break;
        }
    }
    if (isaddNewVn)
    {
        set<string> NewPRight;
        set<string> NewPNewVn;
        for (auto it = P[c].begin(); it != P[c].end(); it++)
        {
            string right = *it;
            if (right[0] != c)
            {
                right += NewVn;
                NewPRight.insert(right);
            }
            else
            {
                right = right.substr(1);
                right += NewVn;
                NewPNewVn.insert(right);
            }
        }
        Vn.insert(NewVn);
        NewPNewVn.insert("#");
        P[NewVn] = NewPNewVn;
        P[c] = NewPRight;
    }
}
void Grammar::ShowByTogether()
{
    for (auto it = Vn.begin(); it != Vn.end(); it++)
    {
        cout << *it << "->";
        char c = *it;
        for (auto it1 = P[c].begin(); it1 != P[c].end(); it1++)
        {
            if (it1 == P[c].begin())
                cout << *it1;
            else
                cout << "|" << *it1;
        }
        cout << endl;
    }
}
int Grammar::findH(char a)
{
    for (int i = 0; i < 7; i++) //找到对应行
    {
        if (a == Y[i])
        {
            return i;
        }
    }
    return -1;
}
int Grammar::findL(char b)
{
    for (int i = 0; i < 8; i++) //找到对应列
    {
        if (b == X[i])
        {
            return i;
        }
    }
    return -1;
}
void Grammar::analyze(char str[], int len)
{
    int cnt = 1; //输出Step
    int i = 0;
    char p[200] = "$E"; //输出stack
    int pindex = 2;
    cout << "步骤\t\t栈\t\t字符串\t\t规则" << endl;
    while (i < len)
    {
        int x, y;
        char ch = cmp.top();
        // cout << "ch:" << ch << endl;
        if (ch >= 'A' && ch <= 'Z')
        {
            cmp.pop();
            x = findH(ch);
            y = findL(str[i]);
            if (x != -1 && y != -1)
            {
                int len2 = rule[x][y].length();
                if (rule[x][y] == "null")
                {
                    string t;
                    for (int j = 0; j < pindex; j++)
                    {
                        if (p[j] == 'X')
                            t += "E'";
                        else if (p[j] == 'Y')
                            t += "T'";
                        else
                        {
                            t += p[j];
                        }
                    }
                    cout << cnt << "\t\t" << t << "\t\t";
                    t.clear();
                    for (int q = i; q < len; q++)
                    {
                        cout << str[q];
                    }
                    cout << "\t出错！跳过当前符号，并继续分析" << endl;
                    cnt++;
                    flag = 1;
                    cmp.push(ch);
                    i = i + 1;
                    continue;
                }
                string t;
                for (int j = 0; j < pindex; j++)
                {
                    if (p[j] == 'X')
                        t += "E'";
                    else if (p[j] == 'Y')
                        t += "T'";
                    else
                    {
                        t += p[j];
                    }
                }
                // cout << t << "   ======" << endl;
                cout << cnt << "\t\t" << t << "\t\t";
                t.clear();
                if (p[pindex - 1] != '$')
                {
                    p[pindex] = '\0';
                    pindex--;
                }
                if (rule[x][y][2] != '#')
                {
                    for (int q = len2 - 1; q > 1; q--)
                    {
                        p[pindex++] = rule[x][y][q];
                        cmp.push(rule[x][y][q]); //进栈
                    }
                }
                else
                {
                    p[pindex] = '\0';
                    pindex;
                }
                for (int q = i; q < len; q++)
                {
                    cout << str[q]; //输出剩余输入串
                }
                t.clear();
                string m = rule[x][y];
                for (int j = 0; j < m.size(); j++)
                {
                    if (m[j] == 'X')
                        t += "E'";
                    else if (m[j] == 'Y')
                        t += "T'";
                    else
                    {
                        t += m[j];
                    }
                }

                string CH;
                if (ch == 'X')
                    CH += "E'";
                else if (ch == 'Y')
                    CH += "T'";
                else
                {
                    CH += ch;
                }

                cout << "\t\t" << CH << t << endl;
                t.clear();
            }
            else
            {
                cout << "\t出错！跳过当前符号，并继续分析" << endl;
                i = i + 1;
                flag = 1;
                //i = error(i, cnt, len, p, str);//未找到，报错
                continue;
            }
        }
        else
        {
            if (ch == str[i])
            {
                cmp.pop();
                string t;
                for (int j = 0; j < pindex; j++)
                {
                    if (p[j] == 'X')
                        t += "E'";
                    else if (p[j] == 'Y')
                        t += "T'";
                    else
                    {
                        t += p[j];
                    }
                }
                cout << cnt << "\t\t" << t << "\t\t";
                t.clear();
                if (ch == '$' && str[i] == '$')
                {
                    cout << "$\t\t接受" << endl;
                    return;
                }
                for (int q = i; q < len; q++)
                {
                    cout << str[q];
                }
                string temp;
                if (ch == 'X')
                    temp = "E\'";
                else if (ch == 'Y')
                    temp = "T\'";
                else
                    temp += ch;
                cout << "\t\t" << temp << "匹配" << endl;
                pindex--;
                p[pindex] = '\0';
                i++;
            }
            else
            {
                cout << "\t出错！跳过当前符号，并继续分析" << endl;
                i = i + 1;
                flag = 1;

                //i = error(i, cnt, len, p, str);//报错
                continue;
            }
        }
        cnt++;
    }
}

