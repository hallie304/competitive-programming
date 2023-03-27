#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10, Mod = 1e9 + 7;
int dp[N], sum[N];
int main() {
    int t, k;
	while (cin >> t >> k) {
		dp[0] = 1;
		sum[0] = 1;
		for (int i = 1; i < N; i++) {
			dp[i] = dp[i-1];
			if (i >= k) {
				dp[i] = (dp[i] + dp[i-k]) % Mod;
			}
			sum[i] = (sum[i-1] + dp[i]) % Mod;
		}
		while (t--) {
			int l, r;
			cin >> l >> r;
			cout << (sum[r] - sum[l-1] + Mod) % Mod << '\n';
		}
	}
	return 0;
}
