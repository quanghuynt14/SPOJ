#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int n, m, K, A[111][111], P[111][111];
vector <int> p;

void Find(int u, int v)
{
    if (!P[u][v]) {
        p.push_back(v);
        return;
    }
    Find(u, P[u][v]);
    Find(P[u][v], v);

}

int main()
{
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d %d %d", &n, &m, &K);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j) A[i][j] = 0;
            else A[i][j] = INF;
            P[i][j] = 0;
        }
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        A[u][v] = c;
        A[v][u] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    P[i][j] = k;
                    P[j][i] = k;
                }
            }
    for (int i = 1; i <= K; i++) {
        int c, u, v;
        scanf("%d %d %d", &c, &u, &v);
        if (!c) printf("%d\n", A[u][v]);
        if (c) {
            p.clear();
            p.push_back(u);
            Find(u, v);
            printf("%d ", p.size());
            for (int ii = 0; ii < p.size(); ii++) printf("%d ", p[ii]);
            printf("\n");
        }

    }

    return 0;
}

