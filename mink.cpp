#include <bits/stdc++.h>
using namespace std;

int T, n, k, A[17101], M[17101];
deque <int> P;

int main()
{
    freopen("a.inp", "r", stdin);
    scanf("%d", &T);
    for (int it = 0; it < T; it++) {
        P.clear();
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &A[i]);
            while (P.size() && A[i] < A[P.back()]) P.pop_back();
            P.push_back(i);
            while (i-k+1 > P.front()) P.pop_front();
            if (i-k+1 > 0) printf("%d ", A[P.front()]);
        }
        printf("\n");
    }
    return 0;
}
