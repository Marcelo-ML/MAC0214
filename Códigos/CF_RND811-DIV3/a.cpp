#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, H, M; cin >> n >> H >> M;
	int h[20], m[20];
	int tempos[20];
	for(int i = 0; i < n; i++){
		cin >> h[i] >> m[i];
		tempos[i] = (m[i]+60*h[i])%(24*60);
	}
	int atual = (M+60*H)%(24*60);
	int mini = 24*60*80;
	for(int i = 0; i < n; i++){
		int cur = (tempos[i] - atual +24*60*5) % (24*60);
		mini = min(cur,mini);
	}
	cout << mini/60 << ' ' << mini%60 << endl;
}

int main(){
	int t; cin >> t;
	while(t--) solve();
}

