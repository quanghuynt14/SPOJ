#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f

int n, a[30001], s[30001], res;

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    s[0] = -INF;
    s[1] = a[1]; res = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] < s[1]) s[1] = a[i];
        else
        if (a[i] > s[res]) {res++; s[res] = a[i]; }
        else {
            int l = 1, r = res;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (a[i] > s[mid]) l = mid;
                else r = mid - 1;
            }
            if (a[i] > s[l] && a[i] < s[l + 1])
                s[l + 1] = a[i];
        }
        for (int j = 1; j <= res; j++) printf("%d ", s[j]); printf("\n");
    }
    printf("%d", res);
    return 0;
}
