#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    // role -> operator >> category -> name list
    unordered_map<string, bool> role;
    unordered_map<string, vector<string>> user2role;
    unordered_map<string, vector<string>> group2role;
    unordered_map<string, unordered_map<string, bool>> resourceList;
    unordered_map<string, unordered_map<string, bool>> categoryList;
    unordered_map<string, unordered_map<string, bool>> operatorList;
    unordered_map<string, unordered_map<string, unordered_map<string, unordered_map<string, bool>>>> mem;
    for (int i = 0; i < n; i++)
    {
        string roleName;
        cin >> roleName;
        role[roleName] = 1;
        int nv;
        cin >> nv;
        while (nv--)
        {
            string operatorName;
            cin >> operatorName;
            operatorList[roleName][operatorName] = 1;
            int no;
            cin >> no;
            while (no--)
            {
                string category;
                cin >> category;
                categoryList[roleName][category] = 1;
                int nn;
                cin >> nn;
                while (nn--)
                {
                    string resource;
                    cin >> resource;
                    resourceList[roleName][resource] = 1;
                }
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        string roleName;
        cin >> roleName;
        int ns;
        cin >> ns;
        while (ns--)
        {
            char c;
            string name;
            cin >> c;
            cin >> name;
            if (c == 'g')
                group2role[name].push_back(roleName);
            else
                user2role[name].push_back(roleName);
        }
    }
    while (q--)
    {
        queue<string> roleToDo;
        unordered_map<string, bool> chk;
        string user;
        cin >> user;
        for (string str : user2role[user])
            if (chk[str] == 0)
            {
                chk[str] = 1;
                roleToDo.push(str);
            }
        int ng;
        cin >> ng;
        while (ng--)
        {
            string group;
            cin >> group;
            for (string str : group2role[group])
                if (chk[str] == 0)
                {
                    chk[str] = 1;
                    roleToDo.push(str);
                }
        }
        string opName;
        string caName;
        string reName;
        cin >> opName >> caName >> reName;
        int res = 0;
        while (roleToDo.size() > 0)
        {
            string ro = roleToDo.front();
            roleToDo.pop();
            if(mem.find(ro) != mem.end())
            {
                if(mem[ro].find(opName) != mem[ro].end())
                {
                    if(mem[ro][opName].find(caName) != mem[ro][opName].end())
                    {
                        if(mem[ro][opName][caName].find(reName) != mem[ro][opName][caName].end())
                            res = mem[ro][opName][caName][reName];
                    }
                }
            }
            if (res)
                break;
            if (operatorList[ro].find(opName) == operatorList[ro].end())
            {
                if (operatorList[ro].find("*") == operatorList[ro].end())
                    continue;
            }
            if (categoryList[ro].find(caName) == categoryList[ro].end())
            {
                if (categoryList[ro].find("*") == categoryList[ro].end())
                    continue;
            }
            if (resourceList[ro].find(reName) == resourceList[ro].end())
            {
                if (resourceList[ro].size() > 0)
                    continue;
            }
            res = 1;
            mem[ro][opName][caName][reName] = 1;
        }
        cout << res << endl;
    }

    return 0;
}
// 1 2 3
// op 1 open 1 door 1 room302
// op 1 g sre
// op 1 u xiaop
// xiaoc 2 sre ops open door room302
// xiaop 1 ops open door room501
// xiaoc 2 sre ops remove door room302