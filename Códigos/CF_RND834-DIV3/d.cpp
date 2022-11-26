#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define ll long long
// #define endl '\n'
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define pii pair<int,int>
#define int long long
 
int val(int p, int n){
	if(n%p) return 0;
	return 1+val(p,n/p);
}

void solve(){
	int n, m;
	cin >> n >> m;
	int v2 = val(2, n), v5 = val(5, n);
	if(v2 < v5){
		int k = 1;
		while(2*k <= m && v2<v5) {k *= 2; v2++;}
		while(10*k <= m) { k *= 10; }
		int j = k;
		while(j+k <= m) j+=k;
		cout << j*n << endl;
		return;
	}
		int k = 1;
		while(5*k <= m && v5<v2) {k *= 5; v5++;}
		while(10*k <= m) { k *= 10; }
		int j = k;
		while(j+k <= m) j+=k;
		cout << j*n << endl;
		return;


}
 
signed main(){
	fastio();
	int t; cin >> t; while(t--) solve();
}


