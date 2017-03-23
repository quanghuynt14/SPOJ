#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, k;
ll res, a[1001][1001], f[1001][1001];

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            scanf("%lld", &a[i][j]);
            f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + a[i][j];
        }
    for (int i = k; i <= n; i++)
        for (int j = k; j <= n; j++)
            res = max(res, f[i][j] - f[i-k][j] - f[i][j-k] + f[i-k][j-k]);
    printf("%lld", res);

}
