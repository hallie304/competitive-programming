#include <iostream>
#include <map>
using namespace std;
long long ans = 0;
map <int,int> count_map;
int n, m ,count, num;
bool contain_m;
int main(){
	count_map[0] = 1;
	contain_m = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> num;
		if (num == m)
		    contain_m = true;
		else if (num < m) 
		    count--;
		else if (num > m) 
		    count++;
		if (!contain_m) 
		    count_map[count]++; 
		if (contain_m) 
		    ans += count_map[count] + count_map[count - 1];
	}
	cout << ans << endl;
}
