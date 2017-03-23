#include <bits/stdc++.h>
using namespace std;

typedef vector <int> BigInt;
int t, n, T[111];
BigInt F[111];

void Set(BigInt &a)
{
    while (a.size() && !a.back()) a.pop_back();
}

void Set1(BigInt &a, BigInt &b)
{
    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
}

BigInt Plus(BigInt a, BigInt b)
{
    BigInt ans;
    int carry = 0;
    Set1(a, b);
    for (int i = 0; i < a.size(); i++) {
        carry += a[i] + b[i];
        ans.push_back(carry % 10);
        carry /= 10;
    }
    if (carry) ans.push_back(carry);
    return ans;
}

void Printf(BigInt a)
{
    Set(a);
    for (int i = a.size() - 1; i >= 0; i--) printf("%d", a[i]);
    printf("\n");
}

int main()
{
    freopen("a.inp", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &T[i]);
        n = max(n, T[i]);
    }
    F[1].push_back(1);
    F[2].push_back(2);
    for (int i = 3; i <= n; i++)
        F[i] = Plus(F[i-1], F[i-2]);
    for (int i = 0; i < t; i++) Printf(F[T[i]]);
    return 0;
}
