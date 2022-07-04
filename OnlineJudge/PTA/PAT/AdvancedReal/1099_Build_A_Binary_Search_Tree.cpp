#include<bits/stdc++.h>
using namespace std;


void midTra(unordered_map<int, vector<int>>& tree, int root, vector<int>& index)
{
    if(root == -1)
        return;
    midTra(tree, tree[root][0], index);
    index.push_back(root);
    midTra(tree, tree[root][1], index);
}

int main()
{
    vector<int> index;
    unordered_map<int, vector<int>> nodes;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        nodes[i] = {l, r};
    }
    midTra(nodes, 0, index);
    vector<int> value(n);
    for(int i = 0; i < n; i++)
        cin >> value[i];
    sort(value.begin(), value.end());
    for(int i = 0; i < n; i++)
        nodes[index[i]].push_back(value[i]);
    queue<int> tra;
    tra.push(0);
    int last = 1;
    int count = 0;
    while(last)
    {
        while(last--)
        {
            cout << nodes[tra.front()][2];
            count ++;
            if(count != n)
                cout << " ";
            if(nodes[tra.front()][0] != -1)
                tra.push(nodes[tra.front()][0]);
            if(nodes[tra.front()][1] != -1)
                tra.push(nodes[tra.front()][1]);
            tra.pop();
        }
        last = tra.size();
    }
    return 0;
}