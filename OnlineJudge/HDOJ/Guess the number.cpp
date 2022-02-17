#include <stdio.h>
#include <string.h>
//const int maxn = 100 + 5;
#define maxn 105 
char map[maxn][maxn];
int m, n; 
int next[8][2] = {{0,1},{1,0},{0,-1},{-1,0},{-1,1},{1,-1},{1,1},{-1,-1}};//右下左上 45度方向 
void dfs(int x, int y) {
	int i, tx, ty;
	for (i = 0; i < 8; i++) {//周围八种方向 
		tx = x + next[i][0];//下一步坐标 
		ty = y + next[i][1];
		if (tx<0 || tx>=m || ty<0 || ty>=n)//是否越界 
			continue;
		if (map[tx][ty] == '@') {
			map[tx][ty] = '*';
			dfs(tx, ty);
		}
	}
	return;
}
int main() {
	int i, j, cnt;
	while (scanf("%d%d", &m, &n), m+n) {
		for (i = 0; i < m; i++) scanf("%s", map[i]);
		cnt = 0;
		for (i = 0; i < m; i++)
			for (j = 0; j < n; j++) 
				if (map[i][j] == '@') {
					map[i][j] = '*';//标记走过的油地 
					dfs(i, j);
					cnt++;
				}
		printf("%d\n", cnt);
	}
	return 0;
}