#include <bits/stdc++.h>

using namespace std;

int a,b;

bool isPrime(int n)
{
    if (n == 1) return false;
    for (int i = 2; i <= sqrtl(n); i++)
        if (n%i == 0) return false;
    return true;
}

int main()
{
    scanf("%d%d",&a,&b);
    for (int i = a; i<=b; i++)
        if (isPrime(i)) printf("%d\n",i);
    return 0;
}
