#include <bits/stdc++.h>
#include "LinkList.h"
#include "Stack.h"
using namespace std;

//结构体student作为链表结点的data的类型
struct student
{
    string name; //学生姓名
    bool operator==(student &s)
    {
        return name == s.name;
    }
    friend ostream &operator<<(ostream &os, student &st)
    {
        return os << "the name of this student is : " << st.name;
    }
};

Stack<student> recycle;
Linklist<student> database;

//插入学生信息，默认插到序列末尾
void StudentInsert(string &s, int pos = database.len, Linklist<student> &da = database)
{
    student *st = new student;
    st->name = s;
    LListInsert(da, pos, *st);
}

//通过序号显示学生信息，默认为序列末尾的学生
void DisplayStudent(int pos = database.len)
{
    student st = LListGetData(database, pos);
    cout << st.name << endl;
}

//通过序号删除指定学生信息，默认为序列末尾学生
bool DeleteStudentByNum(Stack<student> &re = recycle, Linklist<student> &da = database)
{
    int pos;
    cout << "input the number you want to delete : ";
    cin >> pos;
    if (pos > database.len)
    {
        cout << "not so many student" << endl;
        return 0;
    }
    else if (pos <= 0)
    {
        cout << "please input a right number" << endl;
        return 0;
    }
    LLnode<student> *de = new LLnode<student>;
    (*de) = LListDeletByNum(da, pos);
    if (de->data.name == "")
        return 0;
    Push(re, de->data);
    re.l->tail->pos = de->pos;
    return 1;
}

//删除最后一个学生
bool DeleteStudent(Stack<student> &re = recycle, int pos = database.len, Linklist<student> &da = database)
{
    LLnode<student> *de = new LLnode<student>;
    (*de) = LListDeletByNum(da, pos);
    if (de->data.name == "")
        return 0;
    Push(re, de->data);
    re.l->tail->pos = de->pos;
    return 1;
}

//通过学生姓名删除序列中的学生
bool DeleteStudentByName(Linklist<student> &da = database, Stack<student> &re = recycle)
{
    string s;
    cout << "please the name of the student you want to delete : ";
    cin >> s;
    LLnode<student> *de = new LLnode<student>;
    student *st = new student;
    st->name = s;
    (*de) = LListDeleteByValue(da, *st);
    if (de->data.name == "")
        return 0;
    Push(re, de->data);
    re.l->tail->pos = de->pos;
    return 1;
}

//撤销对学生信息的删除
string &RestoreStudent(Linklist<student> &da = database, Stack<student> &re = recycle)
{
    LLnode<student> *rs = new LLnode<student>;
    (*rs) = Pop(re);
    LListInsert(da, rs->pos - 1, rs->data);
    return rs->data.name;
}

void ShowStatus()
{
    cout << endl;
    cout << "  Student(s) in the system : " << database.len << endl;
    cout << "  Student(s) was deleted : " << recycle.l->len << endl;
}

student &Getstudent(unsigned num, Linklist<student> &da = database)
{
    return LListGetData(da, num);
}

//主页
void homepage();

void input()
{
    string name;
    cout << "    input the name to insert or input \"homepage\" to back to the homepage : ";
    while (cin >> name)
    {
        cout << endl;
        if (name == "homepage")
            homepage();
        StudentInsert(name);
        cout << "    success" << endl;
        ShowStatus();
        cout << endl;
        cout << "    input the name to insert or input \"homepage\" to back to the homepage : ";
    }
}

void de()
{
    cout << "select the method to delete : " << endl;
    cout << "    numb --delete the student by the number" << endl;
    cout << "    name --delelt the student by name ( delete only one in one time )" << endl;
    cout << "    last --delete the last one" << endl;
    cout << "    home --back to the homepage" << endl;

    string cm;
    while (cin >> cm)
    {
        int flag = 0;
        int ck = 1;
        if (cm == "numb")
        {
            ck = DeleteStudentByNum();
        }
        else if (cm == "name")
        {
            ck = DeleteStudentByName();
        }
        else if (cm == "last")
        {

            ck = DeleteStudent();
        }
        else if (cm == "home")
            homepage();
        else
        {
            cout << "error command" << endl;
            continue;
        }
        if (ck)
        {
            cout << "delete successfully!" << endl;
            ShowStatus();
        }
        else
        {
            cout << "delete error! no such student or other error" << endl;
        }
    }
}

void restore()
{
    if (recycle.l->len == 0)
    {
        cout << "no student can be restored" << endl;
    }
    string name = RestoreStudent();
    cout << "the student has been restored is " << name << endl;
    cout << "restore successfully!" << endl;
}

void query()
{
    string cm;
    cout << "  please select the method you want to query : " << endl;
    cout << "      numb --query the information of the specified student" << endl;
    cout << "      all  --quety all the student(s)" << endl;
    cout << "      home --back to the homepage" << endl;
    cout << endl;
    while (cin >> cm)
    {
        if (cm == "numb")
        {
            int num;
            cout << "please input the num of the stuendt you want";
            cin >> num;
            if (num > database.len)
            {
                cout<<"not so many student"<<endl;
                continue;
            }
            else if(num<=0) 
            {
                cout<<"number error"<<endl;
                continue;
            }
            cout << Getstudent(num) << endl;
        }
        else if (cm == "all")
        {
            for (int i = 1; i <= database.len; i++)
            {
                cout << "Order " << i << endl;
                cout << "    " << Getstudent(i) << endl;
            }
        }
        else if (cm == "home")
        {
            homepage();
        }
        else
        {
            cout << "error aommand" << endl;
        }
    }
}

bool command(string &cm)
{
    if (cm == "input")
    {
        input();
        return 0;
    }
    else if (cm == "delete")
    {
        de();
        return 0;
    }
    else if (cm == "restore")
    {
        restore();
        return 0;
    }
    else if (cm == "show")
    {
        ShowStatus();
        return 0;
    }
    else if (cm == "exit")
    {
        exit(0);
        return 0;
    }
    else if (cm == "query")
    {
        query();
        return 0;
    }
    return 1;
}

void homepage()
{
    cout << endl;
    cout << "  please input the command :" << endl;
    cout << "      input   : input the name and the student will be inserted" << endl;
    cout << "      delete  : delete a student ( can be specified or default the last )" << endl;
    cout << "      restore : undo the last deletion of student ( cannot specify the order )" << endl;
    cout << "      query   : query the information of the specified student" << endl;
    cout << "      show    : display the status of system" << endl;
    cout << "      exit    : exit the program " << endl;
    cout << endl;

    string cm;
    int ck = 0;
    while (cin >> cm)
    {
        ck = command(cm);
        if (ck)
            cout << "error command" << endl;
    }
}

int main()
{
    homepage();
    return 0;
}