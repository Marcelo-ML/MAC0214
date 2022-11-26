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
	int n, h, _h; cin >> n >> _h;
	vector<int> a;
	for(int i = 0; i < n; i++){ int x; cin >> x; a.pb(x); }
	sort(a.begin(), a.end());
	int g = 2, b = 1;
	int i;
	// 3 casos
	// CASO 1: GGB
	h = _h;
	for(i = 0; i < n; i++){
		if(h > a[i]){
			h += (a[i]/2);
			continue;
		}
		if(g > 0){
			g--; h*= 2; i--; continue;
		}
		if(b > 0){
			b--; h*= 3; i--; continue;
		}
		break;
	}
	int cand = i;

	g = 2, b = 1;
	// CASO 2: GBG
	h = _h;
	for(i = 0; i < n; i++){
		if(h > a[i]){
			h += (a[i]/2);
			continue;
		}
		if(g == 2 || (b == 0 && g == 1) ){
			g--; h*= 2; i--; continue;
		}
		if(b > 0){
			b--; h*= 3; i--; continue;
		}
		break;
	}
	cand = max(cand, i);

	g = 2, b = 1;
	// CASO 3: BGG
	h = _h;
	for(i = 0; i < n; i++){
		if(h > a[i]){
			h += (a[i]/2);
			continue;
		}
		if(g > 0 && b == 0){
			g--; h*= 2; i--; continue;
		}
		if(b > 0){
			b--; h*= 3; i--; continue;
		}
		break;
	}
	cand = max(cand, i);

	cout << cand << endl;
}
 
signed main(){
	fastio();
	int t; cin >> t; while(t--) solve();
}


