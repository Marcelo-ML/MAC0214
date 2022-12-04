#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#define ll long long
#define int long long
#define pii pair<int,int>
#define fs first
#define sc second
#define pb push_back
// #define endl '\n'

const int MOD = 1e9+7;
const int MAXN = 200010;

int n;
vector<int> adj[MAXN];

void solve(){
int n; cin >> n;
vector<bool> vis(n, false);

for(int i = 0; i < n; i++)
    adj[i] = {};
bool no = false;
int apar[n];
for(int i = 0; i < n; i++)
    apar[i] = 0;
for(int i = 0; i < n; i++){
    int u, v; cin >> u >> v;
    adj[u-1].pb(v-1);
    apar[u-1]++;
    if(apar[u-1] > 2)
        no = true;
    apar[v-1]++;
    if(apar[v-1] > 2)
        no = true;
    adj[v-1].pb(u-1);
    if(u == v)
        no = true;
}
if(no){
    cout << "NO" << endl;
    return;
}

for(int i = 0; i < n; i++){
    if(vis[i]) continue;
    vis[i] = true;
    int tam_ciclo = 0;
    int j = adj[i][0];
    while(j != i){
        vis[j] = true;
        for(auto k : adj[j])
            if(!vis[k]) {j = k; goto prox_iteracao;}
        break;
        prox_iteracao:
        tam_ciclo++;
    }
    if(tam_ciclo&1){
        cout << "NO" << endl;
        return;
    }
}

cout << "YES" << endl;
}
signed main(){_
    int t; cin >> t; while(t--)
	solve();
}

