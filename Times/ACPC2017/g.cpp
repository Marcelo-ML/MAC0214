#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define all(v) v.begin(), v.end()
#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second

#define pb push_back
#define pq priority_queue<int,vector<int>,less<int>>

const int INF = 10000000000000;

int mmc(int a, int b){
	__int128 x = (__int128)a*(__int128)b/(__int128)__gcd(a,b);
	if(x > INF)
		return -1;
	else
		return x;
}

void solve(){
	int n; cin >> n;
	vector<int> a;
	vector<int> psum (n);
	for(int i = 0; i < n; i++){
		int x; cin >> x; a.pb(x);
	}
	partial_sum(all(a), psum.begin());

	int result = 0;
	for(int i = 0; i < n; i++){
		int MMC = 1;
		for(int j = i; j < n; j++){
			MMC = mmc(MMC, a[j]);
			if(MMC == -1)
				break;
			if( (psum[j] - (i ? psum[i-1] : 0)) % MMC == 0)
				result++;
		}
	}

	cout << result << endl;
}

signed main(){_
	int t; cin >> t;
	while(t--) solve();
}
