#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7, N = 1e5 + 5;
 
int modPow(int a, int x){
    if (x == 0) return 1;
    if (x == 1) return a;
    int temp = modPow(a, x/2);
    if (x%2 == 0) return temp * temp % MOD;
    else return (a * temp % MOD) * temp % MOD;
}
 
signed main(){
    string a;
    int k;
    cin >> a >> k;
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        a[i] = a[i] - '0';
        if (a[i] == 0 || a[i] == 5) ans = ans + modPow(2,i);
    }
    ans %= MOD;
    if (k == 1) cout << ans;
    else cout << ans * (modPow(2, n * k) - 1) % MOD * modPow((modPow(2,n) - 1), MOD - 2) % MOD;
    return 0;
}
