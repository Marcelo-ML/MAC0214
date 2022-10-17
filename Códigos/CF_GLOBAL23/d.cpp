#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fs first
#define sc second
#define int long long

const int MAXN = 200010;
int n, k;
vector<int> filhos[MAXN];
int score[MAXN];
map<int,int> DP[MAXN];

int dfs(int v, int P){
    if(DP[v].find(P) != DP[v].end())
        return DP[v][P];
    if(filhos[v].empty()){ // v é folha
        DP[v][P] = P*score[v];
        return P*score[v];
    }
    int bruto = P / filhos[v].size();
    int sobra = P % filhos[v].size();
    vector<pair<int,int>> ganhos;
    map<int,int> dfs_com_sobra;
    map<int,int> dfs_sem_sobra;
    if(!sobra){
        int resp = P*score[v];
        for(auto u : filhos[v])
            resp += dfs(u,bruto);
        DP[v][P] = resp;
        return resp;
    }
    for(auto u : filhos[v]){
        dfs_com_sobra[u] = dfs(u,bruto+1);
        dfs_sem_sobra[u] = dfs(u,bruto);
        ganhos.pb({dfs_com_sobra[u]-dfs_sem_sobra[u],u});
    }
    sort(ganhos.begin(),ganhos.end());
    reverse(ganhos.begin(), ganhos.end());
    int resp = P*score[v];
    for(int i = 0; i < filhos[v].size(); i++){
        if(i < sobra)
            resp += dfs_com_sobra[ganhos[i].sc];
        else
            resp += dfs_sem_sobra[ganhos[i].sc];
    }
    // cout << v << ", " <<  P << ": " << resp << endl;
    DP[v][P] = resp;
    return resp;
}



void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        filhos[i].clear();
        DP[i].clear();
    }
    for(int i = 2; i <= n; i++){
        int x; cin >> x; filhos[x].pb(i);
    }
    for(int i = 1; i <= n; i++){
        cin >> score[i];
    }
    cout << dfs(1, k) << endl;
}

signed main(){
    int t; cin >> t;
    while(t--)
        solve();
}
