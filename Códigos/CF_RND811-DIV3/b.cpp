#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

void solve(){
	int n; cin >> n;
	vector<int> a;
	for(int i = 0; i < n; i++){
		int x; cin >> x; a.pb(x);
	}

	set<int> nums;
	for(int i = n-1; i >= 0; i--){
		if(nums.find(a[i]) != nums.end()){
			cout << i+1 << endl;
			return;
		}
		nums.insert(a[i]);
	}
	cout << 0 << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}

