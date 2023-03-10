
#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t; 
 
    while (t--) {
        int n, k, l, r;
        bool found_l = false, found_r = false;
 
        cin >> n >> k; 
 
        for (int i = 0; i < n; i++) {
            cin >> l >> r; 
 
            if (l == k) {
                found_l = true; 
            }
            if (r == k) {
                found_r = true; 
            }
        }
 
        if (found_l && found_r) {
            cout << "YES" << endl; 
        } else {
            cout << "NO" << endl;
        }
    }
 
    return 0;
}
