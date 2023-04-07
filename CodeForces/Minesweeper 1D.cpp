#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7, N = 1e6 + 5;
int dp[N][3];

signed main(){
    string s; cin >> s;
    dp[0][0] = dp[0][1] = 1;
    int n = s.size();

    s = " " + s;
    for (int i = 1; i <= n; i++){
        if (s[i] == '0') dp[i][0] = dp[i-1][0]; // can only extend the prefix if the (i-1)th cell was a type-0 cell
        if (s[i] == '1') { 
            dp[i][1] = dp[i-1][0]; // the cell to the left contains a bomb
            dp[i][0] = dp[i-1][2]; // the cell to the left does not contain a bomb
        }
        if(s[i] == '2') dp[i][1] = dp[i-1][2]; // can only extend the prefix if the last cell was a type-2 cell.
        if(s[i] == '*') dp[i][2] = (dp[i-1][1] + dp[i-1][2]) % MOD; // can fill the i-th cell with a bomb if wither thr (i-1)th cell contain '1' 
        if(s[i] == '?') {
            dp[i][0] = (dp[i-1][0] + dp[i-1][2])%MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
            dp[i][2] = (dp[i-1][1] + dp[i-1][2])%MOD;
        }
    }
    cout << (dp[n][0] + dp[n][1]) % MOD;
}