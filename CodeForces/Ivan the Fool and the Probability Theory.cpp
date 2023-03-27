#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 5;
int dp[N];
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }
    int ans = (2 * (dp[n] + dp[m] - 1)) % MOD;
    cout << ans;
    return 0;
}
