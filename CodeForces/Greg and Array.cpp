#include <bits/stdc++.h>
#define int long long
const int N = 1e5+5;

using namespace std;

int n, m, k;
int a[N], c[N], l[N], r[N], d[N], x[N], y[N], cnt[N];

signed main(){
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        c[i] = a[i] - a[i-1];
    }
    for (int i = 1; i <= m; i++) cin>>l[i]>>r[i]>>d[i];

    for (int i = 1; i <= k; i++){
        cin >> x[i] >> y[i];
        cnt[x[i]]++; 
        cnt[y[i]+1]--; 
    }
    
    for (int i = 1; i <= m; i++){
        cnt[i] += cnt[i-1]; 
        c[l[i]] += cnt[i] * d[i]; 
        c[r[i]+1] -= cnt[i] * d[i]; 
    }
    
    for (int i = 1; i <= n; i++){
        c[i] += c[i-1]; 
        cout << c[i] << ' '; 
    }
    return 0;
}