#include <bits/stdc++.h>
using namespace std;

int n, a[60001], s[60001], res;

int sum(int x)
{
    int res = 0;
    while (x > 0) {
        res += s[x];
        x -= (x&-x);
    }
    return res;
}

void update(int x, int v)
{
    while (x <= 60001) {
        s[x] += v;
        x += (x&-x);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i > 0; i--) {
        res += sum(a[i] - 1);
        update(a[i], 1);
    }
    printf("%d", res);
    return 0;
}
