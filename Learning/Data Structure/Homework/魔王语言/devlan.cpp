#include <bits/stdc++.h>
using namespace std;
using ElementType = char;

//�������ṹ�壬���ڴ洢���������
typedef struct LNode
{
    ElementType data;
    struct LNode *next;
    struct LNode *pre;
} * LinkList;
LinkList words;

//�������ȡ�ַ�����������洢
LinkList LLCreat()
{
    LinkList ll = new LNode;
    ElementType dt;
    LNode* re = ll;
    while(dt = getchar(),dt != '\n')
    {
        LNode *tp = new LNode;
        tp->data = dt;
        tp->pre = re;
        re->next = tp;
        re = re->next;
    }
    re->next = new LNode;
    re->next->next = NULL;
    return ll;
}


//ջ��ջ���ṹ��
typedef struct StNode
{
    StNode() {next = NULL;}
    ElementType data;
    StNode *next;
    StNode *pre;
} * Stack;

//�������꽫����������
void LNodeInsert(LinkList ll, int pos,ElementType dt)
{
    LNode *re = ll->next;
    for(int i = 1;i<pos;i++)
    {
        re = re->next;
    }
    LNode *tp = new LNode;
    if(re->next == NULL)
    {
        tp->next = NULL;
        tp->pre = re;
        tp->data = dt;
        re->next = tp;
    }
    else{
        tp->data = dt; 
        tp->pre = re;
        tp->next = re->next;
        re->next->pre = tp;
        re->next = tp;
    }
}

//��ջ
ElementType StPop(Stack st)
{
    ElementType dt;
    if (st->next)
    {
        StNode *ttp = st;
        StNode *tp = st->next;
        while(tp->next)
        {
            tp = tp->next;
            ttp = ttp->next;
        }
        dt = tp->data;
        ttp->next = NULL;
        delete tp;
    }
    else
    {
        return 0;
    }
    return dt;
}

//��ջ
void StPush(Stack st, ElementType data)
{
    StNode *tp = st;
    if (st->next)
    {
        while (tp->next)
            tp = tp->next;
        StNode *ttp = new StNode;
        ttp->data = data;
        tp->next = ttp;
        ttp->pre = tp;
        ttp->next = NULL;
    }
    else
    {
        tp = new StNode;
        tp->data = data;
        st->next = tp;
        tp->pre = st;
        tp->next = NULL;
    }
}

//ջ�ĳ�ʼ��
Stack StInit(Stack st)
{
    StNode *sn = st->next;
    if (!st)
    {
        st = new StNode;
        st->next = NULL;
    }
    else
    {
        StNode *tp = st->next;
        while (tp)
        {
            sn = tp;
            tp = tp->next;
            delete sn;
        }
        st->next=NULL;
    }
    return st;
}

//�ж�ջ�Ƿ�Ϊ��
bool StEmpty(Stack st)
{
    if(st->next)
        return 0;
    return 1;
}

//���ز�����������������data
ostream& operator << (ostream& os , LinkList ll)
{
    LNode *tp = ll->next;
    while(tp->next)
    {
        os << tp->data ;
        tp = tp->next;
    }
    return os;
}

//���������еĴ�д��ĸ
void ReplaceUP(LNode *qu)
{
    //��ȡ��ǰ��ĸ��ǰ����ĸ��ָ��
    LNode *qunext = qu->next;
    LNode *qupre = qu->pre;

    //��ĸA��B�ֱ��滻�����滻֮��������滻ԭ������ĸ���
    if (qu->data == 'A')
    {
        LNodeInsert(qupre, 1, 's');
        LNodeInsert(qupre, 2, 'a');
        LNodeInsert(qupre, 3, 'e');
        qupre->next = qu->next;
        qu->next->pre = qupre;
        delete qu;
    }
    else if (qu->data == 'B')
    {
        LNodeInsert(qupre, 1, 't');
        LNodeInsert(qupre, 2, 'A');
        LNodeInsert(qupre, 3, 'd');
        LNodeInsert(qupre, 4, 'A');
        qupre->next = qu->next;
        qu->next->pre = qupre;
        delete qu;
    }
}

//�滻�ַ����е������ڲ����ַ���
void ReplaceBR(LinkList qu)
{
    //��ȡ��ǰ�ַ�ǰ�ַ���ָ��
    LNode *qupre = qu->pre, *qunext;
    //�������žʹ���
    if (qu->data == '(')
    {
        LNode *tp = qu;            //��������ָ��
        Stack st = new StNode;     //����ջ���ڴ洢���ַ�֮����ַ�
        st = StInit(st);           //��ʼ��ջ
        if (qu->next->data == ')') //���������Ϊ�գ���������ţ���������
        {
            tp->pre->next = tp->next->next;
            tp->next->next->pre = tp->pre;
            delete tp;
            return;
        }
        ReplaceUP(qu->next);    //�������ַ�Ϊ��д�ַ������
        LNode seta = *qu->next; //��������ĸ�Ľ���ֵ
        tp = qu->next->next;    //��ʱָ��ָ��ڶ����ַ�
        tp->pre = qupre;        //�ڶ����ַ�ָ������ǰһ�ַ�
        LNode *de = qu->next;   //ָ�����ַ�
        delete qu;              //�ͷ����Ž��Ŀռ�

        //�����ҵ��������,���������н��ַ������ջ
        while (tp->data != ')')
        {
            LNode *de = tp;           //de����tp��������һ�����ͷſռ�
            StPush(st, tp->data);     //�ַ������ջ
            tp->pre->next = tp->next; //��������ǰ��
            tp->next->pre = tp->pre;  //�������Ӻ���
            tp = tp->next;            //����λ��
            delete de;                //�ͷſռ�
        }
        int count = 1;
        while (!StEmpty(st)) //�ַ�������ջ���������ַ�һ���������
        {
            LNodeInsert(qupre, count, seta.data);
            LNodeInsert(qupre, count + 1, StPop(st));
            count += 2;
        }
        LNodeInsert(qupre, count, seta.data); //�������һ������ĸ
        qupre->next = tp->next;
        tp->next->pre = qupre;
        delete tp;
    }
}

//�ڱ��������о����Ƿ���ַ������滻
LNode *Replace(LNode *tp)
{
    ReplaceUP(tp->next);
    ReplaceBR(tp->next);
    return tp;
}

//�����ַ��������д���
void TransHome()
{
    cout << "words before translate : ";
    words = LLCreat();
    LNode *tp = words;
    while (1)
    {
        tp = Replace(tp);
        tp = tp->next;
        if (!tp->next)
            break;
    }
}

int main()
{
    while (1)
    {
        TransHome();
        cout << endl;
        cout << "words atfer translate : ";
        cout << words << endl;
        cout << endl;
        cout << endl;
    }
    return 0;
}
//a(aA)b
//a(Ab)b
//A(AB)B
//(abcd)
//adacaba
//A(abcd)B
//saeadacabatsaedsae