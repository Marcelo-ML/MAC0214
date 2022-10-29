#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long

void solve(){
	int q; cin >> q;
	set<int> s;
	map<int,int> ans;
	for(int i = 0; i < q; i++){
		char ch; cin >> ch;
		if(ch == '+'){
			int x; cin >> x;
			s.insert(x);
		}
		else{
			int k; cin >> k;
			if(ans.find(k) != ans.end()){
				while(s.find(ans[k]) != s.end()) {ans[k] +=k;}
				cout << ans[k] << endl;
				continue;
			}
			int j = 1;
			while(s.find(k*j) != s.end()) j++;
			ans[k] = k*j;
			cout << ans[k] << endl;
		}
	}
}

signed main(){
	solve();
}


