#include <bits/stdc++.h>
using namespace std;

using ElementType = char;

string str;
int wei[1000];    //�洢�����Ȩ��
char c[1000];     //�����ڴ������ڱ�����ַ�
int vis[1000];    //����ز��������ڱ��
char *code[1000]; //���ڱ���ÿ���ַ���Ӧ�ı���
int HuffmanLen;   //��ǰ�ַ��ĸ���

//���������Ľ��
typedef struct HFnode
{
    HFnode()
    {
        parent = NULL;
        lchild = NULL;
        rchild = NULL;
        data = -1;
    }
    ElementType data;
    int we;
    HFnode *parent;
    struct HFnode *lchild;
    struct HFnode *rchild;
} HFnode, *HFTree;
typedef void (*func)(HFTree);

HFTree HuffmanNode[1000]; //������������ĸ����
HFTree HuffmanTree;       //�ڴ��ܱ�����ܹ�������

//ɾ�������������
void HuffmanDel(HFTree n);

//�Թ�������������������Խ����п�ѡ�ĺ�������
void HuffmanTra(HFTree t, func fun);

//��ȡ�û��������ݲ����棬���ڴ�����������
int datainput();

//��ȡToBeTran.txt�ļ��������ر������ļ����ݵ��ַ���
char *ToBeTranLoad();

//��ȡCodeFile.txt�ļ������ر������ļ����ݵ��ַ���
char *CodeFileLoad();

//���ؽ��������Ȩ����С�Ľ���λ�ã�����conΪѡ�����ų��ĵ�λ��
int HuffmanMinVal();

//������������ݴ�����������
void HuffmanCreate();

//���ݹ��������������������룬������str�ַ�������
//�����ֱ�Ϊ�������������ڴ�����ǰ�ַ�������������ַ���
void HuffmanCodeBuild(HFTree t, char *s);

//�������������Ĺؼ���Ϣ��hfmTree.txt��
void HuffmanFileOut();

//�������������Ĺؼ���Ϣ��hfmTree.txt��
void HuffmanFileOut();

//����hfmTree.txt�е���Ϣ
bool HuffmanLoad();

//����hfmTree.txt�е���Ϣ
bool HuffmanLoad();

//�Դ�����ַ������б���
void HuffmanEncode(char *s);

//���ú�����ʹ�õ������Ϣ�����������
void HuffmanBuild();

//�ݹ鹹���������
void HuffmanBdTra(HFTree r, char *BDstr, char dt);

//�Դ���Ĺ���������н���
void HuffmanDecode(char *s);

//�Դ���Ĺ���������н���
void HuffmanDecode(char *s);

//�ݹ��������,��ĩ�˽���data���뵽�����
int HuffmanDcTra(HFTree t, char *s, int num, ostream &os);

//��ӡ���������İ���ɲ������ļ�
void HuffmanDisplay();

//�����������ÿ���ַ����а������
void HuffmanTable(HFTree t, int num, int flag, ostream &os);

//��ӡ�ַ������Ӧ���뵽�ն�
void huaffmanShow();

//��ȡ���б�����ַ���
char *GetEncodeStr();

//��ȡ���н�����ַ���
char* GetDecodeStr();

