#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

typedef pair <int, int> pii;
typedef vector <pii> vii;

vii *G;
vector <int> Dist1;
vector <int> Dist2;
vector <int> F1;
vector <int> F2;
vector <int> h;
int n, m, minDist, res;

void Dijkstra1(int s)
{
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    Dist1.assign(n + 1, INF);
    F1.assign(n + 1, 0);
    Dist1[s] = 0; F1[s] = 1;
    pq.push({0, s});
    while (!pq.empty()) {
        pii q = pq.top(); pq.pop();
        int u = q.second;
        if (Dist1[u] != q.first) continue;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if (Dist1[v] > Dist1[u] + w) {
                Dist1[v] = Dist1[u] + w;
                F1[v] = F1[u];
                pq.push({Dist1[v], v});
            }
            else if (Dist1[v] == Dist1[u] + w) F1[v] += F1[u];
        }
    }
}

void Dijkstra2(int s)
{
    priority_queue <pii, vector <pii>, greater <pii> > pq;
    Dist2.assign(n + 1, INF);
    F2.assign(n + 1, 0);
    Dist2[s] = 0; F2[s] = 1;
    pq.push({0, s});
    while (!pq.empty()) {
        pii q = pq.top(); pq.pop();
        int u = q.second;
        if (Dist2[u] != q.first) continue;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].first;
            int w = G[u][i].second;
            if (Dist2[v] > Dist2[u] + w) {
                Dist2[v] = Dist2[u] + w;
                F2[v] = F2[u];
                pq.push({Dist2[v], v});
            }
            else if (Dist2[v] == Dist2[u] + w) F2[v] += F2[u];
        }
    }
}

int main()
{
    freopen("path.inp", "r", stdin);
    scanf("%d %d", &n, &m);
    G = new vii[n + 1];
    for (int i = 0; i < m; i++) {
        int x, y, d;
        scanf("%d %d %d", &x, &y, &d);
        G[x].push_back({y, d});
        G[y].push_back({x, d});
    }
    /*
    Dijkstra(1, n);
    minDist = Dist[n];
    L.assign(n + 1, INF);
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < G[i].size(); j++) {
            L[j] = G[i][j].second;
            G[i][j].second = INF;
        }
        Dijkstra(1, n);
        if (Dist[n] == minDist) { res++; h.push_back(i); }
        for (int j = 0; j < G[i].size(); j++)
            G[i][j].second = L[j];
    }
    printf("%d\n", res);
    for (int i = 0; i < h.size(); i++) printf("%d\n", h[i]);
    */
    Dijkstra1(1);
    Dijkstra2(n);
    for (int i = 1; i <= n; i++)
        if (Dist1[i] + Dist2[i] > Dist1[n] || (Dist1[i] + Dist2[i] == Dist1[n] && F1[i] * F2[i] < F1[n])) {
            //printf("%d %d %d %d %d %d\n", Dist1[i], Dist2[i], Dist1[n], F1[i], F2[i], F1[n]);
            h.push_back(i);
        }
    printf("%d\n", h.size());
    for (int i = 0; i < h.size(); i++) printf("%d\n", h[i]);
    return 0;
}
