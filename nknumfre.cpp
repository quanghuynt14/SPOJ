#include <bits/stdc++.h>
using namespace std;

int a, b, res;

inline int gcd(int a, int b)
{
    return (b == 0 ? a : gcd(b, a % b));
}


int daonguoc(int x)
{
    int y;
    y = x % 10;
    x = x / 10;
    while (x > 0) {
        y = y * 10 + (x % 10);
        x = x / 10;
    }
    return y;
}

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
        if (gcd(i, daonguoc(i)) == 1) res++;
    printf("%d", res);
}
