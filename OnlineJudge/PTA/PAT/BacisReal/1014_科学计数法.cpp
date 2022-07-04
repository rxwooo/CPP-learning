    #include<bits/stdc++.h>
    using namespace std;

    int main()
    {
        string num = "";
        char flag1, flag2;
        int zhi;
        cin >> flag1;
        char in;
        cin >> in;
        num += in;
        cin >> in;
        while(cin >> in, in != 'E')
            num += in;
        cin >> flag2;
        cin >> zhi;
        if(flag1 == '-')
            cout << flag1;
        if(flag2 == '-')
        {
            cout << "0.";
            zhi --;
            while(zhi --)
                cout << "0";
            cout << num;
        }
        else
        {
            int len = num.size();
            for(int i = 0; i < len && i < zhi; i++)
                cout << num[i];
            if(zhi < len)
            {
                cout << ".";
                cout << num.substr(zhi + 1, len - 1 - zhi);
            }
            else
            {
                while(zhi-- >= len)
                    cout << "0";
            }
        }
        cout << endl;
        return 0;
    }