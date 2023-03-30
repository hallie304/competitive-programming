#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int N = 1e6 + 5;
 
int luckiness(int x) {
    string s = to_string(x);
    sort(s.begin(), s.end());
    return s.back() - s.front();
}
 
signed main() {
    int t; 
    cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        int max_luckiness = -1;
        int res;
        for (int x = l; x <= r; x++) {
            int x_luckiness = luckiness(x);
            if (x_luckiness > max_luckiness) {
                max_luckiness = x_luckiness;
                res = x;
            }
            if (max_luckiness == 9) break;
        }
        cout << res << '\n';
    }
    return 0;
}