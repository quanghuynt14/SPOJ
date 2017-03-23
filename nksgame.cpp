#include <bits/stdc++.h>

using namespace std;

int n;
int b, c;

int main()
{
    int min1 = INT_MAX, min2 = INT_MAX, max1 = INT_MIN, max2 = INT_MIN;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &b);
        max1 = max(max1, b);
        min1 = min(min1, b);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &c);
        max2 = max(max2, c);
        min2 = min(min2, c);
    }

    printf("%I64d", (long long)min(min(min(abs(max1+min2),abs(max1+max2)),abs(min1+min2)),abs(min1+max2)));
    return 0;
}
