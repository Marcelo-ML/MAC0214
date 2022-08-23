#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;

vector<int> adj[MAXN];
int n, h, l;
int sim[MAXN];

int main(){
	cin >> n >> h >> l;
	for(int i = 0; i < n; i++) sim[i] = MAXN;

	queue<int> fila;

	for(int i = 0; i < h; i++){
		int x; cin >> x;
		sim[x] = 0;
		fila.push(x);
	}

	for(int i = 0; i < l; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	while(fila.size() > 0){
		int cur = fila.front();
		fila.pop();

		for(auto x : adj[cur]){
			if(sim[x] == MAXN){
				sim[x] = sim[cur] + 1;
				fila.push(x);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(sim[ans] < sim[i]) ans = i;
	}

	cout << ans << endl;
}
