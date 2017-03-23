#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair <int, int> pii;
typedef pair <int, pii> piii;
typedef vector <pii> vii;

vii *G;
int Dist[10001][21];
int n, m, k;

void dijkstra(int s, int f)
{
    priority_queue <piii, vector <piii>, greater <piii> > pq;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) Dist[i][j] = INF;
    for (int i = 0; i <= k; i++) Dist[s][i] = 0;
    pq.push({Dist[s][0], {s, 0}});
    while (!pq.empty()) {
        piii q = pq.top();
        pq.pop();
        int u = q.second.first;
        int x = q.second.second;
        if (u == f) return;
        if (Dist[u][x] != q.first) continue;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if (x < k) {
                if (Dist[v][x + 1] > Dist[u][x]) {
                Dist[v][x + 1] = Dist[u][x];
                pq.push({Dist[v][x + 1], {v, x + 1}});
                }
            }
            if (Dist[v][x] > Dist[u][x] + w) {
                Dist[v][x] = Dist[u][x] + w;
                pq.push({Dist[v][x], {v, x}});
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    G = new vii[n + 1];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    dijkstra(1, n);
    printf("%d", Dist[n][k]);
    return 0;
}
