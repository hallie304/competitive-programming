#include <iostream>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d, ans;
        cin >> a >> b >> c >> d;
 
        if(d >= b && d - b >= c - a){
            ans = d - b + (a + d - b) - c;
            cout << ans << '\n';
        }
        else cout << -1 << '\n';
    }
}