//���������ҳ��������ʾ�û����������ʽ���͸�ѡ�������
void HuffmanHomepage()
{
    int ck = 1;         //������ĳЩ�������Ƿ�ɹ������ļ��еĹ�������
    char et[100] = {0}; //���ڶ�ȡ�û���ѡ�����ѡ���ж�
    char *strenc;

    //����ѭ����ʹ�����ܳ�������
    while (1)
    {
        memset(et, 0, sizeof(et)); //ÿ���ж�ǰ��������жϵ��ַ�����
        cout << "------------------------------------------------------------" << endl;
        cout << "-please enter the num to choose the faction :              -" << endl;
        cout << "-    I - Initializing Huffman tree.                        -" << endl;
        cout << "-    E - Encoding the ToBeTran.txt.                        -" << endl;
        cout << "-    D - Decoding the CodeFile.txt.                        -" << endl;
        cout << "-    P - Printing the CodeFile.txt in the terminal.        -" << endl;
        cout << "-    T - Printing and saving the HuffmanTree table.        -" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << endl;
        cout<<"enter your choice : ";
        cin>>et;

        cout << endl;

        if (et[0] == 'I') //ѡ���˶Թ����������г�ʼ������������
        {
            HuffmanTra(HuffmanTree, HuffmanDel); //ɾ���ڴ���ԭ�й�������
            datainput();                         //���¹���������������
            HuffmanCreate();                     //������������
            HuffmanCodeBuild(HuffmanTree, "");   //���ڴ��������������й��������빹��
            HuffmanFileOut();                    //�����������뼰��Ӧ�ַ������ļ�
            huaffmanShow();                      //��ӡ�ַ������Ӧ���뵽�ն�
        }
        else if (et[0] == 'E') //���ļ��е����Ľ��б���
        {
            if (HuffmanLen == 0) //��������������ڴ�ʹ��ļ��м���
            {
                ck = HuffmanLoad(); //�����ļ��еĹ�������
                if (!ck)            //�ļ�����ʧ�ܾ���ֹ���β���
                    continue;
                cout << "a new huffmanTree will be created" << endl;
                HuffmanBuild();   //�����ļ��ж�ȡ�Ĺ�����������Ϣ�����������
                HuffmanFileOut(); //��������������Ӧ�ַ������ļ�
            }
            strenc = GetEncodeStr();
            HuffmanEncode(strenc); //����ToBeTranc�е����Ĳ����б���
            cout<<endl;
        }
        else if (et[0] == 'D') //���ļ��еĹ���������н���
        {
            if (HuffmanLen == 0) //��������������ڴ�ʹ��ļ��м���
            {
                ck = HuffmanLoad(); //�����ļ��еĹ�������
                if (!ck)            //�ļ�����ʧ�ܾ���ֹ���β���
                    continue;
                cout << "a new huffmanTree will be created" << endl;
                HuffmanBuild();   //�����ļ��ж�ȡ�Ĺ�����������Ϣ�����������
                HuffmanFileOut(); //��������������Ӧ�ַ������ļ�
            }
            strenc = GetDecodeStr();
            HuffmanDecode(strenc); //����CodeFile�еĹ���������н���
            cout << " CodeFile.txt decode completed" << endl;
        }
        else if (et[0] == 'P') //��CodeFile�еĹ����������뵽�ն˺ʹ����ļ�
        {
            cout << CodeFileLoad() << endl;
            fstream f("CodePrin.txt", ios::out | ios_base::trunc);
            if (!f)
            {
                cout << "CodePrin.txt open error" << endl;
                break;
            }
            f << CodeFileLoad() << endl;
            f.close();
        }
        else if (et[0] == 'T') //�����������İ�����ӡ���ն˲������ļ�
        {
            HuffmanDisplay();
        }
        else //�����������ٴν������
        {
            HuffmanHomepage();
        }
    }
}

int main()
{
    HuffmanLen = 0;
    HuffmanHomepage();
    return 0;
}

// 5
// a(1) b(2) c(3) d(4) e(5)

//ɾ�������������
void HuffmanDel(HFTree n)
{
    if (n)
    {
        if (n->parent->lchild == n)
            n->parent->lchild == NULL;
        if (n->parent->rchild == n)
            n->parent->rchild == NULL;
        delete n;
    }
}

//�Թ�������������������Խ����п�ѡ�ĺ�������
void HuffmanTra(HFTree t, func fun)
{
    if (t)
    {
        fun(t);
        if (t->lchild)
            HuffmanTra(t->lchild, fun);
        if (t->rchild)
            HuffmanTra(t->rchild, fun);
    }
}

//��ȡ�û��������ݲ����棬���ڴ�����������
int datainput()
{
    cout << "Please enter the number of characters : ";
    cin >> HuffmanLen;
    if (HuffmanLen < 1)
        return HuffmanLen;
    for (int i = 0; i < HuffmanLen; i++)
    {
        cout << "Please enter the value and weight of character " << i + 1 << " : ";
        cin >> c[i] >> wei[i];     //���ַ��Ͷ�ӦȨ�ش�������
        HFnode *node = new HFnode; //�������ռ�
        node->data = c[i];         //����Ӧ�ַ��������data
        node->we = wei[i];         //���ַ���ӦȨ�ش����wei
        HuffmanNode[i] = node;     //����㱣�浽�������������
    }
    c[HuffmanLen] = 0; //���ַ������ĩβ����Ϊ0
    return HuffmanLen; //���ع��������ĳ���
}
//��ȡ���н�����ַ���
char* GetDecodeStr()
{
   while (1)
    {
        cout << "1. using CodeFile file" << endl;
        cout << "2. using your own string " << endl;
        cout << "3. back to previous" << endl;
        cout << endl;
        cout << "enter yout choice : ";
        int ck;
        cin >> ck;
        if (ck == 1)
        {
            char * str = CodeFileLoad();
            cout<< " string to be decode is : "<<str<<endl;
            cout<<endl;
            cout<<endl;
            return str;
        }
        else if (ck == 2)
        {
            cout << "please input your string :";
            char *str = new char[1000];
            cin >> str;
            return str;
        }
        else if (ck == 3)
        {
            HuffmanHomepage();
        }
    } 
}

