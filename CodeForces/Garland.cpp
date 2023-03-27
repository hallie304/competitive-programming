#include <bits/stdc++.h>
#define int long long
using namespace std;
 
signed main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        
        if (s[0] == s[3]) cout << -1 << "\n";
        else if (s[0] == s[2] || s[1] == s[3]) cout << 6 << "\n";
        else cout << 4 << "\n";
    }
    return 0;
}
