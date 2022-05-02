#include<bits/stdc++.h>
using namespace std;

int mymap[110][110];
int st[110][110];
struct state
{
    state(int x, int y, int st):pos({x, y}), ks(st){}
    vector<int> pos;
    int ks;
};
queue<state> qu;
vector<int> bg, ed;
int n, m, k;

int touch(int x, int y)
{
    int count = 0;
    if(mymap[x - 1][y - 1] == '*')
        count ++;
    if(mymap[x + 1][y - 1] == '*')
        count ++;
    if(mymap[x - 1][y + 1] == '*')
        count ++;
    if(mymap[x + 1][y + 1] == '*')
        count ++;
    return count;
}

int bfs(int x, int y);

int main()
{
    char c;
    cin >> n >> m >> k;
    memset(mymap, 0, sizeof(mymap));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            cin >> c;
            mymap[i][j] = c;
            if(c == 'S')
                bg = {i, j};
            if(c == 'F')
                ed = {i, j};
        }
    for(int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        mymap[x][y] = '*';
    }

    qu.push(state(bg[0], bg[1], 0));
    cout << bfs() << endl;
        
    return 0;
}

int bfs()
{
    int x, y;
    while (1)
    {
        if(qu.size() == 0)
        {
            return -1;
        }
        state st = qu.front();
        qu.pop();
        //up
        if(mymap[st.pos[0]][st.pos[1] - 1] == '.') 
        {
            x = st.pos[0];
            y = st.pos[1] - 1;
            int count = touch(x, y);
            
        }

        //down
        if(mymap[st.pos[0]][st.pos[1] + 1] == '.') 
        {
            
        }

        //left
        if(mymap[st.pos[0] - 1][st.pos[1]] == '.') 
        {
            
        }

        //right
        if(mymap[st.pos[0] + 1][st.pos[1]] == '.') 
        {
            
        }
    }
    
}