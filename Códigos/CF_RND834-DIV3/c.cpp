#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define ll long long
// #define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pii pair<int,int>
#define int long long

// int abs(int x){ return x>=0 ? x : -x; }

void solve(){
	int l, r, x;
	int a, b;
	cin >> l >> r >> x >> a >> b;
	if(a == b){ cout << 0 << endl; return; }
	if(abs(a-b) >= x){ cout << 1 << endl; return; }
	if( (abs(a-l) < x && abs(a-r) < x) || (abs(b-l) < x && abs (b-r) < x) ){cout << -1 << endl; return; }
	if( (abs(a-l) >= x && abs(b-l) >= x) || (abs(a-r) >= x && abs(b-r) >= x) ){cout << 2 << endl; return; }
	cout << 3 << endl;
}
 
signed main(){
	fastio();
	int t; cin >> t; while(t--) solve();
}


