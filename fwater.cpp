#include <bits/stdc++.h>
using namespace std;

int n, G[310][310], res;

int minKey(int key[], bool mstSet[])
{
    int nmin = INT_MAX,  min_index;
    for (int i = 0; i <= n; i++)
        if (mstSet[i] == false && key[i] < nmin) {
            nmin = key[i];
            min_index = i;
        }
    return min_index;
}

void primMST(int G[310][310])
{
    int parent[310];
    int key[310];
    bool mstSet[310];
    for (int i = 0; i <= n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i <= n - 1; i++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int v = 0; v <= n; v++)
            if (G[u][v] && mstSet[v] == false && G[u][v] < key[v]) {
                parent[v] = u;
                key[v] = G[u][v];
            }
    }
    for (int i = 0; i <= n; i++) res += G[i][parent[i]];
    printf("%d", res);
}

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int u;
        scanf("%d", &u);
        G[0][i] = u;
        G[i][0] = u;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) scanf("%d", &G[i][j]);
    primMST(G);
    return 0;
}
