#include <bits/stdc++.h>
using namespace std;

int n, k, f[100002];
bool fre[100002];

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        fre[x] = 1;
    }
    if (!fre[n]) f[n] = 1;
    for (int i = n - 1; i > 0; i--)
        if (!fre[i])
            f[i] = (f[i+1] + f[i+2]) % 14062008;
    printf("%d", f[1]);
    return 0;
}
