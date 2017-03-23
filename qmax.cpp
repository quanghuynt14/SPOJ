#include <bits/stdc++.h>

using namespace std;

int n, m, q, A[50101], IT[201010], res;

void update(int k, int l, int r, int i, int p)
{
    if (l > i || r < i) return;
    if (l == r) {IT[k] = p; return; }
    int mid = (l + r) / 2;
    update(k*2, l, mid, i, p);
    update(k*2+1, mid+1, r, i, p);
    IT[k] = max(IT[k*2], IT[k*2+1]);
}

void get(int k, int l, int r, int u, int v)
{
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        res = max(res, IT[k]);
        return;
    }
    int mid = (l + r) / 2;
    get(k*2, l, mid, u, v);
    get(k*2+1, mid+1, r, u, v);
}

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, k;
        scanf("%d %d %d", &u, &v, &k);
        A[u] += k;
        A[v+1] -= k;
    }
    for (int i = 1; i <= n; i++) {
        A[i] += A[i-1];
        update(1, 1, n, i, A[i]);
    }
    scanf("%d", &q);
    while (q--) {
        int u, v;
        scanf("%d %d", &u, &v);
        res = 0;
        get(1, 1, n, u, v);
        printf("%d\n", res);
    }
    return 0;
}