//��ȡ���б�����ַ���
char *GetEncodeStr()
{
    while (1)
    {
        cout << "1. using ToBeTran file" << endl;
        cout << "2. using your own string " << endl;
        cout << "3. back to previous" << endl;
        cout << endl;
        cout << "enter yout choice : ";
        int ck;
        cin >> ck;
        if (ck == 1)
        {
            char * str = ToBeTranLoad();
            cout<< " string to be encode is : "<<str<<endl;
            cout<<endl;
            cout<<endl;
            return str;
        }
        else if (ck == 2)
        {
            cout << "please input your string :";
            char *str = new char[1000];
            cin >> str;
            return str;
        }
        else if (ck == 3)
        {
            HuffmanHomepage();
        }
    }
}

//��ȡToBeTran.txt�ļ��������ر������ļ����ݵ��ַ���
char *ToBeTranLoad()
{
    FILE *f;
    f = fopen("ToBeTran.txt", "r");
    if (f == NULL)
    {
        cout << "open file failed" << endl;
        return NULL;
    }
    char *TranStr = new char[1000]; //�����ַ�����ռ䱣���ļ�����
    memset(TranStr, 0, sizeof(TranStr));
    fscanf(f, "%s", TranStr);
    fclose(f);
    return TranStr;
}

//��ȡCodeFile.txt�ļ������ر������ļ����ݵ��ַ���
char *CodeFileLoad()
{
    FILE *f;
    f = fopen("CodeFile.txt", "r");
    if (f == NULL)
    {
        cout << "open file failed" << endl;
        return NULL;
    }
    char *CodeStr = new char[1000]; //�����ַ�����ռ䱣���ļ�����
    memset(CodeStr, 0, sizeof(CodeStr));
    fscanf(f, "%s", CodeStr);
    fclose(f);
    return CodeStr;
}

//���ؽ��������Ȩ����С�Ľ���λ�ã�����conΪѡ�����ų��ĵ�λ��
int HuffmanMinVal()
{
    if (HuffmanLen)
    {
        int minwe;
        int pos = -1;
        int flag = 0;
        for (int i = 0; i < HuffmanLen; i++)
        {
            if (vis[i]) //��ǹ���λ�ò�����ѡ��
                continue;
            //��һ�ν���ѭ��ʱ�����浽��Сֵ����Ϊ��һ��
            if (!flag)
            {
                minwe = HuffmanNode[i]->we;
                pos = i;
                flag = 1;
            }
            //�Ƚ�Ȩ�أ�������С��Ȩ�غ���Ӧλ��
            if (HuffmanNode[i]->we < minwe)
            {
                minwe = HuffmanNode[i]->we;
                pos = i;
            }
        }
        return pos; //������С�ĵ�����
    }
    return -1;
}

//������������ݴ�����������
void HuffmanCreate()
{
    memset(vis, 0, sizeof(vis));
    HFnode *tp;
    int count = 1;
    int last, seclast = -1; //�ֱ����ڱ��浱ǰȨ����С�͵ڶ�С�Ľ��λ��
    while (count < HuffmanLen)
    {
        last = HuffmanMinVal();                                    //����Ȩ����С�Ľ��
        vis[last] = 1;                                             //��Ǵ�λ�ò�����֮���ѡ��
        seclast = HuffmanMinVal();                                 //����Ȩ�صڶ�С�Ľ��
        HFTree ht = new HFnode;                                    //���ٿռ���Ϊ�µ������
        ht->lchild = HuffmanNode[seclast];                         //������Ϊ�ڶ�С�Ľ��
        ht->rchild = HuffmanNode[last];                            //������Ϊ���µĽ��
        ht->we = HuffmanNode[last]->we + HuffmanNode[seclast]->we; //�½���Ȩ��Ϊ��������Ȩ��֮��
        HuffmanNode[seclast] = ht;                                 //�����µĽ���ڵڶ�С�Ľ���λ��
        count++;
    }
    //���û�вμ�ѡ�񣬹���������ֻ�н��������׽��
    if (seclast == -1)
    {
        HuffmanTree = HuffmanNode[0];
    }
    //����ͷ��ص�ǰ��������µ���
    else
    {
        HuffmanTree = HuffmanNode[seclast];
    }
}

