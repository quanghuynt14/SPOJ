#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair <int, int> pii;
typedef vector <pii> vii;

vii *G1;
vii *G2;
vector <int> D1;
vector <int> D2;
int T, n, m, k, s, t;

void Dijkstra1(int s)
{
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    D1.assign(n + 1, INF);
    D1[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        pii q = pq.top(); pq.pop();
        int u = q.second;
        if (D1[u] != q.first) continue;
        //if (u == f) return;
        for (int i = 0; i < G1[u].size(); i++) {
            int v = G1[u][i].first;
            int w = G1[u][i].second;
            if (D1[v] > D1[u] + w) {
                D1[v] = D1[u] + w;
                pq.push({D1[v], v});
            }
        }
    }
}

void Dijkstra2(int s)
{
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    D2.assign(n + 1, INF);
    D2[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        pii q = pq.top(); pq.pop();
        int u = q.second;
        if (D2[u] != q.first) continue;
        //if (u == f) return;
        for (int i = 0; i < G2[u].size(); i++) {
            int v = G2[u][i].first;
            int w = G2[u][i].second;
            if (D2[v] > D2[u] + w) {
                D2[v] = D2[u] + w;
                pq.push({D2[v], v});
            }
        }
    }
}

int main()
{
    freopen("path.inp", "r", stdin);
    scanf("%d", &T);
    for (int iT = 0; iT < T; iT++) {
        scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
        G1 = new vii[n + 1];
        G2 = new vii[n + 1];
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            G1[u].push_back({v, w});
            G2[v].push_back({u, w});
        }
        Dijkstra1(s);
        Dijkstra2(t);
        int res = D1[t];
        for (int i = 0; i < k; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            res = min(res, D1[u] + D2[v] + w);
            res = min(res, D1[v] + D2[u] + w);
        }
        if (res != INF) printf("%d\n", res);
        else printf("-1\n");
    }
}
