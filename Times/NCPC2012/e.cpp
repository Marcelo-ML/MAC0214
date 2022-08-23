#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

#define pp pair<long long, long long>
#define ld double
#define f first
#define s second

ld dot(pp a, pp b){
	return a.f * b.f + a.s * b.s;
}
ld dist(pp a, pp b){
	ld dx = (a.f - b.f), dy = (a.s - b.s);
	return sqrt((ld) (dx * dx + dy * dy) );
}
ld dist(pp a){
	return sqrt((ld) (a.f * a.f + a.s * a.s) );
}

ld get_angle(pp p1, pp p2, pp p3){
	pp a = {p3.f - p2.f, p3.s - p2.s};
	pp b = {p2.f - p1.f, p2.s - p1.s};
	return acos(dot(a, b) / (dist(a) * dist(b)));
}

const int MAXN = 201;

ld d[MAXN][MAXN];
ld dp[MAXN][MAXN];
ld ang[MAXN][MAXN][MAXN];
pp pt[MAXN];
vector<int> adj[MAXN];

const ld INF = 1e18;
const ld eps = 1e-9;

int n, R;

int ja_foi[MAXN][MAXN];

ld X;
ld solve(int a, int b){
	if(dp[a][b] < INF + eps) return dp[a][b];
	if(ja_foi[a][b]) return INF;

	if(b == n) return 0;

	ja_foi[a][b] = true;
	for(int c : adj[b]){
		if(ang[a][b][c] <= X){
			//cout << a << " " << b << " " << c << endl;
			//cout << get_angle(pt[a], pt[b], pt[c]) << endl;
			dp[a][b] = min(dp[a][b], solve(b, c) + d[b][c]);
		}
	}

	return dp[a][b];
}

ld run(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			dp[i][j] = INF, ja_foi[i][j] = 0;

	ld ans = INF;
	for(int i : adj[1]){
		ans = min(solve(1, i) + dist(pt[1], pt[i]), ans);
	}

	return ans;		
}

ld D;
ld bb(){
	ld l = 0.0, r = 8.0;

	for(int i = 0; i < 100; i++){
		X = (l + r) / 2;
		if(run() <= D) r = X;
		else l = X; 
	}
	return l;
}

int main(){
	cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
	cin >> n >> R >> D;

	for(int i = 1; i <= n; i++) 
		cin >> pt[i].f >> pt[i].s;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			d[i][j] = dist(pt[i], pt[j]);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int k = 1; k <= n; k++)
				ang[i][j][k] = get_angle(pt[i], pt[j], pt[k]);


	for(int i = 0; i < R; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);	
	}

	cout << setprecision(10) << fixed;

	ld ans = bb();
	if(ans > 7.0) cout << "Impossible" << endl;
	else cout << 180 * ans / acos(-1) << endl;
}