//���ݹ��������������������룬������str�ַ�������
//�����ֱ�Ϊ�������������ڴ�����ǰ�ַ�������������ַ���
void HuffmanCodeBuild(HFTree t, char *s)
{
    if (t)
    {
        if (t->lchild)
        {
            //������������ڣ��ڵ�ǰ�ַ���֮ǰ��һ��0,��������һ�εݹ�
            char *str = new char[strlen(s) + 2];
            strcpy(str, s);
            str[strlen(s)] = '0';
            str[strlen(s) + 1] = 0;
            HuffmanCodeBuild(t->lchild, str);
        }
        if (t->rchild)
        {
            //������������ڣ��ڵ�ǰ�ַ���֮ǰ��һ��0,��������һ�εݹ�
            char *str = new char[strlen(s) + 2];
            strcpy(str, s);
            str[strlen(s)] = '1';
            str[strlen(s) + 1] = 0;
            HuffmanCodeBuild(t->rchild, str);
        }
        //ѭ����ĩβ�����Ϊ�������ַ����޺��ӽ��
        if (t->lchild == NULL && t->rchild == NULL)
        {
            for (int i = 0; i < HuffmanLen; i++)
            {
                if (t->data == c[i])
                {
                    code[i] = s;
                    break;
                }
            }
        }
    }
}

//�������������Ĺؼ���Ϣ��hfmTree.txt��
void HuffmanFileOut()
{
    cout << endl;
    FILE *f;
    f = fopen("hfmTree.txt", "wb");
    if (f == NULL)
    {
        cout << "open file failed" << endl;
        return;
    }
    fprintf(f, "%d\n", HuffmanLen);
    //ͨ��ѭ������Ϣ�����ļ�
    for (int i = 0; i < HuffmanLen; i++)
    {
        fprintf(f, "%c %s\n", c[i], code[i]);
    }
    fclose(f);
    cout << "Huffman Save Completed " << endl;
    cout << endl;
    cout << endl;
}

//��ӡ��ĸ�Լ���Ӧ����
void huaffmanShow()
{
    for (int i = 0; i < HuffmanLen; i++)
    {
        printf("%c ---- %s\n", c[i], code[i]);
    }
    cout << endl;
    cout << endl;
}

//����hfmTree.txt�е���Ϣ
bool HuffmanLoad()
{
    memset(c, 0, sizeof(c));
    memset(code, 0, sizeof(code));
    FILE *f;
    f = fopen("hfmTree.txt", "r");
    if (f == NULL)
    {
        cout << "open file failed" << endl;
        return 0;
    }
    char ck;
    ck = fgetc(f);
    //����ļ���ͷΪ������ֹ����
    if (ck <= 0 || ck == '\n')
    {
        cout << "File Empty" << endl;
        return 0;
    }
    HuffmanLen = ck - '0';
    for (int i = 0; i < HuffmanLen; i++)
    {
        fgetc(f);
        c[i] = fgetc(f);
        fgetc(f);
        char *strL = new char[1000];
        fscanf(f, "%s", strL);
        code[i] = strL;
    }
    c[HuffmanLen] = 0;
    return 1;
}

//�Դ�����ַ������б���
void HuffmanEncode(char *s)
{
    fstream f("CodeFile.txt", ios::out);
    if (!f)
    {
        cout << "open file failed" << endl;
        return;
    }
    int len = strlen(s);
    cout<<"the result is : ";
    //���ϲ��Ҵ������ַ������ڴ��еĶ�Ӧ����
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < HuffmanLen; j++)
        {
            if (s[i] == c[j])
            {
                f << code[j];
                cout<<code[j];
                break;
            }
        }
    }
    f.close();
    cout<<endl;
    cout << "ToBeTran.txt encode completed " << endl;
}

