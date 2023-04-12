

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9+7, N = 1e6+5;
int dp[N][5];

signed main(){
    string s;
    cin >> s;
    if (s[0]=='0') dp[0][0]=1;
    else if (s[0]=='1') dp[0][1]=1;
    else if (s[0]=='*') dp[0][3]=1;
    else if (s[0]=='?') dp[0][0]=dp[0][1]=dp[0][3]=1;
    int n = s.length();
    for (int i=1; i < n; i++){
        if (s[i]=='0') dp[i][0] = (dp[i-1][0]+dp[i-1][2])%MOD;
        else if (s[i]=='1'){
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
            dp[i][2] = dp[i-1][3];
        }
        else if (s[i]=='2') dp[i][4]=dp[i-1][3];
        else if (s[i]=='*') dp[i][3]=(dp[i-1][1]+dp[i-1][4]+dp[i-1][3])%MOD;
        else if (s[i]=='?'){
            dp[i][0] = (dp[i-1][0]+dp[i-1][2])%MOD;
            dp[i][1] = (dp[i-1][0] + dp[i-1][2])%MOD;
            dp[i][2] = dp[i-1][3];
            dp[i][3] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][4])%MOD;
            dp[i][4] = dp[i-1][3];
        }
    }
    cout<<(dp[n-1][0]+dp[n-1][2]+dp[n-1][3])%MOD;
}
