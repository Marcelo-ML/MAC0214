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
	char letras[3] = {'Y', 'e', 's'};
	string s; cin >> s;
	for(int i = 0; i < s.size(); i++){
			char ch = s[i];
			if(ch != 'Y' && ch != 'e' && ch != 's'){
				cout << "NO" << endl;
				return;
			}
			if(i == 0)
				continue;
			if((s[i] == 'Y' && s[i-1] != 's') || (s[i] == 'e' && s[i-1] != 'Y') || (s[i] == 's' && s[i-1] != 'e')){
				cout << "NO" << endl;
				return;
			}
	}
	cout << "YES" << endl;

}
 
signed main(){
	fastio();
	int t; cin >> t; while(t--) solve();
}


