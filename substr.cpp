#include <bits/stdc++.h>
using namespace std;

#define BASE 1000000007
typedef long long ll;

string a, b;
ll A[1010101], B[1010101], M[1010101];

void hash_build(string x, ll H[1010101])
{
    for (int i = 0; i < x.size(); i++) {
        H[i+1] = (H[i] * M[1] + x[i]) % BASE;
    }
}

ll hash_range(ll H[1010101], int l, int r)
{
    return (H[r] - H[l-1]*M[r-l+1] + 1LL*BASE*BASE) % BASE;
}

int main()
{
    freopen("a.inp", "r", stdin);
    getline(cin, a);
    getline(cin, b);
    int n = a.size(), m = b.size();
    M[0] = 1; M[1] = 2309;
    for (int i = 2; i <= 1010101; i++)
        M[i] = (M[i-1] * M[1]) % BASE;
    hash_build(a, A);
    hash_build(b, B);
    for (int i = 1; i <= n-m+1; i++)
        if (hash_range(A, i, i+m-1) == B[m]) printf("%d ", i);
    return 0;
}
