#include <iostream>
#include <vector>
using namespace std;
 
const int MAX_N = 200005;
 
int main() {
    int n, k, q;
    cin >> n >> k >> q;
 
    vector<int> intervals(MAX_N);
 
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        intervals[l]++;
        intervals[r + 1]--;
    }
 
    int count = 0;
    vector<int> isCovered(MAX_N);
    for (int i = 0; i < MAX_N; i++) {
        count += intervals[i];
        if (count >= k) {
            isCovered[i] = 1;
        }
    }
 
 
    vector<int> prefixSum(MAX_N);
    prefixSum[0] = isCovered[0];
    for (int i = 1; i < MAX_N; i++) {
        prefixSum[i] = prefixSum[i - 1] + isCovered[i];
    }
 
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int coveredPoints = prefixSum[r] - prefixSum[l - 1];
        cout << coveredPoints << endl;
    }
 
    return 0;
}
