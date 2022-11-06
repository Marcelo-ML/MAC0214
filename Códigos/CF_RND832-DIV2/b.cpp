#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n; cin >> n;
	cout << (n+1)/2 << endl;
	for(int i = 0; i < n/2; i++){
		cout << 3*i + 2 << ' ' << 3*(n-i) << endl;
	}
	if(n&1){
		int x = (n+1)/2;
		cout << 3*x -1 << ' ' << 3*x << endl;
	}
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}

