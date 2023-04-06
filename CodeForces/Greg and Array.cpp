#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n, m, k;
int a[N], l[N], r[N], d[N], x[N], y[N], cnt[N], res[N];

signed main(){
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        res[i] = a[i] - a[i-1];
    }
    for (int i = 1; i <= m; i++) cin>>l[i]>>r[i]>>d[i];

    for (int i = 1; i <= k; i++){
        cin >> x[i] >> y[i];
        cnt[x[i]]++; 
        cnt[y[i]+1]--; 
    }
    
    for (int i = 1; i <= m; i++){
        cnt[i] += cnt[i-1]; 
        res[l[i]] += cnt[i] * d[i]; 
        res[r[i]+1] -= cnt[i] * d[i]; 
    }
    
    for (int i = 1; i <= n; i++){
        res[i] += res[i-1]; 
        cout << res[i] << ' '; 
    }
    return 0;
}