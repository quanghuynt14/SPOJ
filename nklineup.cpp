#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
int n, q, A[50101], ITmin[201010], ITmax[201010], resmin, resmax;

void update(int k, int l, int r, int i, int p)
{
    if (l > i || r < i) return;
    if (l == r) {
        ITmin[k] = p;
        ITmax[k] = p;
        return;
    }
    int mid = (l + r) / 2;
    update(k*2, l, mid, i, p);
    update(k*2+1, mid+1, r, i, p);
    ITmin[k] = min(ITmin[k*2], ITmin[k*2+1]);
    ITmax[k] = max(ITmax[k*2], ITmax[k*2+1]);
}

void get(int k, int l, int r, int u, int v)
{
    if (l > v || r < u) return;
    if (l >= u && r <= v) {
        resmin = min(resmin, ITmin[k]);
        resmax = max(resmax, ITmax[k]);
        return;
    }
    int mid = (l + r) / 2;
    get(k*2, l, mid, u, v);
    get(k*2+1, mid+1, r, u, v);
}

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &A[i]);
        update(1, 1, n, i, A[i]);
    }
    for (int i = 1; i <= q; i++) {
        int u, v;
        resmin = INF; resmax = 0;
        scanf("%d %d", &u, &v);
        get(1, 1, n, u, v);
        printf("%d\n", resmax-resmin);
    }
    return 0;
}
