#include <bits/stdc++.h>

using namespace std;

#define input_file "mmass.in"
#define output_file "mmass.out"

int res;
string s;
stack <int> a;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen(input_file, "r", stdin);
    freopen(output_file, "w", stdout);
    #endif // ONLINE_JUDGE
    getline(cin, s);
    for (int i = 0 ; i < s.size(); i++) {
        if (s[i] == 'C') a.push(12);
        if (s[i] == 'H') a.push(1);
        if (s[i] == 'O') a.push(16);
        if (s[i] == '(') a.push(0);
        if (s[i] == ')') {
            int k = 0;
            while (!a.empty() && a.top() != 0) {k += a.top(); a.pop();}
            a.pop();
            a.push(k);
        }
        if (s[i] >= '2' && s[i] <= '9') a.top() *= (s[i] - '0');
    }
    res = 0;
    while (!a.empty()) {
        res += a.top();
        a.pop();
    }
    printf("%d", res);
    return 0;
}
