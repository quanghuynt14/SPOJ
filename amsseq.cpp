#include <bits/stdc++.h>
using namespace std;

int n, k, A[10101], F[10101], m;

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        if (i-k < 1) {
            int x = 0;
            for (int j = 1; j <= i; j++) x = max(x, F[j] + A[i]);
            F[i] = x;
        } else {
            int x = 0;
            for (int j = i-k; j <= i; j++) x = max(x, F[j] + A[i]);
            F[i] = x;
        }
    if (F[n] < 0) printf(0);
    else printf("%d", F[n]);
    return 0;
}
