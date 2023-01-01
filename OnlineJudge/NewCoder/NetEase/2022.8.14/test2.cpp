#include<bits/stdc++.h>
using namespace std;

struct unit
{
    unit():fire(0), hp(3){}
    unit(int f, int h):fire(f), hp(h){}
    int fire = 0;
    int hp = 3;
};

int main()
{
    int next[2][8] = {
        {-1, -1, -1, 0, 1, 1, 1, 0},
        {-1, 0, 1, 1, 1, 0, -1, -1}
    };
    unit myMap[202][202];
    unordered_map<int,vector<int>> fire;
    int food[202][202];
    int res = 0;
    memset(food, 0, sizeof(food));
    int w, h;
    cin >> w >> h;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y, t;
        cin >> x >> y >> t;
        myMap[x + 1][y + 1].hp = t;
        food[x + 1][y + 1] = t;
    }
    int m;
    cin >> m;
    while(m--)
    {
        int x, y, t;
        cin >> x >> y >> t;
        fire[t].push_back(x + 1);
        fire[t].push_back(y + 1);
    }
    int round = 1;
    while (1)
    {
        int fireCount = 0;
        int len = fire[round].size();
        for(int i = 0; i < len; i+=2)
        {
            int x = fire[round][i];
            int y = fire[round][i + 1];
            if(myMap[x][y].hp == 3)
            {
                myMap[x][y].fire = 5;
                myMap[x][y].hp --;
            }
        }
        for(int i = 1; i <= w; i++)
            for(int j = 1; j <= h; j++)
            {
                if(myMap[i][j].fire > 0)
                    for(int k = 0; k < 8; i++)
                        if( myMap[i + next[0][k]][j + next[1][k]].hp == 3 || 
                            (food[i + next[0][k]][j + next[1][k]] && myMap[i + next[0][k]][j + next[1][k]].hp == food[i + next[0][k]][j + next[1][k]])
                        )
                        {
                            myMap[i + next[0][k]][j + next[1][k]].fire = max(myMap[i][j].fire - 1, myMap[i + next[0][k]][j + next[1][k]].fire);
                        }
                if(food[i][j] && myMap[i][j].hp < food[i][j])
                {
                    fireCount ++;
                    myMap[i][j].hp --;
                    if(myMap[i][j].hp == 0)
                    {
                        food[i][j] = 0;
                        res++;
                    }
                }
            }
        if(fireCount == 0)
            break;
    }
    cout << res << endl;
    return 0;
}
                // if(myMap[i][j].hp == -5)
                // {
                //     myMap[i][j].hp = 3;
                // }
                // if(myMap[i][j].hp == 3)
                // {
                //     int maxFire = 0;
                //     for(int k = 0; k < 8; k++)
                //         maxFire = max(maxFire, myMap[i + next[0][k]][j + next[1][k]].fire);
                //     myMap[i][j].fire = maxFire;
                //     if(maxFire > 0)
                //         myMap[i][j].hp --;
                // }
                // if(myMap[i][j].fire > 0)
                // {
                //     myMap[i][j].fire --;
                // }
                // if(food[i][j] && myMap[i][j].hp < food[i][j])
                // {
                //     fireCount ++;
                //     myMap[i][j].hp --;
                //     if(myMap[i][j].hp == 0)
                //     {
                //         food[i][j] = 0;
                //         res++;
                //     }
                // }
                // else if(myMap[i][j].hp < 3 && myMap[i][j].hp >= -4)
                // {
                //     if(myMap[i][j].hp > 0)
                //         fireCount ++;
                //     myMap[i][j].hp --;
                // }