#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

struct piii
{
    int X, Y, Z;
};

int n, bit[200001], res;
piii a[200001];

bool cmp(piii a, piii b)
{
    return (a.X == b.X) ? ((a.Y == b.Y) ? (a.Z < b.Z) : (a.Y < b.Y)) : (a.X < b.X);
}

int get(int x)
{
    int res = INF;
    while (x > 0) {
        res = min(res, bit[x]);
        x -= (x & -x);
    }
    return res;
}

void update(int x, int y)
{
    while (x <= n) {
        bit[x] = min(bit[x], y);
        x += (x & -x);
    }
}

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d", &n);
    int k;
    for (int i = 1; i <= n; i++) {scanf("%d", &k); a[k].X = i; }
    for (int i = 1; i <= n; i++) {scanf("%d", &k); a[k].Y = i; }
    for (int i = 1; i <= n; i++) {scanf("%d", &k); a[k].Z = i; }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) bit[i] = INF;
    for (int i = 1; i <= n; i++) {
        int minz = get(a[i].Z);
        if (minz > a[i].Y) res++;
        update(a[i].Z, a[i].Y);
    }
    printf("%d", res);
    return 0;
}
