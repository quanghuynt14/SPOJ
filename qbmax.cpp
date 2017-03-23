#include <bits/stdc++.h>

using namespace std;

int m, n, kq;
int a[101][101], f[101][101];
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (int j = 0; j <= n+1; j++)
    {
        f[0][j] = INT_MIN;
        f[m+1][j] = INT_MIN;
    }
    for (int i = 1; i <= m; i++)
        f[i][1] = a[i][1];

    for (int j = 2; j <= n; j++)
        for (int i = 1; i <= m; i++)
            f[i][j] = max(f[i-1][j-1],max(f[i][j-1],f[i+1][j-1])) + a[i][j];
    kq = INT_MIN;
    for (int i = 1; i <= m; i++)
        kq = max(kq,f[i][n]);
    printf("%d", kq);

    return 0;
}
