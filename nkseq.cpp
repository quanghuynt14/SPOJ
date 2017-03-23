#include <bits/stdc++.h>

using namespace std;

#define TASK "a"
#define input_file TASK".inp"
#define output_file TASK".out"

long n, sum, res, a[100100], f[100100];

int main()
{

//    #ifndef ONLINE_JUDGE
//    freopen(input_file, "r", stdin);
//    freopen(output_file, "w", stdout);
//    #endif
    scanf("%li", &n);
    f[n+1] = 100000*10000 + 1;
    for (long i = 1; i <= n; i++) {
        scanf("%li", &a[i]);
        sum += a[i];
        f[n+1] = min(f[n+1],sum);
    }
    if (sum <= 0) {
        printf("0");
        return 0;
    }
    if (f[n+1] > 0) res++;
    for (long i = n; i >= 2; i--) {
        f[i] = min(f[i+1]+a[i],a[i]);
        res += (f[i] > 0);
    }
    printf("%li", res);
    return 0;
}
