#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
#define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 200010;

void solve(){
	int n; cin >> n;
	vector<int> a(n);
	int num[2];
	num[0] = 0;
	num[1] = 0;
	for(int i = 0; i < n; i++){
		char ch; cin >> ch;
		a[i] = ch-'0';
		num[a[i]]++;
	}
	int maxi[2];
	maxi[0] = 0;
	maxi[1] = 0;
	int cur[2];
	cur[0] = 0;
	cur[1] = 0;
	for(int i = 0; i < n; i++){
		if(!i){
			if(!a[i]){
				cur[0] = 1;
				maxi[0] = 1;
			}
			else{
				cur[1] = 1;
				maxi[1] = 1;
			}
			continue;
		}
		if(a[i] == a[i-1]){
			cur[a[i]]++;
			maxi[a[i]]=max(maxi[a[i]],cur[a[i]]);
		}
		else{
			cur[a[i]] = 1;
			maxi[a[i]]=max(maxi[a[i]],cur[a[i]]);
			cur[1-a[i]] = 0;
		}
	}
	cout << max(max(maxi[0]*maxi[0],maxi[1]*maxi[1]),num[0]*num[1]) << endl;

}

signed main(){_
	int t; cin >> t;
	while(t--) solve();
}

