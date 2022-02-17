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
    char S; //�ķ��Ŀ�ʼ����
    map<char, set<string> > P;
    map<char, set<char> > FIRST;
    map<char, set<char> > FOLLOW;
    map<string, string> Table;
    vector<char> X;              //�����ս������>����
    vector<char> Y;              //������ս������>����
    vector<vector<string> > rule; //�������ʽ����
    stack<char> cmp;
    int eli_flag = 0; //������־

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
    void remove_left_gene(char c); //��ȡ������
    void ShowByTogether();
    int findH(char a);
    int findL(char b);
    void analyze(char str[], int len); //Ԥ�����
};

int main()
{

    string filename_gramer = "ר��6.txt";
    Grammar* grammar = new Grammar(filename_gramer);
    cout << endl;
    cout << "������ݹ�ǰ"<< endl;
    cout <<  endl;
    cout << "��ʼ�ķ���ʾ��" << endl;
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
    cout << "������ݹ��" << endl;
    cout << endl;

    // ������ݹ�֮����ж�
    grammar->remove_left_recursion();
    cout << "���ƺ��ķ���ʾ��" << endl;
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

    cout << "/��������������������������������������������������������������������������������������������������������������������/" << endl;
    cout << "/***************************************************Ԥ�����********************************************************/" << endl;
    cout << "/��������������������������������������������������������������������������������������������������������������������/" << endl;
    string str1;
    getline(cin, str1);
    char* str = (char*)str1.c_str();
    int len = strlen(str);

    grammar->analyze(str, len + 1);
    if (grammar->flag == 1)
        cout << "\n��ǰ��䲻�Ϸ�!" << endl;
    else
        cout << "\n��ǰ���Ϸ�!" << endl;
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
        ifstream in("ר��6.txt");
        if (!in.is_open())
        {
            cout << "�ķ�  �ļ���ʧ��" << endl;
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
            ���Vn��Vt��set

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
    cout << "��ǰ�����ķ�Ϊ��" << endl
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
    //�жϵ�������
    int iter = 4;
    while (iter--)
    {
        for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
        {
            char cur_s = *it;
            /*
                cur_s->cur_string[0]
                    a�ӵ�A��FIRST��
                cur_s->cur_string[0]
                    B��FITRST���ӵ�A��FIRST��
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
    //���FIRST��
    cout << "FIRST��Ϊ��" << endl;
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
    //�жϵ�������
    int iter = 4;
    while (iter--)
    {
        for (set<char>::iterator it = Vn.begin(); it != Vn.end(); it++)
        {
            char cur_s = *it;
            /*
                cur_s->cur_string[0]
                a�ӵ�A��FIRST��
                cur_s->cur_string[0]
                B��FITRST���ӵ�A��FIRST��
                */
            for (set<string>::iterator it1 = P[cur_s].begin(); it1 != P[cur_s].end(); it1++)
            {
                string cur_string = *it1;
                for (int i = 0; i < cur_string.length() - 1; i++)
                {
                    /*
                            B->Ac
                            ��c�ӵ�A��follow��
                        */
                    if (isupper(cur_string[i]) && !isupper(cur_string[i + 1]))
                    {
                        FOLLOW[cur_string[i]].insert(cur_string[i + 1]);
                    }
                    /*
                            B->AC
                            ��C��first���ӵ�A��follow��
                        */
                    if (isupper(cur_string[i]) && isupper(cur_string[i + 1]))
                    {
                        //����C��firstȥ��#���ӵ�A��follow��
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
    //���FOLLOW��
    cout << "FOLLOW��Ϊ��" << endl;
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
                ����ʽΪ
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
            ��������Ϣ���������û�г��ֹ���
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
            ��ʾTable
        */
    cout << "�ķ�������" << endl
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
        ������ݹ�
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
    for (int i = 0; i < 7; i++) //�ҵ���Ӧ��
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
    for (int i = 0; i < 8; i++) //�ҵ���Ӧ��
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
    int cnt = 1; //���Step
    int i = 0;
    char p[200] = "$E"; //���stack
    int pindex = 2;
    cout << "����\t\tջ\t\t�ַ���\t\t����" << endl;
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
                    cout << "\t����������ǰ���ţ�����������" << endl;
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
                        cmp.push(rule[x][y][q]); //��ջ
                    }
                }
                else
                {
                    p[pindex] = '\0';
                    pindex;
                }
                for (int q = i; q < len; q++)
                {
                    cout << str[q]; //���ʣ�����봮
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
                cout << "\t����������ǰ���ţ�����������" << endl;
                i = i + 1;
                flag = 1;
                //i = error(i, cnt, len, p, str);//δ�ҵ�������
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
                    cout << "$\t\t����" << endl;
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
                cout << "\t\t" << temp << "ƥ��" << endl;
                pindex--;
                p[pindex] = '\0';
                i++;
            }
            else
            {
                cout << "\t����������ǰ���ţ�����������" << endl;
                i = i + 1;
                flag = 1;

                //i = error(i, cnt, len, p, str);//����
                continue;
            }
        }
        cnt++;
    }
}

