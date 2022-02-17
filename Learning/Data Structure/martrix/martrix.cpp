#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 12500
#define MAXLEN 120

struct Triple
{
    int i, j;
    int data;
};

struct SMatrix
{
    Triple data[MAXSIZE + 1];
    int rpos[MAXSIZE + 1];
    int mu, nu, tu; //矩阵行数，列数，非零元个数
};

//矩阵转置
void TransposeSMatrix(SMatrix &M, SMatrix &T)
{
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    if (T.tu)
    {
        int t = 1;
        for (int i = 1; i <= M.mu; i++)
        {
            for (int m = 1; m <= M.tu; m++)
            {
                if (M.data[m].j == i)
                {
                    T.data[t].i = M.data[m].j;
                    T.data[t].j = M.data[m].i;
                    T.data[t].data = M.data[m].data;
                    t++;
                }
            }
        }
    }
}

//快速矩阵转置
void FastTransposeSMatrix(SMatrix &M, SMatrix &T)
{
    T.mu = M.nu;
    T.nu = M.mu;
    T.tu = M.tu;
    int num[M.nu + 1];
    int cpot[T.nu + 1];
    if (T.mu)
    {
        //求出M中每一列所含非零元个数
        memset(num, 0, sizeof(num));
        for (int t = 1; t <= M.tu; t++)
            num[M.data[t].j]++;

        //求第col列中第一个非零元T中的序号
        cpot[1] = 1;
        for (int col = 2; col <= M.nu; col++)
            cpot[col] = cpot[col - 1] + num[col - 1];

        //矩阵转置
        for (int m = 1; m <= M.tu; m++)
        {
            int col = M.data[m].j;
            int t = cpot[col];

            T.data[t].i = M.data[m].j;
            T.data[t].j = M.data[m].i;
            T.data[t].data = M.data[m].data;
            cpot[col]++;
        }
    }
}

void MultSMatrix(SMatrix &M, SMatrix &N, SMatrix &Q)
{
    if (M.nu != N.mu)
        return;
    int ctemp[MAXSIZE + 1];
    int tm, tn;
    int col;

    Q.mu = M.mu;
    Q.nu = N.nu;
    Q.tu = 0;
    if (M.tu * N.tu != 0)
    {
        for (int ar = 1; ar <= M.mu; ar++)
        {
            memset(ctemp, 0, sizeof(ctemp));
            Q.rpos[ar] = Q.tu + 1;
            if (ar < M.mu)
                tm = M.rpos[ar + 1];
            else
                tm = M.tu + 1;
            for (int m = M.rpos[ar]; m < tm; m++)
            {
                int br = M.data[m].j;
                if (br <= N.mu)
                    tn = N.rpos[br + 1];
                else
                    tn = N.tu + 1;

                for (int n = N.rpos[br]; n < tn; n++)
                {
                    col = N.data[n].j;
                    ctemp[col] += M.data[m].data * N.data[n].data;
                }
            }
            for (col = 1; col <= Q.nu; col++)
            {
                if (ctemp[col])
                {
                    if (++Q.tu> MAXSIZE)
                        return;
                    Q.data[Q.tu] = {ar, col, ctemp[col]};
                }
            }
        }
    }
}

void CreatSMatrix(SMatrix &M)
{
    int col, raw, num;
    cout << "please input the col and raw of the matrix : ";
    cin >> col >> raw;
    cout << "please input the amount of non-zero element : ";
    cin >> num;
    M.mu = raw;
    M.nu = col;
    M.tu = num;
}

void SetSMatrix(SMatrix &M)
{
    int count;
    for (int i = 1; i <= M.tu; i++)
    {
        cout << "please input the position and value of element " << i << " : ";
        cin >> M.data[i].i >> M.data[i].j >> M.data[i].data;
    }
}

void SetRpos(SMatrix &M)
{
    int flag = 0;
    int vis[MAXSIZE+1];
    int count[MAXSIZE+1];
    memset(M.rpos,0,sizeof(M.rpos));
    memset(count,0,sizeof(count));
    memset(vis,0,sizeof(vis));
    vis[1] = 1;
    for (int i = 2; i <= M.tu; i++)
    {
        count[M.data[i].i]++;
        if(vis[M.data[i].i]==0)
            vis[M.data[i].i] = i;
    }
    
    for (int i = 1; i <= M.mu; i++)
        if(vis[i]==0)
            M.rpos[i] = vis[i - 1]+count[i-1];
        else
            M.rpos[i] = vis[i];

}

void SetTestSample(SMatrix &M)
{
    M.mu = 6;
    M.nu = 7;
    M.tu = 8;
    M.data[1] = {1, 2, 12};
    M.data[2] = {1, 3, 9};
    M.data[3] = {3, 1, -3};
    M.data[4] = {3, 6, 14};
    M.data[5] = {4, 3, 24};
    M.data[6] = {5, 2, 18};
    M.data[7] = {6, 1, 15};
    M.data[8] = {6, 4, -7};
}

void TestOuput(SMatrix &T)
{
    for (int i = 1; i <= T.tu; i++)
        cout << "( " << (T.data[i].i) << " , " << T.data[i].j << " , " << T.data[i].data << " )" << endl;
}



int main()
{
    SMatrix T, M;
    SetTestSample(M);
    SetRpos(M);

    cout << "Original Matrix is :" << endl;
    TestOuput(M);

    TransposeSMatrix(M, T);
    SetRpos(T);
    cout << "Matrix after transpose is :" << endl;
    TestOuput(T);
    cout<<endl;

    TransposeSMatrix(M, T);
    cout << "Matrix after fasttranspose is :" << endl;
    TestOuput(T);
    cout<<endl;

    cout<<"the two matrices above multiply is :"<<endl;
    SMatrix Q;
    SetRpos(M);
    SetRpos(T);
    MultSMatrix(M,T,Q);
    SetRpos(Q);
    TestOuput(Q);

    return 0;
}