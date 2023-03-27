#include<bits/stdc++.h>
using namespace std;
const int Mod = 1e9 + 7, Max_N = 1e5 + 5;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
 
    for (char a : s){
        if (a == 'm' || a == 'w'){
            cout << 0;
            return 0;
        }
    }
    
    vector<int> dp(Max_N);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1];
        if (s[i - 1] == s[i - 2] && (s[i - 1] == 'u' || s[i - 1] == 'n')){
            dp[i] = (dp[i] + dp[i - 2]) % Mod;
        }
    }
    cout << dp[n];
    return 0;
}
