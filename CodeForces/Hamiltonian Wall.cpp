#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int dp[2][N];
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        string s1, s2;
        cin >> s1 >> s2;
        dp[0][0] = dp[1][0] = 1;
	    for (int i = 1; i <= m; i++) dp[0][i] = dp[1][i] = 0;
	    for (int i = 1; i <= m; i++) {
	        if (s1[i-1] == 'B' && s2[i-1] == 'B'){
    			dp[0][i] = dp[1][i-1];
    			dp[1][i] = dp[0][i-1];
		    } else if (s1[i-1] == 'B') dp[0][i] = dp[0][i-1];
		    else dp[1][i] = dp[1][i-1];
	    }
	    if (dp[0][m]||dp[1][m]) cout << "YES\n";
	    else cout << "NO\n";
    }
}
