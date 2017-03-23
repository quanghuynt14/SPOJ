#include <bits/stdc++.h>
using namespace std;

int p, x, y, z, a[10001];

int Find(int x)
{
    return (a[x] == x ? x : a[x] = Find(a[x]));
}

void Unite(int x, int y)
{
    a[Find(x)] = Find(y);
}

int main()
{
    //freopen("input.inp", "r", stdin);
    for (int i = 0; i <= 10000; i++) a[i] = i;
    scanf("%d", &p);
    for (int i = 0; i < p; i++) {
        scanf("%d %d %d", &x, &y, &z);
        if (z == 1) Unite(x, y);
        else {
            printf("%d\n", Find(x) == Find(y));
        }
    }
    return 0;
}
