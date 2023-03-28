#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1e9 + 7, MAXN = 1e4 + 5;
int n, A[MAXN], F[MAXN];
 
int pow(int a, int x){
    if (x == 0) return 1;
    int temp = pow(a, x/2);
    if (x % 2 == 0) return 1LL * temp * temp % MOD;
    else return 1LL * temp * temp % MOD * a % MOD;
}
 
int main() {
    int x, y; cin >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    y /= x;
    for(int i = 1; i * i <= y; ++i) {
        if(y % i == 0) A[++n] = i;
    }
    n = (n << 1) - (A[n] * A[n] == y);
    for(int i = 1, j = n; i < j;) {
        A[j--] = y / A[i++];
    }
    for(int i = 1; i <= n; ++i) {
        F[i] = pow(2, A[i] - 1);
    }
    for(int i = 2; i <= n; ++i) {
        for(int j = 1; j < i; ++j) {
            if(A[i] % A[j] == 0) F[i] = (F[i] - F[j] + MOD) % MOD;
        }
    }
    for(int i = 1; i <= n; ++i) {
        if(A[i] == y) cout << F[i];
    }
    return 0;
}
 
