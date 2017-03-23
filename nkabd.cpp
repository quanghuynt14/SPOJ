#include <bits/stdc++.h>
using namespace std;

int l, r, a[10000001], res;

void eratos(int x)
{
    for (int i = 1; i < x; i++) {
        int j = 2*i;
        while (j <= x) {
            a[j] += i;
            j += i;
        }
    }
}

int main()
{
    //freopen("a.inp", "r", stdin);
    eratos(10000001);
    scanf("%d %d", &l, &r);
    res = 0;
    for (int i = l; i <= r; i++)
        if (a[i] > i) res++;
    printf("%d", res);
    return 0;
}
