#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 1e6;
int n, k;
int a[N], minValPre[N], maxValPre[N], minValSuf[N], maxValSuf[N], preSum[N];
double variationRange() {
    minValPre[1] = a[1], maxValPre[1] = a[1];
    for (int i = 2; i <= n; i++) {
        minValPre[i] = min(minValPre[i - 1], a[i]);
        maxValPre[i] = max(maxValPre[i - 1], a[i]);
    }
    
    minValSuf[n] = a[n], maxValSuf[n] = a[n];
    for (int i = n - 1; i >= 1; i--) {
        minValSuf[i] = min(minValSuf[i + 1], a[i]);
        maxValSuf[i] = max(maxValSuf[i + 1], a[i]);
    }
    
    preSum[1] = a[1];
    for (int i = 1; i <= n; i++) {
        preSum[i] = preSum[i-1] + a[i];
    }

    
    double ans = 1e6;
    double currMin, currMax;
    maxValPre[0] = maxValSuf[n+1] = -1e6;
    minValPre[0] = minValSuf[n+1] = 1e6;
    for (int i = 1; i <= n - k + 1; i++) {
        currMax = max((double) max((double)maxValPre[i - 1], (double)maxValSuf[i + k]), (double) (preSum[i + k - 1] - preSum[i - 1])/k);
        currMin = min((double) min((double)minValPre[i - 1], (double)minValSuf[i + k]), (double) (preSum[i + k - 1] - preSum[i - 1])/k);
        ans = min(ans, currMax-currMin);
    }
    return ans;
}


int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << fixed << variationRange() << endl;
    return 0;
}
