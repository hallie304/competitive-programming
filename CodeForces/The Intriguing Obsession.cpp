#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 998244353, N = 1e5 + 5;
int FACT[N];
 
int modPow(int a, int x) {
    if (x == 0) return 1;
    if (x == 1) return a;
    int temp = modPow(a, x/2);
    if (x % 2 == 0) return temp * temp % MOD;
    else return (temp * temp % MOD) * a % MOD;
}
 
int inv(int x) {
    return modPow(x, MOD - 2);
}
 
int choose(int n, int k) {
    return FACT[n] * inv((FACT[k] * FACT[n-k]) % MOD) % MOD;
}
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    FACT[0] = 1;
    for (int i = 1; i <= N; i++) {
        FACT[i] = (FACT[i-1] * i) % MOD;
    }
    int a, b, c, ans_1 = 0, ans_2 = 0, ans_3 = 0;
    cin >> a >> b >> c;
    for (int i = 0; i <= min(a, b); i++) {
        ans_1 = (ans_1 + ((choose(a, i) * choose(b, i) % MOD) * FACT[i] % MOD)) % MOD;
    } 
    for (int i = 0; i <= min(a, c); i++) {
        ans_2 = (ans_2 + ((choose(a, i) * choose(c, i) % MOD) * FACT[i] % MOD)) % MOD;
    }
    for (int i = 0; i <= min(b, c); i++) {
        ans_3 = (ans_3 + ((choose(b, i) * choose(c, i) % MOD) * FACT[i] % MOD)) % MOD;
    }
    cout << ((ans_1 * ans_2 % MOD) * ans_3) % MOD;
}
