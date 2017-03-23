#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair <int, int> pii;
int tx[4] = {1, 0, -1, 0};
int ty[4] = {0, -1, 0, 1};
int r, c, x, y;
char a[101][101];
int d[101][101];

void bfs(int x, int y)
{
    queue <pii> qu;
    for (int i = 0; i <= r; i++)
        for (int j = 0; j <= c; j++) d[i][j] = INF;
    qu.push({x, y});
    d[x][y] = 0;
    while(!qu.empty()) {
        pii q = qu.front(); qu.pop();
        int u = q.first;
        int v = q.second;
        if (u == 1 && v == 1) {printf("%d", d[u][v]); return;}
        for (int i = 0; i < 4; i++) {
            int u1 = u + tx[i];
            int v1 = v + ty[i];
            if (u1 > 0 && v1 > 0 && u1 <= r && v1 <= c && a[u1][v1] != '*' && d[u1][v1] == INF) {
                    d[u1][v1] = d[u][v] + 1;
                    qu.push({u1, v1});
            }
        }
    }
}
int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d\n", &r, &c);
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%c", &a[i][j]);
            if (a[i][j] == 'C') {x = i; y = j;}
        }
        scanf("\n");
    }
    bfs(x, y);
    return 0;
}
