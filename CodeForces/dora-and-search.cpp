
#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        int n;
        cin >> n;
 
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
 
        int l = 1, r = n, L = 1, R = n;
        bool foundRange = false;
 
        while (l < r && !foundRange) {
            foundRange = true;
 
            if (a[l] == L) {
                l++, L++;
            } else if (a[l] == R) {
                l++, R--;
            } else if (a[r] == L) {
                r--, L++;
            } else if (a[r] == R) {
                r--, R--;
            } else {
                foundRange = false;
            }
        }
 
        if (foundRange) {
            cout << l << " " << r << endl;
        } else {
            cout << -1 << endl;
        }
    }
 
    return 0;
}
