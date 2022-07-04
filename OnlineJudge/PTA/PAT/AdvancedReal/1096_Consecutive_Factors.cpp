#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test;
    cin >> test;
    vector<int> seq;
    int limit = sqrt(test);
    int maxSeq = 0;
    int maxSeqPos = 0;
    int backup = test;
    seq.push_back(0);
    seq.push_back(0);
    for(int i = 2; i <= limit; i++)
    {
        if(test % i == 0)
        {
            seq.push_back(seq[i - 1] + 1);
            test /= i;
        }
        else
        {
            seq.push_back(0);
            test = backup;
        }
        if(seq[i] > maxSeq)
        {
            maxSeq = seq[i];
            maxSeqPos = i;
        }
    }
    if(maxSeq == 0)
    {
        cout << 1 << endl;
        cout << test << endl;
        return 0;
    }
    cout << maxSeq << endl;
    cout << maxSeqPos - maxSeq + 1;
    for(int i = 0; i < maxSeq - 1; i ++)
    {
        cout << "*" <<  maxSeqPos - maxSeq + 2 + i;
    }
    cout << endl;
    return 0;
}