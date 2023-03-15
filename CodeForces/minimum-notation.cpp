#include <iostream>
#include <string>
#include <algorithm>
#include <conio.h>
using namespace std;
int t, n, l, r, minSorted;
string s;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> s;
        n = s.size();
        int a[n];
        for (int i = 0; i <= n - 1; i++) {
            a[i] = s[i] - '0';
        }
        minSorted = a[n-1];
        for (int i = n-2; i >= 0; i--) {
            if (a[i] > minSorted) {
                a[i] = min((a[i] + 1), 9);
            } else minSorted = a[i];
        }
        
        sort(a, a + n); 
        for (int i = 0; i <= n - 1; i++) {
            cout << a[i];
        }
        cout << '\n';
    }
}
