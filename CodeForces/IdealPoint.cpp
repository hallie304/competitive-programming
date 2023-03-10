#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> count(51, 0);
        bool is_ideal = true;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            int l, r;
            cin >> l >> r;
            if (l == r && l == k) {
                temp += 1;
            }
            for (int j = l; j <= r; j++) {
                count[j]++;
            } 
        }
        int max_count = *max_element(count.begin(), count.end());

        if (temp != 0 && count[k] != 0){
            cout << "YES\n" << endl;
            break;
        }
        if (max_count == 1 || max_count == min_count) {
            is_ideal = false;
        }
        for (int i = 1; i <= 50; i++) {
            if (count[i] == max_count) {
                if (i != k && n == max_count) {
                    is_ideal = false;
                } else if (i == k & n == max_count) {
                    is_ideal = false;
                }
            }
        }
        if (is_ideal) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}

    