//�ݹ鹹���������
void HuffmanBdTra(HFTree r, char *BDstr, char dt)
{
    //�ַ���Ϊ��ʱ�����ݹ鲢����Ϣ������
    if (*BDstr == '\0')
    {
        r->data = dt;
    }
    else
    {
        //��ǰ���ַ�Ϊ1�ͷ�����������Ϊ0�ͷ������������ַ���ǰ��һ���ַ�
        //������������ھ͹���һ���µĽ��

        if (*BDstr == '1')
        {
            if (!r->rchild)
            {
                HFnode *tp = new HFnode;
                tp->parent = r;
                r->rchild = tp;
            }
            HuffmanBdTra(r->rchild, BDstr + 1, dt);
        }
        else if (*BDstr == '0')
        {
            if (!r->lchild)
            {
                HFnode *tp = new HFnode;
                tp->parent = r;
                r->lchild = tp;
            }
            HuffmanBdTra(r->lchild, BDstr + 1, dt);
        }
    }
}

//���ú�����ʹ�õ������Ϣ�����������
void HuffmanBuild()
{
    HuffmanTree = new HFnode;
    //����ÿһ���ַ��Ͷ�Ӧ�ַ�������һ��
    for (int i = 0; c[i] != 0; i++)
    {
        HuffmanBdTra(HuffmanTree, code[i], c[i]);
    }
}

//�ݹ��������,��ĩ�˽���data���뵽����������ص�ǰ���������
int HuffmanDcTra(HFTree t, char *s, int num, ostream &os)
{
    if (t)
    {
        if (t->lchild == NULL && t->rchild == NULL)
        {
            os << t->data;
            cout<< t->data;
            return num;
        }
        if (s[num] == '0')
        {
            return HuffmanDcTra(t->lchild, s, num + 1, os);
        }
        if (s[num] == '1')
        {
            return HuffmanDcTra(t->rchild, s, num + 1, os);
        }
    }
    return num;
}

//�Դ���Ĺ���������н���
void HuffmanDecode(char *s)
{
    //�ַ���Ϊ�վ���ֹ����
    if (s == NULL)
    {
        cout << "HuffmanCode Load Error" << endl;
        return;
    }
    fstream f("TextFile.txt", ios::out | ios_base::trunc);
    int len = strlen(s);
    cout<<"the result is : ";
    for (int i = 0; i < len - 1;)
    {
        i = HuffmanDcTra(HuffmanTree, s, i, f);
    }
    f.close();
    cout<<endl;
    cout << endl;
}

//�����������ÿ���ַ����а������
void HuffmanTable(HFTree t, int num, int flag, ostream &os)
{
    //flag����ж���������
    //num����ÿ��������ʱǰ�Ŀո�
    //osΪ����������
    if (t)
    {
        for (int i = 0; i < num * 4; i++)
        {
            cout << " ";
            os << " ";
        }
        if (t->lchild == NULL && t->rchild == NULL)
        {
            cout << t->data << " (" << flag << ")"
                 << "--------------------" << endl;
            os << t->data << " (" << flag << ")"
               << "--------------------" << endl;
        }
        else
        {
            cout << "NULL"
                 << " (" << flag << ")"
                 << "--------------------" << endl;
            os << "NULL"
               << " (" << flag << ")"
               << "--------------------" << endl;
        }

        if (t->lchild)
        {
            HuffmanTable(t->lchild, num + 1, 0, os);
        }
        if (t->rchild)
        {
            HuffmanTable(t->rchild, num + 1, 1, os);
        }
    }
}

//��ӡ���������İ���ɲ������ļ�
void HuffmanDisplay()
{
    if (HuffmanLen == 0) //�ڴ��в����ڹ��������ʹ��ڴ浼��
    {
        cout << "Find HuffmamTree in File" << endl;
        HuffmanLoad();
        HuffmanBuild();
    }
    fstream f("TreePrint.txt", fstream::out | ios_base::trunc);
    if (!f)
    {
        cout << "TreePrint.txt open error" << endl;
        return;
    }
    HuffmanTable(HuffmanTree, 0, -1, f);
    f.close();
    cout << "HuffmanTree Table saved completed" << endl;
}
