#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define ll long long
// #define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pii pair<int,int>
#define int long long
 
void solve(){
	int n; cin >> n;
	vector<int> b(n/2), a(n/2);
	for(int i = 0; i < n/2; i++) cin >> b[i];
	
	set<int> tqp;
	for(int i = 1; i <= n; i++) tqp.insert(-i);
	for(auto x : b) tqp.erase(-x);

	if(tqp.size() != n/2) {cout << -1 << endl; return; }
	for(int i = n/2 - 1; i >= 0; i--){
		// escolher o maior cara que eu ainda tenho que por e menor que b[i]
		auto it = tqp.upper_bound(-b[i]);
		if(it == tqp.end()){
			cout << -1 << endl; return;
		}
		a[i] = -(*it);
		tqp.erase(*it);

	}
	for(int i = 0; i < n/2; i++)
		cout << a[i] << ' ' << b[i] << ' ';
	cout << endl;
}
 
signed main(){
	fastio();
	int t; cin >> t; while(t--) solve();
}


