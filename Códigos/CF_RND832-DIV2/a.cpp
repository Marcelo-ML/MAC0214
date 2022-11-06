#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
	int n; cin >> n;
	int somap = 0, soman = 0;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		if(x > 0)
			somap += x;
		else
			soman -= x;
	}
	if(somap > soman)
		swap(somap, soman);
	cout << soman - somap << endl;
}

signed main(){
	int t; cin >> t;
	while(t--) solve();
}

