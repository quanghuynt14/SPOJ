#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll t, n, a[100001], s[100001], f[100001], ma;

int main()
{
    //freopen("a.inp", "r", stdin);
    scanf("%lld", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%lld", &a[i]);
        ma = max(ma, a[i]);
    }
    s[0] = 0; s[1] = 1;
    for (int i = 1; i <= ma/2; i++) { s[i*2] = s[i]; s[i*2+1] = s[i] + s[i+1]; }
    f[1] = 1;
    for (int i = 2; i <= ma; i++) f[i] = max(f[i- 1], s[i]);
    for (int i = 1; i <= t; i++) printf("%d\n", f[a[i]]);
    return 0;
}
