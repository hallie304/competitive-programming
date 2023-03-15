#include <iostream>
#include <vector>
using namespace std;
int t, n, a[200005], l, r, L, R;
int main() {
    cin >> t;
 
    while (t--) {
        cin >> n;
 
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
 
        int l = L = 1, r = R = n;
 
        while ((a[l] == L || a[l] == R || a[r] == L || a[r] == R) && l <= r) {
 
            if (a[l] == L) {
                l++, L++;
            } else if (a[l] == R) {
                l++, R--;
            } else if (a[r] == L) {
                r--, L++;
            } else if (a[r] == R) {
                r--, R--;
            }
        }
 
        if (l >= r) {
            cout << -1 << endl;
        } else {
            cout << l << " " << r << endl;
        }
    }
}
 
