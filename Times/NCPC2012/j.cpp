#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

const int N = 1e3 + 10;

int n, r[N], C[N], p[N];
vector<int> adj[N];

bool check (int x, int flow) {
	if(x == 0) return true;
	if(flow <= C[x]) return check(p[x], flow);
	return false;
}

void solve () {
	vector< pair<int, int> > op;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i] >> r[i] >> C[i];
		adj[p[i]].pb(i);
		op.pb(mp(r[i], i));
	}

	sort(op.begin(), op.end());

	int ans = 0;
	for (auto [flow, x] : op) {
		if(check(x, flow)) {
			ans++;
			while(x) {
				C[x] -= flow;
				x = p[x];
			}
		}
	}
	cout << ans << "\n";
}

signed main (){
	 solve();
}
