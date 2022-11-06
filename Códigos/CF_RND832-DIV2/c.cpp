#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n; cin >> n;
	int prim; cin >> prim;
	bool flag = 0;
	for(int i = 0; i < n-1; i++){
		int x; cin >> x;
		if(x < prim)
			flag = 1;
	}
	if(flag)
		cout << "Alice" << endl;
	else
		cout << "Bob" << endl;
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}

