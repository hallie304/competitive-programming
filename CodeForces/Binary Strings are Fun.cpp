#include <bits/stdc++.h>
// #define int unsigned int
// #define it int
using namespace std;
const unsigned int MOD = 998244353, N = 2e5 + 5;
int dp[N];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    unsigned int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> s;
        unsigned int ans = 1, temp = 1;
        for (unsigned int i = 1; i < n; i++) {
            if (s[i] == s[i-1]) temp *= 2;
            else temp = 1;
            temp %= MOD;
            ans += temp;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}
